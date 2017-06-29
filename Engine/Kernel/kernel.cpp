int Kernel::start()
{
    //SDL Initialisation
    initSDL();

    //Create an application window with the following settings
    SDL_Window* window= createWindow("Test", 640, 480);
   
    //Generate OpenGL Context and mapp to window
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    //OpenGL Intialisation
    Graphics* graphics_manager;
    graphics_manager->initOpenGL();

    //Check that the window was succesfully created
    if(window == NULL)
    {
        //Print error, if null
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //Variable Declaration
    SDL_Event event;

    //The window is open: could enter program loop here
    while(Kernel::isRunning)
    {
        update(event);
        render();
    }

    //Free up memory resources
    cleanUp(window, glContext);
}

bool Kernel::initSDL()
{
    /*SDL ERROR CHECKING*/
    if (SDL_Init(SDL_INIT_NOPARACHUTE & SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return -1;
    }
    else{
        SDL_Log("SDL initialized");
    }
    /*SDL_IMAGE ERROR CHECKING*/
    int	imageInitFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	int	returnInitFlags = IMG_Init(imageInitFlags);
	if (((returnInitFlags) & (imageInitFlags)) != imageInitFlags)	{

		std::cout << "ERROR SDL_Image Init" << IMG_GetError() << std::endl;
	}

    /*TTF (Fonts) ERROR CHECKING*/
    if (((returnInitFlags) & (imageInitFlags)) != imageInitFlags)	{

		std::cout << "ERROR SDL_Image Init" << IMG_GetError() << std::endl;
	}

	if (TTF_Init() == -1)	{
		std::cout << "ERROR	TTF_Init: " << TTF_GetError();
	}

    //Specify OpenGL Version (4.2)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    return true;
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

bool Kernel::update(SDL_Event event)
{
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Kernel::isRunning=false;
                break;
            case SDL_WINDOWEVENT_CLOSE:
                Kernel::isRunning=false;
                break;
        }
    }

    return true;
}

void Kernel::render()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
}

void Kernel::cleanUp(SDL_Window* window, SDL_GLContext &glContext)
{
    //Destroy Context
    SDL_GL_DeleteContext(glContext);

    //CLose and destroy the window
    SDL_DestroyWindow(window);

    //Clean Up
    SDL_Quit();
}
