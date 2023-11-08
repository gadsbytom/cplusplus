#ifndef OCR_TESSERACT_H
#define OCR_TESSERACT_H

#include <opencv2/opencv.hpp>
#include <string>

std::string OCR(const cv::Mat &img);

#endif // OCR_TESSERACT_H
