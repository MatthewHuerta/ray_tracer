#include<iostream>
//#include<Point.h>
//#include<Vector.h>
//#include<Color.h>
//#include<Canvas.h>
#include "Tuple.h"
#include"Matrix.h"

using namespace tracer;

int main() {

    Matrix M = Matrix();
    // Matrix N = Matrix();


//
        double k[3][3] = {
            {1,2,6},
            {-5,8,-4},
            {2,6,4}
        };
    double l[4][4] = {
            {2,-1,5,0},
            {7,-3,2,7},
            {2,0,6,-3},
            {6,2,-6,8}
    };
    double p[4][4] = {
            {2,4,5,0},
            {7,8,2,7},
            {-2,0,6,-3},
            {-6,1,-6,8}
    };

    M = l;
    Matrix N = Matrix(M);

    M.print();
    N.print();
//    Matrix N = M.sub(1,0);
//    N.print();

    // std::cout<< std::endl << M.cofactor(0,0) << std::endl;
    //
    // std::cout<< std::endl << M.cofactor(0,1) << std::endl;
    //
    // std::cout<< std::endl << M.cofactor(0,2) << std::endl;
    //
    // std::cout<< std::endl << M.det() << std::endl;


    return 0;
}
