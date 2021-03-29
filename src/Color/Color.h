#ifndef COLOR_H
#define COLOR_H
#include <Tuple.h>
namespace tracer {

class Color : public Tuple {
public:

Color();
Color(double, double, double);
Color(const Color&);
explicit Color(const Tuple&);
bool operator==(const Color& b);
bool operator!=(const Color& b);
Color operator*(const Color& b);
void print() override;

};
}

#endif
