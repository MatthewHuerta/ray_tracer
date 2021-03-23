#ifndef PIXEL_H
#define PIXEL_H
#include <Tuple.h>
namespace tracer{

class Pixel : public Tuple{
public:

Pixel();
Pixel(double, double, double);
void print();

};
}

#endif
