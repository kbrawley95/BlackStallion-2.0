#ifndef _KERNEL_H
#define _KERNEL_H

#include "../common.h"

class Kernel
{
    public:

        void start();

    private:

        //Class Fields
        bool isRunning = true;
        float currentTime=0;
        float lastTime = 0;
        float deltaTime = 0;

        SDL_Window* createWindow(std::string windowName);
        void eventHandling(SDL_Event* event);
        void update();
        void render();
        void cleanUp();

}

#include "kernel.cpp"

#endif