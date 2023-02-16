// how to use Geometry module

#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main(int argc, char** argv){
    // Eigen/Geometry module provides many rotation, translation representations

    // 3D rotation matrix uses Matrix3d or Matrix3f
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    
    // rotation vector is uses AngleAxis, the underlying layer is not directly Matrix, 
    // but the operation can be treated as a matrix (operator overloading 
    Eigen::AngleAxisd rotation_vector (M_PI/4, Vector3d(0,0,1)); //Rotate 45 degree along the Z axis
    // theta & n as a parameter.. 

    cout.precision(3);
    cout<<"rotation matrix from rot vec = \n" <<rotation_vector.matrix()<<endl;
    rotation_matrix=rotation_vector.toRotationMatrix(); //Rodridues
    cout<<"rotation matrix = \n" <<rotation_matrix<<endl;

    Vector3d v(1,0,0);
    Vector3d v_rotated=rotation_vector*v;
    cout<<"(1,0,0) after rotation (by angle axis) = "<<v_rotated.transpose()<<endl;
    v_rotated = rotation_matrix*v;
    cout<<"(1,0,0) after rotation (by matrix) = "<<v_rotated.transpose()<<endl;

    //Euler Angle 
    //convert euler angle and rotation matrix or vice versa. for human understanding 
    Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0); //ZYX order, y p r
    cout<<"yaw pitch roll = "<<euler_angles.transpose()<<endl;

    //Euclidean Transformation 4x4 
    Isometry3d T= Isometry3d::Identity(); //3.. but is actually 4x4
    T.rotate(rotation_vector); //dont use euler here
    T.pretranslate(Vector3d(1,3,4));
    cout<<"Transformation Matrix = \n"<<T.matrix()<<endl;
    
    Vector3d v_transformed =T*v;
    cout<<"v transformed = "<<v_transformed.transpose()<<endl;


    //quaternion
    Quaterniond q=Quaterniond(rotation_vector);
    cout<<"quaternion from rotation vector = "<<q.coeffs().transpose()<<endl;
    q=Quaterniond(rotation_matrix);
    cout<<"quaternion from rotation matrix = "<<q.coeffs().transpose()<<endl;

    v_rotated = q*v;
    cout<<"(1,0,0) after rotation (quaternion) = "<<v_rotated.transpose()<<endl;
    cout<<"should be equal to  "<<(q*Quaterniond(0,1,0,0)*q.inverse()).coeffs().transpose()<<endl; //math form

    //real is in the last (quaternion order)







    return 0;




}