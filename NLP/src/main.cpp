#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include "image_processor.h"
#include "ocr_tesseract.h"

int main(int argc, char** argv) {
    // Check for command line arguments
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <ImagePath>" << std::endl;
        return -1;
    }

    // Read the image file from the command line argument
    cv::Mat image = ImageProcessor::LoadImage(argv[1]);

    // Check for failure
    if (image.empty()) {
        std::cerr << "Could not open or find the image: " << argv[1] << std::endl;
        return -1;
    }

      // Perform OCR on the image
    std::string text =  OCR(image);

    // Print the extracted text
    std::cout << "Extracted Text:\n" << text << std::endl;

    // Process the image (if you want to do any processing)

    // Save or export the image (if necessary)

    return 0;
}
