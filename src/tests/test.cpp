#include<iostream>
//#include<Point.h>
//#include<Vector.h>
//#include<Color.h>
//#include<Canvas.h>
#include "Tuple.h"
#include"Matrix.h"

using namespace tracer;

int main() {

    auto M = Matrix();

//
        double k[3][3] = {
            {1,5,0},
            {-3,2,7},
            {0,6,-3}
        };
    M = k;
    M.print();
    N.print();

return 0;
}
