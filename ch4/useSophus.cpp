#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

//basic Sophus usage

int main(int argc, char **argv) {
  
  // SO(3) part 

  // 90 degree rotation along z axis
  Matrix3d R = AngleAxisd(M_PI / 2, Vector3d(0, 0, 1)).toRotationMatrix();
  // or quaternion
  Quaterniond q(R);
  Sophus::SO3d SO3_R(R);              // Sophus::SO3d init with rotation matrix //d=double
  Sophus::SO3d SO3_q(q);              // initialize with quaternion
  
  cout << "SO(3) from matrix:\n" << SO3_R.matrix() << endl;
  cout << "SO(3) from quaternion:\n" << SO3_q.matrix() << endl;
  cout << "they are equal" << endl;

  // logarithmic map to get Lie algebra
  Vector3d so3 = SO3_R.log();
  cout << "so3 = " << so3.transpose() << endl;
  // hat: vector to skew symmetric matrix
  cout << "so3 hat=\n" << Sophus::SO3d::hat(so3) << endl;
  // inversely from mat to vec
  cout << "so3 hat vee= " << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() << endl;

  // update by perturbation model 
  Vector3d update_so3(1e-4, 0, 0); // this is a small update
  Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3) * SO3_R;
  cout << "SO3 updated = \n" << SO3_updated.matrix() << endl;

  cout << "*******************************" << endl;
  // similar for SE(3)
  Vector3d t(1, 0, 0);           // translation 1 along axis X
  Sophus::SE3d SE3_Rt(R, t);           // construct SE(3) from R, t
  Sophus::SE3d SE3_qt(q, t);            // construct SE(3) from q, t
  cout << "SE3 from R,t= \n" << SE3_Rt.matrix() << endl;
  cout << "SE3 from q,t= \n" << SE3_qt.matrix() << endl;
  // Lie algebra is 6d vector, we give a typedef
  typedef Eigen::Matrix<double, 6, 1> Vector6d;
  Vector6d se3 = SE3_Rt.log();
  cout << "se3 = " << se3.transpose() << endl;
  // output shows sophus puts translation at first in se(3), then rotation.
  // same as SO(3) we have hat and vee
  cout << "se3 hat = \n" << Sophus::SE3d::hat(se3) << endl;
  cout << "se3 hat vee = " << Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose() << endl;

  // Finally update
  Vector6d update_se3;
  update_se3.setZero();
  update_se3(0, 0) = 1e-4;
  Sophus::SE3d SE3_updated = Sophus::SE3d::exp(update_se3) * SE3_Rt;
  cout << "SE3 updated = " << endl << SE3_updated.matrix() << endl;

  return 0;
}
