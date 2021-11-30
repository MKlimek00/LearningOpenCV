#include "drawwrite4.h"

void blankimg()
{
    Mat img(512, 512, CV_8UC3, Scalar(200, 0, 200)); // scalar() nadaje kolor w BGR

    imshow("Blank", img);

    waitKey(0);
}

void drawShape()
{
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

    // point -> �rodek okr�gu, promie�, kolor okr�gu, grubo�� linii/ FILLED je�li chemy wype�ni� obszar
    circle(img, Point(256, 256), 150, Scalar(200, 0, 200), FILLED);
    rectangle(img, Rect(50, 100, 50, 100), Scalar(100, 100, 100), 10);// zamiast Rect(), mo�na da� Point(), Point(), kt�re okre�laj� prawy g�rny r�g i lewy dolny
    line(img, Point(256, 100), Point(300, 456), Scalar(50, 100, 150), 5);

    imshow("Blank", img);

    waitKey(0);
}

void text()
{
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

    putText(img, "pozdrawiam", Point(50, 100), FONT_HERSHEY_DUPLEX, 2, Scalar(0, 69, 255), 2);

    imshow("Blank", img);

    waitKey(0);
}