#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

std::string OCR(const cv::Mat &img) {
    // Create Tesseract object
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    
    // Initialize Tesseract to use English (eng) and the LSTM OCR engine.
    ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

    // Set Page Segmentation Mode to Auto (can be changed based on your needs)
    ocr->SetPageSegMode(tesseract::PSM_AUTO);

    // Set image data to Tesseract (note that OpenCV images are BGR and Tesseract expects RGB)
    cv::Mat rgbImg;
    cv::cvtColor(img, rgbImg, cv::COLOR_BGR2RGB);
    ocr->SetImage(rgbImg.data, rgbImg.size().width, rgbImg.size().height, 3, rgbImg.step);

    // Run OCR on the image
    std::string outText = std::string(ocr->GetUTF8Text());

    // Destroy used object and release memory
    ocr->End();

    return outText;
}
