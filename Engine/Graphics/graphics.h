#ifndef _GRAPHICS_H
#define _GRAPHICS_H

class Graphics
{
    public:
        void initGL();
    private:

        void draw();
        void setViewport(int width, int height);
}

#include "graphics.cpp"

#endif