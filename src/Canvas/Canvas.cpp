#include "Canvas.h"
#include <stdexcept>
#include <iostream>

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

void Canvas::except(unsigned int p){
        std::cout << "\u001b[31m for unsigned int '" << p << "' : ";
        throw std::runtime_error(" pixel value out of screen-range \u001b[0m");
}

void Canvas::write_pixel(unsigned int x, unsigned int y, const Color& col){
        try{
                if(x >= width) {
                        Canvas::except(x);
                }
                if(y >= height) {
                        Canvas::except(y);
                }
        }
        catch(std::exception const & e) {
                std::cout<< e.what() << '\n';
        }

        box[((y*width) + x)] = Color(col);
}
Color Canvas::pixel_at(unsigned int x, unsigned int y){
        try{
                if(x >= width) {
                        Canvas::except(x);
                }
                if(y >= height) {
                        Canvas::except(y);
                }
        }
        catch(std::exception const & e) {
                std::cout<< e.what() << '\n';
        }
        return box[((y*width) + x)];
}
