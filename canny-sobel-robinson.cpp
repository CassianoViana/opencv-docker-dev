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

    Mat image, canned, sobed, robed;

    image = imread(argv[1], 1);
    
    Canny(image, canned, 200, 255);
    imshow("Canny Filter", canned);

    waitKey(0);
    return 0;
}
