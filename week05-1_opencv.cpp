#include <opencv/highgui.h>
int main()
{///Intel performance library
    IplImage * img = cvLoadImage("c:/image.jpg");
    cvShowImage("week05", img);
    cvWaitKey(0);
}
