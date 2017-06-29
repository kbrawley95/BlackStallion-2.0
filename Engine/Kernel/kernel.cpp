int Kernel::start()
{
    SDL_Window* window;

    //Error Checking
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;

    //Create an application window with the following settings
    window = createWindow("Test", 640, 480);

    //Check that the window was succesfully created
    if(window == NULL)
    {
        //Print error, if null
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //The window is open: could enter program loop here
    while(Kernel::isRunning)
    {
        update();
        render();
    }

    //Free up memory resources
    cleanUp(window);
}

SDL_Window* Kernel::createWindow(const char* window_title, int width, int height)
{
    SDL_Window* window = SDL_CreateWindow(
        window_title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    return window;
}

void Kernel::update()
{

}

void Kernel::render()
{

}

void Kernel::cleanUp(SDL_Window* window)
{
    //CLose and destroy the window
    SDL_DestroyWindow(window);

    //Clean Up
    SDL_Quit();
}
