#include<iostream>
//#include<Point.h>
//#include<Vector.h>
//#include<Color.h>
//#include<Canvas.h>
#include"Matrix.h"

using namespace tracer;

int main() {

    Matrix M = Matrix(4, 4);
    double k = 0;
        for (int j = 0; j < M.y; j++) {
            for (int i = 0; i < M.x; i++) {
               M.matrix[i][j] = k;
               k++;
            }
        }

    M.print();

    std::cout << std::endl << M.matrix[1][2] << std::endl;



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
