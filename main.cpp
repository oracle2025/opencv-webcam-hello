#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
    CvCapture* capture = 0;
    Mat frame, frameCopy, image;

    capture = cvCaptureFromCAM( 1 ); //0=default, -1=any camera, 1..99=your camera
    if(!capture) cout << "No camera detected" << endl;

    cvNamedWindow( "result", CV_WINDOW_AUTOSIZE  );

    if( capture )
    {
        cout << "In capture ..." << endl;
        for(;;)
        {
            IplImage* iplImg = cvQueryFrame( capture );
            frame = iplImg;
            if( frame.empty() ) {
            	std::cout << "frame empty" << std::endl;
                break;
            }
            if( iplImg->origin == IPL_ORIGIN_TL )
                frame.copyTo( frameCopy );
            else
                flip( frame, frameCopy, 0 );

			cvShowImage( "result", iplImg );

            if( waitKey( 10 ) >= 0 )
                cvReleaseCapture( &capture );
        }
        std::cout << "waitkey" << std::endl;

        waitKey(0);

    cvDestroyWindow("result");

    return 0;
    }
}
