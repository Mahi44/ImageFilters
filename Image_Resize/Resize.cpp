#include<iostream>
#include<opencv2/opencv.hpp>

void imresize(cv::Mat& img) {
	cv::resize(img, img, cv::Size(0, 0), 0.2, 0.2);
}


int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::string img_path = argv[1];
		cv::Mat img = cv::imread(img_path, -1);
		imresize(img);
		cv::imwrite(img_path, img);
	}
	return 0;
}