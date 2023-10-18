#include<iostream>
#include<opencv2/opencv.hpp>

//This filter increases the exposure and adds a bluish tint.
void applyMoonFilter(cv::Mat& image) {
	// Increase exposure
	cv::convertScaleAbs(image, image, 1.2, 0);

	// Add bluish tint
	cv::add(image, cv::Scalar(10, 10, 30), image);
}



int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::string img_path = argv[1];
		cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
		applyMoonFilter(img);
		cv::imwrite("Moon.png", img);
	}
	return 0;
}