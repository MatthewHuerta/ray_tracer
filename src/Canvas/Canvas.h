#ifndef CANVAS_H
#define CANVAS_H
#include<Color.h>
#include<vector>

namespace tracer {

        class Canvas {
        public:
            unsigned int width = 0;
            unsigned int height = 0;

            std::vector<Color> box;

            void except(unsigned int);

            Canvas(unsigned int, unsigned int);

            void write_pixel(unsigned int, unsigned int, const Color&);

            Color pixel_at(unsigned int, unsigned int);

        };
}
#endif
