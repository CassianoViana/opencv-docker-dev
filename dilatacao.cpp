#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

struct point
{
    int x;
    int y;
};

Mat dilatacao(Mat image){
    
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    Mat bw = gray_image > 128;
    Mat dilated = bw.clone();

    point mask[3][3] =
        {{{-1, -1}, {0, -1}, {1, -1}},
         {{-1, 0}, {0, 0}, {1, 0}},
         {{-1, 1}, {0, 1}, {1, 1}}};

    for (int r = 1; r < dilated.rows; r++)
    {
        for (int c = 1; c < dilated.cols; c++)
        {
            int mrows = sizeof(mask) / sizeof(mask[0]);
            int mcols = sizeof(mask[0]) / sizeof(mask[0][0]);
            for (int mr = 0; mr < mrows; mr++)
            {
                for (int mc = 0; mc < mcols; mc++)
                {
                    point maskpoint = mask[mr][mc];
                    if (bw.at<uchar>(r + maskpoint.y, c + maskpoint.x) == 255)
                    {
                        dilated.at<uchar>(r, c) = 255;
                        continue;
                    }
                }
            }
        }
    }
    return dilated;
}


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;

    image = imread(argv[1], 1);
    Mat dilated = dilatacao(image);
    //Mat dilated;
    Mat structuringElement = getStructuringElement(MORPH_RECT, Size(5, 5), Point(0,0));
    //dilate(image, dilated, structuringElement);

    imshow("Dilated Image", dilated);

    waitKey(0);
    return 0;
}
