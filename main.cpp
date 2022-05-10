#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

///////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<Point> points; // Store the points as global variables

void CallBackFunc(int event, int x, int y,int flag, void* values)
{
    if  ( event == EVENT_LBUTTONDOWN )
    {
        points.emplace_back(x,y);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{

    Mat img = imread("car.jpg");
    namedWindow(" Window", 1);
    setMouseCallback(" Window", CallBackFunc, nullptr); // Add the pointer to the callback

    while (waitKey(33) != 27)
    {
        //Draw your points
        for (auto & point : points)
        {
            string str_x = to_string(point.x);
            string str_y = to_string(point.y);
            string point_text = ".(" + str_x +" ," + str_y +")";

            putText(img,point_text,Point2i(point.x, point.y),FONT_HERSHEY_COMPLEX,0.25,Scalar(255,15,3),0.25);
        }
        imshow(" Window", img);

    }
    return 0;

}

