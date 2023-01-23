#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "exe [video]" << endl;
		return -1;
	}
	Ptr<Tracker> tracker = Tracker::create("KCF");

	cv::VideoCapture cap(argv[1]);
	if (!cap.isOpened()) {
		cout << "ビデオが開けません" << endl;
		return -1;
	}

	Mat frame;
	cap >> frame;

	//Rect2d roi = selectROI("tracker", frame);
	Rect2d roiTLD = roi;
}