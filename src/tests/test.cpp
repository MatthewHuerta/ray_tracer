#include<iostream>
//#include<Point.h>
//#include<Vector.h>
//#include<Color.h>
//#include<Canvas.h>
#include "Tuple.h"
#include"Matrix.h"
#include"../tests/Debug.cpp"

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
            {8,-5,9,2},
            {7,5,6,1},
            {-6,0,9,6},
            {-3,0,-9,-4}
    };

    M = p;
    N = M.invert();

    TIME(N.print())
    TIME(M.print())

    return 0;
}
