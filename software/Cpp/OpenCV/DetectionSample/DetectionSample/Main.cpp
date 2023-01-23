#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/opencv.hpp>

using namespace cv;

//画像を重ねる関数 はみ出しても可
void PinP_point(const Mat& srcImg, const Mat& smallImg, const Point2f p0, const Point2f p1);

enum PROCESSIONG {
    NONE = 0,
    LINE,
    CIRCLE,
    ELLIPSE,
    FACE,
    EYE,
    PEAPLE,
    FEATURE,
};

PROCESSIONG operator ++(PROCESSIONG& value) {
    value = value == FEATURE ? NONE : PROCESSIONG(value + 1);
    return value;
}

struct data {
    CascadeClassifier faceCascade = CascadeClassifier("haarcascade_frontalface_alt.xml");
    CascadeClassifier eyeCascade = CascadeClassifier("haarcascade_eye.xml");
};

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
    Mat background = Mat::zeros(frame.rows, frame.cols + 300, CV_8UC3);
    putText(background, "1.Default", Point(frame.cols, 50), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "2.Line", Point(frame.cols, 100), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "3.Circle", Point(frame.cols, 150), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "4.Ellipse", Point(frame.cols, 200), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "5.Face", Point(frame.cols, 250), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "6.Eye", Point(frame.cols, 300), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "7.Peaple", Point(frame.cols, 350), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);
    putText(background, "8.Feature", Point(frame.cols, 400), FONT_HERSHEY_SIMPLEX, 1.2, Scalar(0, 200, 0), 2, CV_AA);

    data data = {};

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

            case '1':
                process = NONE;
                break;

            case '2':
                process = LINE;
                break;

            case '3':
                process = CIRCLE;
                break;

            case '4':
                process = ELLIPSE;
                break;

            case '5':
                process = FACE;
                break;

            case '6':
                process = EYE;
                break;

            case '7':
                process = PEAPLE;
                break;

            case '8':
                process = FEATURE;
                break;

            default:
                break;
        }

        //どのように画像を処理するか決める
        if (process == LINE) {
            Canny(grayFrame, grayFrame, 50, 200, 3);
            std::vector<Vec4i> lines;
            HoughLinesP(grayFrame, lines, 1, CV_PI / 180, 50, 50, 10);

            auto it = lines.begin();
            for (; it != lines.end(); ++it) {
                auto l = *it;
                line(frame, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, CV_AA);
            }
        }
        else if (process == CIRCLE) {
            Canny(grayFrame, grayFrame, 50, 200, 3);
            std::vector<Vec3f> circles;
            HoughCircles(grayFrame, circles, CV_HOUGH_GRADIENT, 1, 20, 1, 52, 10, 100);

            auto it = circles.begin();
            for (; it != circles.end(); ++it) {
                Point center(saturate_cast<int>((*it)[0]), saturate_cast<int>((*it)[1]));
                auto radius = saturate_cast<int>((*it)[2]);
                circle(frame, center, radius, Scalar(0, 0, 255), 2);
            }
        }
        else if (process == ELLIPSE) {
            std::vector<std::vector<Point>> contours;
            //二値化
            threshold(grayFrame, grayFrame, 0, 255, THRESH_BINARY | THRESH_OTSU);
            //輪郭の検出
            findContours(grayFrame, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

            for (auto i = 0; i < contours.size(); ++i) {
                auto count = contours[i].size();
                if (count < 150 || count > 1000) continue; // (小さすぎる|大きすぎる)輪郭を除外

                Mat pointsf;
                Mat(contours[i]).convertTo(pointsf, CV_32F);
                // 楕円フィッティング
                auto box = fitEllipse(pointsf);
                // 楕円の描画
                ellipse(frame, box, Scalar(0, 0, 255), 2, CV_AA);
            }
        }
        else if (process == FACE) {
            std::vector<Rect> faces;
            data.faceCascade.detectMultiScale(grayFrame, faces, 1.1, 2, 2);

            std::vector<Rect>::const_iterator it1 = faces.begin();
            for (; it1 != faces.end(); ++it1) {
                rectangle(frame, it1->tl(), it1->br(), Scalar(0, 0, 255), 2, 8, 0);
            }
        }
        else if (process == EYE) {
            std::vector<Rect> faces;
            data.eyeCascade.detectMultiScale(grayFrame, faces, 1.1, 2, 2);

            std::vector<Rect>::const_iterator it1 = faces.begin();
            for (; it1 != faces.end(); ++it1) {
                rectangle(frame, it1->tl(), it1->br(), Scalar(0, 0, 255), 2, 8, 0);
            }
        }
        else if (process == PEAPLE) {
            HOGDescriptor hog;
            hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

            std::vector<Rect> peaples;
            hog.detectMultiScale(frame, peaples, 0.2, Size(8, 8), Size(16, 16), 1.05, 2);

            std::vector<Rect>::const_iterator it = peaples.begin();
            for (; it != peaples.end(); ++it) {
                auto r = *it;
                // 描画に際して,検出矩形を若干小さくする
                r.x += cvRound(r.width * 0.1);
                r.width = cvRound(r.width * 0.8);
                r.y += cvRound(r.height * 0.07);
                r.height = cvRound(r.height * 0.8);
                rectangle(frame, r.tl(), r.br(), Scalar(0, 0, 255), 3);
            }
        }
        else if (process == FEATURE) {
            auto detector = AKAZE::create();

            std::vector<KeyPoint> keyPoints;
            detector->detect(frame, keyPoints);

            drawKeypoints(frame, keyPoints, frame);
        }

        //座標指定
        Point2f p0(0, 0);
        Point2f p1(frame.cols, frame.rows);
        PinP_point(background, frame, p0, p1);
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
