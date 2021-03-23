#include<iostream>
#include<Point.h>
#include<Vector.h>
#include<Pixel.h>

using namespace tracer;

int main(){

Vector red = Vector(255, 0, 0);
red.print();

Point my_p = Point(2, 2, 2);
my_p.print();

Pixel pix = Pixel(3, 4, 5);
pix.print();

  return 0;
}
