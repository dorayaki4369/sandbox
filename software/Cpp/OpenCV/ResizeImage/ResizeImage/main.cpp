//画像をリサイズするプログラム
//応用すればリネームにも使える

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void resizeImage(int& num);

bool is_image_one = false;
Mat src_image, dst_image;
stringstream src_image_name, dst_image_name;

int main(int argc, char* argv[])
{
	src_image_name.str("");
	dst_image_name.str("");

	if (is_image_one) {
		int num = 31;
		resizeImage(num);
	} else {
		for (int num = 30; num <= 37000;) {
			resizeImage(num);
		}
	}
	destroyAllWindows();
	return 0;
}

void resizeImage(int& num) {
	src_image_name << "E:\\cocoa\\image" << setw(3) << setfill('0') << num << ".png";
	dst_image_name << "E:\\cocoa_p\\cocoa" << setw(5) << setfill('0') << num << ".png";

	src_image = imread(src_image_name.str());
	if (src_image.empty()) {
		cout << "image" << setw(3) << setfill('0') << num << "failed!" << endl;
		return;
	}

	resize(src_image, dst_image, Size(), 100.0 / src_image.cols, 100.0 / src_image.rows);
	imwrite(dst_image_name.str(), dst_image);

	cout << "image" << setw(3) << setfill('0') << num << "successful!" << endl;
}