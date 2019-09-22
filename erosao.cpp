#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

struct point
{
    int x;
    int y;
};

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

    Mat bw = gray_image > 128;
    Mat eroded = bw.clone();

    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }

    point mask[3][3] =
        {{{-1, -1}, {0, -1}, {1, -1}},
         {{-1, 0}, {0, 0}, {1, 0}},
         {{-1, 1}, {0, 1}, {1, 1}}};

    for (int r = 1; r < eroded.rows; r++)
    {
        for (int c = 1; c < eroded.cols; c++)
        {
            int mrows = sizeof(mask) / sizeof(mask[0]);
            int mcols = sizeof(mask[0]) / sizeof(mask[0][0]);
            for (int mr = 0; mr < mrows; mr++)
            {
                for (int mc = 0; mc < mcols; mc++)
                {
                    point maskpoint = mask[mr][mc];
                    if (bw.at<uchar>(r + maskpoint.y, c + maskpoint.x) == 0)
                    {
                        eroded.at<uchar>(r, c) = 0;
                        continue;
                    }
                }
            }
        }
    }

    imshow("Black and White", bw);
    imshow("Eroded Image", eroded);

    waitKey(0);
    return 0;
}
