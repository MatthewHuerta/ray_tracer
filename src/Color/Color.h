#ifndef COLOR_H
#define COLOR_H
#include <Tuple.h>
namespace tracer {

class Color : public Tuple {
public:

Color();
Color(double, double, double);
Color(const Color&);
Color(const Tuple&);
Color operator*(const Color& b);
void print();

};
}

#endif
