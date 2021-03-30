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
            {1,5,0},
            {-3,2,7},
            {0,6,-3}
        };
    double l[4][4] = {
            {2,-1,5,0},
            {7,-3,2,7},
            {2,0,6,-3},
            {6,2,-6,8}
    };

    M = k;
    M.print();
    Matrix N = M.sub(3,3);
    N.print();

return 0;
}
