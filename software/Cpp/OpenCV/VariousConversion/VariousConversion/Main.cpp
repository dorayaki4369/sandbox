#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

enum PROCESSIONG {
    NONE = 0,
    GRAY,
    NEGA_POSI,
    BINARIZATION,
    GAUSSIAN,
    MEDIAN,
    BILATERAL,
    BOX,
    EDGE
};

PROCESSIONG operator ++(PROCESSIONG& value) {
    value = value == EDGE ? NONE : PROCESSIONG(value + 1);
    return value;
}

auto angle = 0;
void PinP_point(const Mat& srcImg, const Mat& smallImg, const Point2f p0, const Point2f p1);

int main() {
    VideoCapture cap(1);
    if (!cap.isOpened()) {
        std::cout << "can not open camera device." << std::endl;
        return -1;
    }

    auto process = NONE;

    Mat frame;
    cap >> frame;
    Mat grayFrame;
    Mat dst_frame;
    cap >> dst_frame;
    Mat background = Mat::zeros(frame.rows, frame.cols + 300, CV_8UC3);
    putText(background, "1.Default", Point(frame.cols, 40), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "2.Gray", Point(frame.cols, 80), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "3.Nega Posi", Point(frame.cols, 120), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "4.Binarization", Point(frame.cols, 160), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "5.Gaussian", Point(frame.cols, 200), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "6.Median", Point(frame.cols, 240), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "7.Bilateral", Point(frame.cols, 280), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "8.Box", Point(frame.cols, 320), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "9.Edge", Point(frame.cols, 360), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "r.Rotation", Point(frame.cols, 400), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);

    while (true) {
        cap >> frame;
        cvtColor(frame, grayFrame, CV_RGB2GRAY);

        auto key = waitKey(1);
        switch (key) {
            case 'q':
                goto FINISH;

            case ' ':
                ++process;
                break;

            case 'r':
                angle = angle == 270 ? 0 : angle + 90;
                break;

            case '1':
                process = NONE;
                break;

            case '2':
                process = GRAY;
                break;

            case '3':
                process = NEGA_POSI;
                break;

            case '4':
                process = BINARIZATION;
                break;

            case '5':
                process = GAUSSIAN;
                break;

            case '6':
                process = MEDIAN;
                break;

            case '7':
                process = BILATERAL;
                break;

            case '8':
                process = BOX;
                break;

            case '9':
                process = EDGE;
                break;

            default:
                break;
        }

        //どのように画像を処理するか決める
        switch (process) {
            case GRAY:
                dst_frame = grayFrame;
                break;

            case NEGA_POSI:
                dst_frame = ~frame;
                break;

            case BINARIZATION:
                threshold(grayFrame, dst_frame, 0, 255, THRESH_TOZERO | THRESH_OTSU);
                break;

            case GAUSSIAN:
                GaussianBlur(frame, dst_frame, Size(51, 3), 80, 3);
                break;

            case MEDIAN:
                medianBlur(frame, dst_frame, 51);
                break;

            case BILATERAL:
                bilateralFilter(frame, dst_frame, 20, 90, 40);
                break;

            case BOX:
                boxFilter(frame, dst_frame, frame.type(), Size(2, 2), Point(-1, -1), false);
                break;

            case EDGE:
                Canny(grayFrame, dst_frame, 50, 200);
                break;

            case NONE:
                cap >> dst_frame;
                break;
        }

        //回転
        Point2f center(dst_frame.cols * 0.5, dst_frame.rows * 0.5);
        auto affine_matrix = getRotationMatrix2D(center, angle, 1.0);
        warpAffine(dst_frame, dst_frame, affine_matrix, dst_frame.size());

        //座標指定
        Point2f p0(0, 0);
        Point2f p1(dst_frame.cols, dst_frame.rows);
        PinP_point(background, dst_frame, p0, p1);
    }

FINISH:
    destroyAllWindows();
    return 0;
}

void PinP_point(const Mat& srcImg, const Mat& smallImg, const Point2f p0, const Point2f p1) {
    //背景画像の作成
    Mat dstImg;
    srcImg.copyTo(dstImg);

    //3組の対応点を作成
    std::vector<Point2f> src, dst;
    src.push_back(Point2f(0, 0));
    src.push_back(Point2f(smallImg.cols, 0));
    src.push_back(Point2f(smallImg.cols, smallImg.rows));

    dst.push_back(p0);
    dst.push_back(Point2f(p1.x, p0.y));
    dst.push_back(p1);

    //前景画像の変形行列
    auto mat = getAffineTransform(src, dst);

    //アフィン変換の実行
    warpAffine(smallImg, dstImg, mat, dstImg.size(), CV_INTER_LINEAR, BORDER_TRANSPARENT);
    imshow("Monitor", dstImg);
}
