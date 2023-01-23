#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    auto a = 20;
    namedWindow("Monitor", CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);
    createTrackbar("res.", "Monitor", &a, 20);
    while(true){}
    waitKey(0);
    destroyAllWindows();
    return 0;
}
