#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    auto img = imread("lena.png", 1);
    for (auto i = 0; i < 1000; ++i) {
        auto x = rand() % img.cols;
        auto y = rand() % img.rows;
        for (auto j = 0; j < 3; ++j) {
            img.at<Vec3b>(y, x)[j] = 0;
        }
        x = rand() % img.cols;
        y = rand() % img.rows;
        for(auto j = 0; j < 3; ++j) {
            img.at<Vec3b>(y, x)[j] = 255;
        }
    }
    Mat dst_img;
    //Canny(img, dst_img, 50, 200);
    //GaussianBlur(img, dst_img, Size(15, 15), 10, 10);
    //medianBlur(img, dst_img, 3);
    //bilateralFilter(img, dst_img, -1, 50, 20);
    boxFilter(img, dst_img, img.type(), Size(2,10), Point(-1,-1), true);
    //cvtColor(img, dst_img, CV_RGB2GRAY);
    //threshold(dst_img, dst_img, 0, 255, THRESH_TOZERO | THRESH_OTSU);
    //dst_img = ~img;
    //Mat canny_img;
    //Canny(img, canny_img, 50, 200);
    //imwrite("building_canny.png", canny_img);
    //std::vector<Vec4i> lines;
    //HoughLinesP(canny_img, lines, 1, CV_PI / 180, 50, 50, 10);
    //
    //auto it = lines.begin();
    //for(; it != lines.end(); ++it) {
    //    auto l = *it;
    //    line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, CV_AA);
    //}
    imwrite("lena_box.png", dst_img);
}
