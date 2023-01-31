#include <iostream>
using namespace std;

#include <ctime>
//Eigen core
#include <Eigen/Core>

//dense matrix operation (inverse, eigenvalues, etc.)
#include <Eigen/Dense>
using namespace Eigen;

#define MATRIX_SIZE 50

//about basic eigen usage

int main(int argc, char** argv){

    Matrix<float, 2, 3> matrix_23; //vec, mat are in Eigen::Matrix - template class.
    Vector3d v_3d; //typedef in Eigen. Vector3d== Matrix<double, 3,1> this is 3-d vector
    Matrix<float, 3,1> vd_3d; //same as above

    Matrix3d matrix_33=Matrix3d::Zero(); //Matrix3d==Eigen::Matrix<double, 3,3>
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    MatrixXd matrix_x; //same. dynamic size mat

    matrix_23<<1,2,3,4,5,6; //init
    cout<<"matrix 2x3 from 1 to 6: \n" <<matrix_23<<endl; //cout Eigen::Matrix
    cout<<"print matrix 2x3: "<<endl;
    for (int i=0;i<2;i++){
        for (int j=0; j<3;j++){
            cout<<matrix_23(i,j)<<"\t";
        }
        cout<<endl;
    }

    
    v_3d<<3,2,1;
    vd_3d<<4,5,6;

    //datatype mixing ERROR 
    
    //===================================comment
    // Matrix<double, 2, 1> result_wrong_type=matrix_23*v_3d; //ERROR 
    //explicitly convert by .cast<type>() function
    Eigen::Matrix<double, 2, 1> result=matrix_23.cast<double>()*v_3d;
    cout<<"[1,2,3;4,5,6]*[3,2,1]= (transpose)"<<result.transpose()<<endl;
    Eigen::Matrix<float, 2,1> result2=matrix_23*vd_3d;
    cout<<"[1,2,3;4,5,6]*[4,5,6]= (no-transpose)"<<result2.transpose()<<endl;


    //===================================comment
    // Eigen::Matrix<double, 2,3> result_wrong_dimension=matrix_23.cast<double>()*v_3d;
    //un ERROR

    matrix_33=Matrix3d::Random(); //<double, 3, 3>
    cout<<"random matrix: \n" <<matrix_33<<endl;
    cout<<"transpose: \n" <<matrix_33.transpose()<<endl;
    cout<<"sum: "<<matrix_33.sum()<<endl;
    cout<<"trace: "<<matrix_33.trace()<<endl;
    cout<<"times 10: \n"<<10* matrix_33<<endl;
    cout<<"inverse: \n"<<matrix_33.inverse()<<endl;
    cout<<"det: "<<matrix_33.determinant()<<endl;

    //Eigenvalues
    //real valued symmetric matrix can guarantee EVD & their V(eigen vectors) are orthogonal 
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
    cout<<"Eigen values = \n" <<eigen_solver.eigenvalues()<<endl;
    cout<<"Eigen vectors =\n"<<eigen_solver.eigenvectors()<<endl;

    //Solving eqs
    //We solve the eq of matrix_NN *x =v_Nd ==> x?
    //N is predifined & filled with random num
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN=
    MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN=matrix_NN*matrix_NN.transpose(); //guarantee semi-positive definite==>eigenvalue positive or zero 
    Matrix<double, MATRIX_SIZE, 1> v_Nd=MatrixXd::Random(MATRIX_SIZE, 1);
    
    clock_t time_stt=clock(); //timing

    //Direct inversion
    Matrix<double, MATRIX_SIZE, 1> x=matrix_NN.inverse()*v_Nd;
    cout<<"time use in normal inverse is "<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    cout<<"x = "<<x.transpose()<<endl;

    //Solved by matrix decomposition, such as QR
    time_stt = clock();
    x=matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout<<"time use in Qr decomposition is "<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    cout<<"x = "<<x.transpose()<<endl;

    //for positive definite mat, u can use cholesky decomp
    time_stt = clock();
    x=matrix_NN.ldlt().solve(v_Nd);
    cout<<"time use in ldlt decomposition is "<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    cout<<"x = "<<x.transpose()<<endl;





    return 0;
}