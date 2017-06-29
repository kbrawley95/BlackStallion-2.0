#ifndef _GRAPHICS_H
#define _GRAPHICS_H

class Graphics
{
    public:
    Graphics();
    ~Graphics();

    void initOpenGL();
    void paintGL();
    void setViewport(int width, int height);
    void cleanUp();
   
   private:
    void sendDataToOpenGL();

};

#include "graphics.cpp"

#endif