#include<iostream>
#include<Point.h>
#include<Vector.h>
#include<Color.h>

using namespace tracer;

int main(){

Color c1 = Color(1, .2, .4);
c1.print();

Color c2 = Color(.9, 1, .1);
c2.print();

Color newcolor = c1*c2;
newcolor.print();


  return 0;
}
