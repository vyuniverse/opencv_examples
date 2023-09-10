#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

int main()
{
    auto image_path = cv::samples::findFile("starry_night.jpg");
    cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);

    if (image.empty())
    {
        std::cerr << "Failed to read image " << image_path << '\n';
        return 1;
    }

    cv::imshow("Starry Night", image);
    cv::waitKey(0);

    return 0;
}

