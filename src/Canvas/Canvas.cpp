#include "Canvas.h"
using namespace tracer;



Canvas::Canvas(unsigned int w, unsigned int h){
        width = w;
        height = h;
        box.resize(w*h);
        Color black = Color();
        for (unsigned int i = 0; i < box.size(); i++)
        {
                box.at(i) = black;
        }
}

void Canvas::write_pixel(unsigned int x, unsigned int y, const Color& col){
        box[((y*width) + x)] = Color(col);
}

Color Canvas::pixel_at(unsigned int x, unsigned int y){
        return box[((y*width) + x)];
}
