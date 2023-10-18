#include<iostream>
#include<opencv2/opencv.hpp>

//This filter desaturates the image and adds a vintage look.
void applyGinghamFilter(cv::Mat& image) {
    // desaturates
    cv::cvtColor(image, image, cv::COLOR_BGR2HSV);

	for (int row = 0; row < image.rows; ++row) {
		for (int col = 0; col < image.cols; ++col) {
			cv::Vec3b& pix = image.at<cv::Vec3b>(row, col);
			if (pix[2] > 98) {
				pix[2] = 98;
			}
		}
	}
    cv::cvtColor(image, image, cv::COLOR_HSV2BGR);
    // Add pinkish tint
    cv::add(image, cv::Scalar(0, 0, 20), image);
}


int main(int argc, char* argv[]) {
	if (argc > 1) {
		std::string img_path = argv[1];
		cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
		applyGinghamFilter(img);
		cv::imwrite("Gingham.png", img);
	}
	return 0;
}