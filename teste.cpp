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
    Mat image;
    Mat gray_image;

    image = imread(argv[1], 1);
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    cout << "teste";
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    image.data = 0;
    imshow("Display Image", gray_image);
    waitKey(0);
    return 0;
}
