#include<iostream>
#include<Point.h>
#include<Vector.h>
#include<Color.h>
#include<Canvas.h>

using namespace tracer;

int main(){

Color c1 = Color(0, 153, 51);

Canvas C = Canvas(10, 10);
C.write_pixel(2, 6, c1);
// std::cout << std::endl << (C.pixel_at(2, 2) != C.pixel_at(1, 1)) << std::endl;
// std::cout << std::endl << (c1 != C.pixel_at(1, 1)) << std::endl;
// std::cout << std::endl << (c1 != C.pixel_at(2, 2)) << std::endl;
C.write_ppm();

  return 0;
}
