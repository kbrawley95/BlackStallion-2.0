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
        
        //Class Instances
        Graphics* graphicsManager;

        //Initialisation
        void initSDL();

        //Pipeline Methods
        SDL_Window* createWindow(std::string windowName);
        void eventHandling(SDL_Event* event);
        void update();
        void render();
        void cleanUp();

}

#include "kernel.cpp"

#endif