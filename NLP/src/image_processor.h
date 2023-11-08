#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class ImageProcessor {
public:
    static cv::Mat LoadImage(const std::string& path);
    // Add other processing functions here
};
