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
    Matrix N = Matrix();



        double k[3][3] = {
            {1,2,6},
            {-5,8,-4},
            {2,6,4}
        };
    double l[4][4] = {
            {-4,2,-2,-3},
            {9,6,2,6},
            {0,-5,1,-5},
            {0,0,0,0}
    };
    double p[4][4] = {
            {2,4,5,0},
            {7,8,2,7},
            {-2,0,6,-3},
            {-6,1,-6,8}
    };

    M = l;
    N = M.invert();
    N.print();

    return 0;
}
