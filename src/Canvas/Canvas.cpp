#include "Canvas.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

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

void Canvas::write_ppm(){
        std::fstream fs("image.ppm", std::ios::out);
        if(fs.is_open())
        {
                // std::cout << std::endl << "made it this far.. I think" << std::endl;
                fs << "P3" << '\n';
                fs << width << " " << height << '\n';
                fs << "255" << '\n';
                std::cout << "canvas height: " << height << "canvas width: " << width << std::endl;
                std::cout << "box.size(): " << box.size() << std::endl;
                for(unsigned int i = 0; i < box.size();) {
                        std::cout << "box[i]: " << i << std::endl;
                        for(unsigned int h = 0; h < height; h++) {
                                std::cout << "height : " << height << std::endl;
                                for(unsigned int w; w <= width; w++) {
                                        if (w==width-1) {
                                                fs << ((box[i]).x * 255) << " " << ((box[i]).y * 255) <<" "<< ((box[i]).z * 255) << '\n';
                                                fs << ((box[i]).x * 255) << " " << ((box[i]).y * 255) <<" "<< ((box[i]).z * 255) << '\n';
                                                i++;
                                                return;
                                        } else{
                                                std::cout << ((box[i]).x * 255) << " " << ((box[i]).y * 255) <<" "<< ((box[i]).z * 255) << " ";
                                                fs << ((box[i]).x * 255) << " " << ((box[i]).y * 255) <<" "<< ((box[i]).z * 255) << " ";
                                                i++;
                                        }
                                }

                        }
                }
                fs.close();
        } else std::cout << std::endl << "unable to open file";

}
