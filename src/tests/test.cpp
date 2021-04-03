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

//
        double k[3][3] = {
            {3,5,0},
            {2,-1,-7},
            {6,-1,5}
        };
    double l[4][4] = {
            {2,-1,5,0},
            {7,-3,2,7},
            {2,0,6,-3},
            {6,2,-6,8}
    };

    M = k;
    M.print();
    Matrix N = M.sub(1,0);
    N.print();

    std::cout<< std::endl << M.cofactor(1,0) << std::endl;

return 0;
}
