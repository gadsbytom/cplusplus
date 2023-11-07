#include <opencv2/opencv.hpp>
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

    // Process the image (if you want to do any processing)

    // Save or export the image (if necessary)

    return 0;
}
