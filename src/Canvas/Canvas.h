#ifndef CANVAS_H
#define CANVAS_H
#include <Color.h>
#include <vector>

namespace tracer {

class Canvas {
public:
unsigned int width = 0;
unsigned int height = 0;
bool swtch = false;

std::vector<Color> box;

static void except(unsigned int);

static void except2(int);

static int count_digits(int);

static double scale_color(const double& c);

static void printfill(const double&);

void strobe();

static void stop_strobe();

void print_canvas();

Canvas(unsigned int, unsigned int);

void write_pixel(unsigned int, unsigned int, const Color&);

Color pixel_at(unsigned int, unsigned int);

void write_ppm();

};
}
#endif
