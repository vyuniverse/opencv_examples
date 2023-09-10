#include "opencv2/core/utility.hpp"
#include <iostream>

int main(void)
{
    std::cout << cv::getBuildInformation() << '\n';
    return 0;
}

