#define DEBUG 1

#include <Debug.cpp>
#include "Canvas.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace tracer;

Canvas::Canvas(unsigned int w, unsigned int h) {
    width = w;
    height = h;
    box.resize(w * h);
    Color black = Color();
    for (auto & i : box) {
        i = black;
    }
}

void Canvas::except(unsigned int p) {
    std::cout << "\u001b[31m for unsigned int '" << p << "' : ";
    throw std::runtime_error(" pixel value out of screen-range \u001b[0m");
}

void Canvas::except2(int p) {
    std::cout << "\u001b[31m too-large pixel value '" << p << "' : ";
    throw std::runtime_error(" pixel value out of range \u001b[0m");
}

int Canvas::count_digits(int number) {
    if (number == 0) return 1;
    int count = 0;
    while (number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

double Canvas::scale_color(const double& c) {
    double result = c * 255;
    if(result < 0)
        return 0;
    if(result > 255)
        return 255;
    return result;
}


void Canvas::printfill(const double &n) {
    if (Canvas::count_digits(n) == 1) {
        std::cout << ' ' << n << ' ';
    } else if (Canvas::count_digits(n) == 2) {
        std::cout << ' ' << n;
    } else if (Canvas::count_digits(n) == 3) {
        std::cout << n;
    } else Canvas::except2(n);
}


void Canvas::strobe() {
    if (swtch == false){
        std::cout << "\u001b[33m";
    } else {
        std::cout << "\u001b[34m";
    }
    swtch = !(swtch);
}

void Canvas::stop_strobe() {
    std::cout << "\u001b[0m";
}

void Canvas::print_canvas() {
    unsigned int i = 0;
    for (unsigned int h = 0; h < height; h++) {
        for (unsigned int w = 0; w < width; w++) {
            strobe();
            printfill(scale_color(box[i].x));
            std::cout << " ";
            printfill(scale_color(box[i].y));
            std::cout << " ";
            printfill(scale_color(box[i].z));
            if ((w == width - 1) || (w > 70)) {
                std::cout << '\n';
                if ((width % 2) == 0)
                    strobe();
            } else {
                std::cout << " ";
            }
            i++;

        }

    }
    stop_strobe();
}

void Canvas::write_pixel(unsigned int x, unsigned int y, const Color &col) {
    try {
        if (x >= width) {
            Canvas::except(x);
        }
        if (y >= height) {
            Canvas::except(y);
        }
    }
    catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }

    box[((y * width) + x)] = Color(col);
}


Color Canvas::pixel_at(unsigned int x, unsigned int y) {
    try {
        if (x >= width) {
            Canvas::except(x);
        }
        if (y >= height) {
            Canvas::except(y);
        }
    }
    catch (std::exception const &e) {
        std::cout << e.what() << '\n';
    }
    return box[((y * width) + x)];
}

void Canvas::write_ppm() {
    std::ofstream fs("image.ppm", std::ios::trunc);
    if (fs.is_open()) {
        fs << "P3" << '\n';
        fs << width << " " << height << '\n';
        fs << "255" << "\n";
        unsigned int i = 0;
        unsigned short charcount = 0;
        for (unsigned int h = 0; h < height; h++) {
            charcount = 0;
            for (unsigned int w = 0; w < width; w++) {

                fs << (scale_color(box[i].x));
                charcount += count_digits(scale_color(box[i].x));

                if ((charcount == 69) || (charcount + count_digits(scale_color(box[i].y)) > 69)) {
                    fs << '\n';
                    charcount = 0;
                } else {
                    fs << ' ';
                    charcount++;
                }

                fs << (scale_color(box[i].y));
                charcount += count_digits(scale_color(box[i].y));

                if ((charcount == 69) || (charcount + count_digits(scale_color(box[i].z)) > 69)) {
                    fs << '\n';
                    charcount = 0;
                } else {
                    fs << ' ';
                    charcount++;
                }

                fs << (scale_color(box[i].z));
                charcount += count_digits(scale_color(box[i].z));

                if ((charcount == 69) || (charcount + count_digits(scale_color(box[i + 1].x)) > 69) ||
                    (w == (width - 1))) {
                    fs << '\n';
                    charcount = 0;
                } else {
                    fs << ' ';
                    charcount++;
                }

                i++;

            }

        }
        fs.close();
    } else std::cout << std::endl << "unable to open file";

}
