#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <boost/format.hpp> //for formatting strings
#include <pangolin/pangolin.h>
#include <sophus/se3.hpp>


using namespace std;
typedef vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> TrajectoryType;
typedef Eigen::Matrix<double, 6,1> Vector6d;

void showPointCloud(const vector<Vector6d, Eigen::aligned_allocator<Vector6d>> &pointcloud);

int main(int argc, char** argv){
    vector<cv::Mat> colorImgs, depthImgs;
    TrajectoryType poses;  //camera poses

    ifstream fin("/home/sj/slambook2/studySLAM/ch5/rgbd/pose.txt");
    if (!fin){
        cerr<<"cannot find pose.txt"<<endl;
        return 1;
    }

    for (int i=0; i<5;i++){
        boost::format fmt("/home/sj/slambook2/studySLAM/ch5/rgbd/%s/%d.%s"); //the image format
        colorImgs.push_back(cv::imread((fmt%"color"%(i+1)%"png").str())); //make file name and convert to string 
        depthImgs.push_back(cv::imread((fmt%"depth"%(i+1)%"pgm").str(), -1 )); 
        //depth img option -1

        double data[7]={0}; //just put 0 .. no meaning
        for (auto &d: data)
            fin>>d;         // overwrite d
        Sophus::SE3d pose(Eigen::Quaterniond(data[6], data[3], data[4], data[5]),
                          Eigen::Vector3d(data[0], data[1], data[2]));
        poses.push_back(pose);
    }
    //we got colorImg vec, depthImg vec, pose vec

    //compute the point cloud using camera intrinsics
    double cx=325.5;
    double cy=253.5;
    double fx=518.0;
    double fy=519.0;
    double depthScale=1000.0;
    vector<Vector6d, Eigen::aligned_allocator<Vector6d>> pointcloud;
    pointcloud.reserve(1000000);         //resize!=reserve, size!=capacity

    for (int i=0; i<5; i++){
        cout<<"converting rgbd images "<<i+1<<endl;
        cv::Mat color=colorImgs[i];
        cv::Mat depth=depthImgs[i];
        Sophus::SE3d T=poses[i];
        for (int v=0; v<color.rows; v++){
            for (int u=0; u<color.cols; u++){
                unsigned int d = depth.ptr<unsigned short>(v)[u]; //depth: 16-bit //v , u
                if(d==0) continue;           //0 is no valid value. jump this and continue
                Eigen::Vector3d point;         //make x,y,depth point
                point[2]=double(d)/depthScale;        
                point[0]=(u-cx) *point[2] /fx;
                point[1]=(v-cy) *point[2] /fy;
                Eigen::Vector3d pointWorld = T*point;   //i th depth, i th pose T
                
                Vector6d p;
                p.head<3>()=pointWorld; //Eigen::Vectorxd::head(n) take first n entries
                //cv::Mat step: byte(1 for uchar)==cols of one row 
                //color: vector<cv::Mat> need .data to get to data
                p[5]=color.data[v*color.step + u*color.channels()];   //b
                p[4]=color.data[v*color.step + u*color.channels()+1]; //g
                p[3]=color.data[v*color.step + u*color.channels()+2]; //r
                //when using data[] think data as 1D list not 2D mat. 
                pointcloud.push_back(p);
            }
        }
    }
    cout<<"global point cloud has "<<pointcloud.size()<<"points."<<endl;
    showPointCloud(pointcloud);

    return 0;
}

void showPointCloud(const vector<Vector6d, Eigen::aligned_allocator<Vector6d>> &pointcloud) {

    if (pointcloud.empty()) {
        cerr << "Point cloud is empty!" << endl;
        return;
    }

    pangolin::CreateWindowAndBind("Point Cloud Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
    );

    pangolin::View &d_cam = pangolin::CreateDisplay()
        .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
        .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glPointSize(2);
        glBegin(GL_POINTS);
        for (auto &p: pointcloud) {
            glColor3d(p[3] / 255.0, p[4] / 255.0, p[5] / 255.0);
            glVertex3d(p[0], p[1], p[2]);
        }
        glEnd();
        pangolin::FinishFrame();
        usleep(5000);  
    }
    return;
}
