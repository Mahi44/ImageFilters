#include<iostream>
#include<opencv2/opencv.hpp>

//This filter increases the brightness, decreases the saturation, and adds a slight pinkish tint.
void applyLarkFilter(cv::Mat& image) {
    // Increase brightness
    cv::convertScaleAbs(image, image, 1.2, 0);

    // Decrease saturation
    cv::cvtColor(image, image, cv::COLOR_BGR2HLS);
    cv::multiply(image, cv::Scalar(1, 1, 0.7), image);
    cv::cvtColor(image, image, cv::COLOR_HLS2BGR);

    // Add pinkish tint
    cv::add(image, cv::Scalar(0, 0, 20), image);
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::string img_path = argv[1];
		cv::Mat img = cv::imread(img_path, -1);
        applyLarkFilter(img);
		cv::imwrite("Lark.png", img);
	}
	return 0;
}