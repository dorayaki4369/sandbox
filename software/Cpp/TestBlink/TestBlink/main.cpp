#include <wiringPi.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
#define	LED	17

int main(void) {
    wiringPiSetupSys();

    pinMode(LED, OUTPUT);

    //while (true)
    //{
    //    digitalWrite(LED, HIGH); // On
    //    delay(500); // ms
    //    digitalWrite(LED, LOW); // Off
    //    delay(500);
    //}

    auto capture = VideoCapture(0);

    namedWindow("red", WINDOW_AUTOSIZE);
    imshow("red", Mat(Size(320, 320), CV_8UC3, Scalar(0, 0, 255)));
    waitKey(0);
    destroyAllWindows();

    capture.release();

    return 0;
}

