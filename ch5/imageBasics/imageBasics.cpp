#include <iostream>
#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv){
  // read image in argv[1]
  cv::Mat image;
  image=cv::imread(argv[1]);

// check if correctly loaded
  if(image.data==nullptr){
    cerr<<"file"<<argv[1]<<"does not exist. "<<endl;
    return 0;  
  }

// some basic informations
  cout<<"Image cols: " <<image.cols<<" ,Image rows: "<<image.rows<<", Image channels: "<<image.channels()<<endl;
  cv::imshow("image", image);
  cv::waitKey(0);

// check image type
  if(image.type()!=CV_8UC1&&image.type()!=CV_8UC3){
    //we need grayscale or rgb img
    cout<<"image type incorrect"<<endl;
    return 0;
  }
  
  chrono::steady_clock::time_point t1=chrono::steady_clock::now();
  for(size_t y=0; y<image.rows; y++){
    // use cv::Mat::ptr to get the pointer of each row
    unsigned char* row_ptr = image.ptr<unsigned char>(y);

    for(size_t x=0; x<image.cols; x++){
      // read the pixel on (x,y), x=column, y=row
      unsigned char* data_ptr=&row_ptr[x*image.channels()]; //data_ptr is pointer to (x,y)
      // visit the pixel in each channel

      // allocating by here and start filling in    
      for(int c=0;c!=image.channels();c++){
        unsigned char data = data_ptr[c]; //data should be pixel of I(x,y) in c-th channel
      }
    }
  }
  chrono::steady_clock::time_point t2=chrono::steady_clock::now();
  chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2-t1);
  cout<<"time used: "<<time_used.count()<<" seconds"<<endl;

  // operator = will not copy the image data, only the reference
  cv::Mat image_another=image;
  image_another(cv::Rect(0,0,100,100)).setTo(0);
  cv::imshow("image", image);
  cv::waitKey(0);

  // use cv::Mat::clone to actually clone the data
  cv::Mat image_clone = image.clone();
  image_clone(cv::Rect(0,0,100,100)).setTo(255);
  cv::imshow("image", image);
  cv::waitKey(0);


  cv::destroyAllWindows();
  return 0;
}