#ifndef _KERNEL_H
#define _KERNEL_H

class Kernel
{
    public:
        

        int start();
        static bool isRunning; 

    private:
       
        SDL_Window* createWindow(const char* window_title, int width, int height);
        bool initSDL();
        bool update(SDL_Event event);
        void render();
        void cleanUp(SDL_Window* window, SDL_GLContext &glContext);

};

bool Kernel::isRunning = true;

#include "kernel.cpp"

#endif