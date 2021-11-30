#include "resizecrop3.h"

void gettingSize()
{
    string path = "Resources/test.jpg";
    Mat img = imread(path);

    cout << img.size() << endl;
}

void resizing()
{
    double scale = 0.5;
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgResize;

    //resize(img, imgResize, Size(640, 480)); // size(w,h) to nowy rozmiar obrazu
    resize(img, imgResize, Size(), scale, scale); // pusty size i skala w x i w y


    imshow("basic", img);
    imshow("rezize", imgResize);

    waitKey(0);
}

void cropping()
{
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgCrop;

    Rect roi(100, 100, 300, 250); // range of intrest

    imgCrop = img(roi);

    imshow("basic", img);
    imshow("crop", imgCrop);

    waitKey(0);
}
