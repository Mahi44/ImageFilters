#include<iostream>
#include<opencv2/opencv.hpp>

//clarendon filter increases the contrast and adds a slightly blue tint to the image.
void clarendon_filter(cv::Mat& image) {
	// Increase contrast
	cv::convertScaleAbs(image, image, 1.5, 0);

	// Add blue tint
	cv::add(image, cv::Scalar(20, 20, 0), image);
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::string img_path = argv[1];
		cv::Mat img = cv::imread(img_path, -1);
		clarendon_filter(img);
		cv::imwrite("Clarendon.png", img);
	}
	return 0;
}