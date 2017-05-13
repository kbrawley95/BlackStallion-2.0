SDL_Window* Kernel::createWindow(std::string windowName)
{
    SDL_window* window = SDL_CreateWindow(
                        windowName, 
                        CENTEREDPOS, 
                        CENTEREDPOS, 
                        Kernel::WIDTH, 
                        Kernel::HEIGHT, 
                        SDL_OPENGL_CONTEXT
    );

    return window;
}

//Initialisation Method (Executed on Engine Start)
void Kernel::start()
{
    SDL_Window* window = createWindow("Test Window");
    SDL_Event* event;

    SDL_Context context = SDL_GLContext(window);

    //Main Game Loop
    while(isRunning)
    {
        eventHandling(event);
        update();
        render();
    }

    cleanUp();
}

void Kernel::eventHandling(SDL_Event* event)
{

}

void Kernel::update()
{
    Time::currentTime = SDL_GetTicks();
    Time::lastTime = Time::currentTime;

    Time::deltaTime = (currentTime - lastTime) /1000; //Get the difference in time between frames in seconds
}

void Kernel::render()
{

}

void Kernel::cleanUp()
{
    delete window;
}