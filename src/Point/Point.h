
#ifndef POINT_H
#define POINT_H
#include<Tuple.h>

namespace tracer{

class Point : public Tuple
{
public:

Point();
Point(double, double, double);
void print();

};

}
#endif
