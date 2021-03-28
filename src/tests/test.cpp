#include<iostream>
//#include<Point.h>
//#include<Vector.h>
//#include<Color.h>
//#include<Canvas.h>
#include"Matrix.h"

using namespace tracer;

int main() {

    Matrix M = Matrix(4, 4);
    Matrix N = Matrix(4, 4);

        double k[4][4] = {
            {1,2,3,4},
            {5,6,7,8},
            {9,8,7,6},
            {5,4,3,2}
        };

    double l[4][4] = {
            {-2,1,2,3},
            {3,2,1,-1},
            {4,3,6,5},
            {1,2,7,8}
    };
    M = k;
    N = l;
    Matrix O = M*N;
    M.print();
    N.print();
    O.print();
    std::cout<<std::endl<<O[3][2]<<std::endl;

    std::cout << std::endl << (M==N) << std::endl;



//Color c1 = Color(1, .8, .6);
//
//Canvas C = Canvas(10, 2);
//
//for(int i = 0; i < C.height; i++) {
//    for (int u = 0; u < C.width; u++){
//        C.write_pixel(u, i, c1);
//    }
//}
//
//C.write_ppm();
//
//C.print_canvas();
return 0;
}
