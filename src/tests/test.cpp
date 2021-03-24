#include<iostream>
#include<Point.h>
#include<Vector.h>
#include<Color.h>
#include<Canvas.h>

using namespace tracer;

int main(){

  // if (__cplusplus > 201703L)
  //          std::cout << "C++20" << std::endl;
  //  else if (__cplusplus == 201703L)
  //          std::cout << "C++17" << std::endl;
  //  else if (__cplusplus == 201402L)
  //          std::cout << "C++14" << std::endl;
  //  else if (__cplusplus == 201103L)
  //          std::cout << "C++11" << std::endl;
  //  else if (__cplusplus == 199711L)
  //          std::cout << "C++98" << std::endl;
  //  else
  //          std::cout << "pre-standard C++" << std::endl;

Color c1 = Color(0, 153, 51);

Canvas C = Canvas(4, 5);
C.write_pixel(2, 6, c1);
std::cout << std::endl << (C.pixel_at(2, 2) != C.pixel_at(1, 1)) << std::endl;
std::cout << std::endl << (c1 != C.pixel_at(1, 1)) << std::endl;
std::cout << std::endl << (c1 != C.pixel_at(2, 2)) << std::endl;


  return 0;
}
