/* �A�j��������؂���v���O����
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

constexpr auto multiVideoDetect = true;//�����̓����ǂݍ��ޏꍇ��true
constexpr auto videonum = 13;//����̍ő�ԍ�

int main(int argc, char* argv[]) {
    //�J�X�P�[�h�̃��[�h
    face_cascade.load("lbpcascade_animeface.xml");

    //*************
    //����ǂݍ���
    //*************
    Mat frame;
    //�����ǂݍ��ޏꍇ
    if (multiVideoDetect) {
        VideoCapture video[videonum];
        for (auto i = 1; i < videonum; i++) {//����̐��������[�v
            stringstream name;
            name.str("");
            name << "F:\\Videos\\�A�j��\\�����̃t�����Y\\kemono_friends (" << i << ").mp4";

            video[i].open(name.str());
            if (video[i].isOpened()) {
                cout << "Successfully opened " << name.str() << endl << "Processing is started." << endl;

                //�摜����
                createVideoFrame(video[i], frame);
            }

            video[i].release();//�r�f�I�t�@�C���͑傫���̂ő��폜
        }
    }
    //���������̏ꍇ
    else {
        VideoCapture video(argv[1]);
        createVideoFrame(video, frame); //�摜����
    }
    cout << "please push enter key" << endl;
    getchar();
    destroyAllWindows();
    return 0;
}

//�t���[���؂�o��
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
        //�S�t���[���؂肾���Ɖ摜���������߂���̂�10�t���[�����ƂɌ��o
        if (framenum % 10 == 0) detectAndDisplay(frame);
    }
}

//�猟�o�E�摜�쐬
int imagenum = 0;
void detectAndDisplay(Mat image) {
    vector<Rect> faces;
    Mat frame_gray;
    stringstream name;
    cvNamedWindow("image", CV_WINDOW_AUTOSIZE);

    //�摜�̃O���[�X�P�[����
    cvtColor(image, frame_gray, COLOR_BGR2GRAY);
    //�q�X�g�O�����̕��R��
    equalizeHist(frame_gray, frame_gray);
    //��̔F�� ��������͏��O
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 0, Size(80, 80));
    for (auto i = 0; i < faces.size(); i++) {
        //�畔���ɒ��ڂ���Mat��ROI�ō��
        auto Face = image(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height));
        
        //�A�Ԃ̃t�@�C���������
        name.str("");
        name << "F:\\KemonoFace\\image" << setw(6) << setfill('0') << imagenum << ".png";
        imwrite(name.str(), Face);
        imagenum++;

        //���łɊ�摜����ʕ\��
        imshow("image", Face);
        waitKey(1);
    }
}
