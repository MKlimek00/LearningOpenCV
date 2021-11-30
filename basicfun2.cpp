#include "basicfun2.h"

void grayscale()
{
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny;

    cvtColor(img, imgGray, COLOR_BGR2GRAY); // COLOR_BGR2GRAY -> skala BGR do skali GRAY

    imshow("basic", img);
    imshow("basic", imgGray);

    waitKey(0);
}

void blur()
{
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgBlur;

    GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);// size(x,y) -> wielko�� kernela -> macierzy przekszt�caj�cej obraz, x,y ~ rozmycie, sigmax,sigmay, nieznacznie wp�ywa na rozmycie

    imshow("basic", img);
    imshow("Blur", imgBlur);

    waitKey(0);
}

void edges()
{
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgCanny;

    //algorytm cannyego do wykrywania kraw�dzi
    Canny(img, imgCanny, 150, 200);// kolejno�� treshold�w nie ma znaczenia, tresholdy ustawiaj� zakres histerezy

    imshow("basic", img);
    imshow("canny", imgCanny);

    waitKey(0);
}

void dilation()
{
    //na normalnym obrazku -> cie�sze kraw�dzie -> t�o si� poszerza
    //dodatek do cannego -> pogrubienie uzyskanych kontur�w
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgCanny, imgDil;

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    Canny(img, imgCanny, 150, 200);
    dilate(imgCanny, imgDil, kernel);

    //imshow("basic", img);
    imshow("canny", imgCanny);
    imshow("DIL", imgDil);

    waitKey(0);
}
void erosion()
{
    // cie�sze kraw�dzie
    // erozja na canny daje czarny obraz, dobrze jest wcze�niej scali� kraw�dzie dylatacj�
    string path = "Resources/test.jpg";
    Mat img = imread(path);
    Mat imgCanny, imgEro;

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    Canny(img, imgCanny, 150, 200);
    erode(img, imgEro, kernel);

    imshow("canny", imgCanny);
    imshow("ero", imgEro);

    waitKey(0);
}
