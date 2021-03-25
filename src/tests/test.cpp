#include<iostream>
#include<Point.h>
#include<Vector.h>
#include<Color.h>
#include<Canvas.h>

using namespace tracer;

int main(){

Color c1 = Color(0, .2, 1);
Color c2 = Color(1, 0, 0);

Canvas C = Canvas(40, 40);
C.write_pixel(0, 0, c1);
C.write_pixel(1, 0, c1);
C.write_pixel(2, 0, c1);
C.write_pixel(0, 1, c1);
C.write_pixel(1, 1, c2);
C.write_pixel(2, 1, c2);
C.write_pixel(0, 2, c2);
C.write_pixel(1, 2, c2);
C.write_pixel(2, 2, c2);
// std::cout << std::endl << (C.pixel_at(2, 2) != C.pixel_at(1, 1)) << std::endl;
// std::cout << std::endl << (c1 != C.pixel_at(1, 1)) << std::endl;
// std::cout << std::endl << (c1 != C.pixel_at(2, 2)) << std::endl;
C.write_ppm();

C.print_canvas();

  return 0;
}
