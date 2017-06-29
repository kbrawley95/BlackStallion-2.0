#ifndef _KERNEL_H
#define _KERNEL_H

class Kernel
{
    public:
        int start();
    private:
        static bool isRunning; 

        SDL_Window* createWindow(const char* window_title, int width, int height);
        void update();
        void render();
        void cleanUp(SDL_Window* window);

};

bool Kernel::isRunning = true;

#include "kernel.cpp"

#endif