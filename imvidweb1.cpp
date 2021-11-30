#include "imvidweb1.h"

void images()
{
    int wait = 0; // je�li jest 0 czeka niesko�czono�� a� co� si� wci�nie
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    imshow(path, img);
    waitKey(wait);
}

void videos()
{
    int wait = 10; // czekanie w ms na kolejn� klatk� -> mo�na przyspiesza� lub spowalnia� gotowe video
    string path = "Resources/video.mp4";
    VideoCapture cap(path);

    Mat img;

    while (true)
    {
        cap.read(img);

        imshow("video", img); // pokazuje wideo klatka po klatce
        waitKey(wait);
    }
}

void webcam()
{
    int camerID = 1; // 0 je�eli jest tylko inna kamera, else -> id kamery

    VideoCapture cap(1);

    Mat img;

    while (true)
    {
        cap.read(img);

        imshow("video", img);
        waitKey(1);
    }
}