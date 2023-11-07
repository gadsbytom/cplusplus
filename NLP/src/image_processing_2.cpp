#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

int main(int argc, char** argv)
{
    // Check for command line arguments
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <ImagePath>" << std::endl;
        return -1;
    }

    // Read the image file from the command line argument
    cv::Mat image = cv::imread(argv[1]);

    // Check for failure
    if (image.empty()) 
    {
        std::cerr << "Could not open or find the image: " << argv[1] << std::endl;
        return -1;
    }

    std::cout << "Image loaded successfully!" << std::endl;

    // Process the image with OpenCV (if you want to do any processing)

    // Convert to Pix format which Tesseract expects
    Pix *pix = pixCreate(image.size().width, image.size().height, 8);
    for(int y = 0; y < image.rows; y++) {
        for(int x = 0; x < image.cols; x++) {
            pixSetPixel(pix, x, y, static_cast<l_uint32>(image.at<uchar>(y,x)));
        }
    }

    // Create Tesseract API
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

    // Initialize Tesseract with English language
    if (ocr->Init(NULL, "eng")) {
        std::cerr << "Could not initialize tesseract." << std::endl;
        pixDestroy(&pix);
        return -1;
    }

    // Set the Pix image for Tesseract to analyze
    ocr->SetImage(pix);

    // Perform OCR on the image
    char* outText = ocr->GetUTF8Text();

    std::cout << "OCR output: " << outText << std::endl;

    // Clean up
    delete [] outText;
    ocr->End();
    pixDestroy(&pix);

    // Save or export the image or text (if necessary)

    return 0;
}
