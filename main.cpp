#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

#include "imvidweb1.h"
#include "basicfun2.h"
#include "resizecrop3.h"

using namespace cv;
using namespace std;

void warp();

int main()
{
    //1. imvidweb
    //images();
    //videos();
    //webcam();

    //2.basicfun
    //grayscale();
    //blur();
    //edges();
    //dilation();
    //erosion();

    //3.resizecrop
    //gettingSize();
    //resizing();
    //cropping();

    //4.drawwrite
    //blankimg();
    //drawShape();
    //text();

    //5.warp
    warp();

    return 0;
}

void warp()
{
    string path = "Resources/warp.jpg";
    Mat img = imread(path);
    float w = 148;
    float h = 210;
    Mat matrix, imgWarp;

    Point2f corners[4] = { { 773, 628 }, { 1433, 825 }, { 24, 1223 }, { 965, 1771 } }; // kolejność rogów LG, PG, LD, PD
    Point2f dest[4] = { { 0.0f, 0.0f }, { w, 0.0f }, { 0.0f, h }, { w, h } };

    matrix = getPerspectiveTransform(corners, dest);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    imshow("basic", img);
    imshow("warp", imgWarp);

    waitKey(0);
}