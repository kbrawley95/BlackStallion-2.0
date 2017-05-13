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

    //Generate OpenGL Context For Rendering Content To Window
    SDL_Context context = SDL_GLContext(window);

    //Initialise SDL2
    initSDL();


    //Initialise OpenGL 
    graphicsManager->initGL();

    //Main Game Loop
    while(isRunning)
    {
        eventHandling(event);
        update();
        render();
    }

    cleanUp();
}

bool Kernel::initSDL()
{
    //Error checking to ensure SDL has been configured properly
    if(SDL_Init(SDL_INIT_EVERYTHING !=0))
    {
        SDL_Log("Unable to Initialise SDL2\n", SDL_GetError());
        return -1;
    }
    else
    {
        SDL_Log("SDL Initialised\n");
    }

    //Specify OpenGL Verision
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    return true;
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