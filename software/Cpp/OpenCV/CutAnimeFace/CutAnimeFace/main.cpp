/* アニメから顔を切り取るプログラム
 * 
 * author: ryuya hirayama
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void createVideoFrame(VideoCapture& video, Mat& frame);
void detectAndDisplay(Mat image);

CascadeClassifier face_cascade;

constexpr auto multiVideoDetect = true;//複数の動画を読み込む場合はtrue
constexpr auto videonum = 13;//動画の最大番号

int main(int argc, char* argv[]) {
    //カスケードのロード
    face_cascade.load("lbpcascade_animeface.xml");

    //*************
    //動画読み込み
    //*************
    Mat frame;
    //複数読み込む場合
    if (multiVideoDetect) {
        VideoCapture video[videonum];
        for (auto i = 1; i < videonum; i++) {//動画の数だけループ
            stringstream name;
            name.str("");
            name << "F:\\Videos\\アニメ\\けものフレンズ\\kemono_friends (" << i << ").mp4";

            video[i].open(name.str());
            if (video[i].isOpened()) {
                cout << "Successfully opened " << name.str() << endl << "Processing is started." << endl;

                //画像生成
                createVideoFrame(video[i], frame);
            }

            video[i].release();//ビデオファイルは大きいので即削除
        }
    }
    //動画一つだけの場合
    else {
        VideoCapture video(argv[1]);
        createVideoFrame(video, frame); //画像生成
    }
    cout << "please push enter key" << endl;
    getchar();
    destroyAllWindows();
    return 0;
}

//フレーム切り出し
int framenum = 0;
void createVideoFrame(VideoCapture& video, Mat& frame) {
    cout << "creating face image..." << endl;

    while (true) {
        framenum++;
        video >> frame;
        if (frame.empty()) {
            cout << "End of video" << endl;
            break;
        }
        //全フレーム切りだすと画像数が増え過ぎるので10フレームごとに検出
        if (framenum % 10 == 0) detectAndDisplay(frame);
    }
}

//顔検出・画像作成
int imagenum = 0;
void detectAndDisplay(Mat image) {
    vector<Rect> faces;
    Mat frame_gray;
    stringstream name;
    cvNamedWindow("image", CV_WINDOW_AUTOSIZE);

    //画像のグレースケール化
    cvtColor(image, frame_gray, COLOR_BGR2GRAY);
    //ヒストグラムの平坦化
    equalizeHist(frame_gray, frame_gray);
    //顔の認識 小さい顔は除外
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 0, Size(80, 80));
    for (auto i = 0; i < faces.size(); i++) {
        //顔部分に注目したMatをROIで作る
        auto Face = image(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
        
        //連番のファイル名を作る
        name.str("");
        name << "F:\\KemonoFace\\image" << setw(6) << setfill('0') << imagenum << ".png";
        imwrite(name.str(), Face);
        imagenum++;

        //ついでに顔画像を画面表示
        imshow("image", Face);
        waitKey(1);
    }
}
