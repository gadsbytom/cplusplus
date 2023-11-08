#include "image_processor.h"
#include <gtest/gtest.h>

class ImageProcessorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Set up any necessary test fixtures
        // For example, create a sample image file on the disk
    }

    virtual void TearDown() {
        // Clean up any test fixtures if necessary
    }
};

TEST_F(ImageProcessorTest, LoadValidImage) {
    // Here, you would need a valid image file path for testing
    std::string validImagePath = "path/to/sample_image.jpg";
    cv::Mat image = ImageProcessor::LoadImage(validImagePath);
    EXPECT_FALSE(image.empty());
}

bool ImageProcessorTest_LoadValidImage_Test_dummy = ::testing::internal::MakeAndRegisterTestInfo(
    "ImageProcessorTest", "LoadValidImage", /* More parameters might be here to set up the test */);


TEST_F(ImageProcessorTest, LoadInvalidImage) {
    std::string invalidImagePath = "path/to/nonexistent_image.jpg";
    cv::Mat image = ImageProcessor::LoadImage(invalidImagePath);
    EXPECT_TRUE(image.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int x = 10;


