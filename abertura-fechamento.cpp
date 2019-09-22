#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat structuringElement = getStructuringElement(MORPH_RECT, Size(3, 3));

    Mat image, gray, bw, eroded, dilated, open, closed;

    image = imread(argv[1], 1);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    bw = gray > 128;
    
    erode(bw, eroded, structuringElement);
    dilate(eroded, open, structuringElement);
    imshow("Open Image (opening morphologic filter)", open);
    
    dilate(bw, dilated, structuringElement);
    erode(dilated, closed, structuringElement);
    imshow("Closed Image (closing morphologic filter)", closed);

    waitKey(0);
    return 0;
}
