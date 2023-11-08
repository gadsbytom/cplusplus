#include "image_processor.h"

cv::Mat ImageProcessor::LoadImage(const std::string& path) {
    return cv::imread(path);
}
