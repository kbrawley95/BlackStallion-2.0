Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

void Graphics::initOpenGL()
{
    //Enable Backface Culling
    glCullFace(GL_BACK);
  
    //Smooth shading
    glShadeModel(GL_SMOOTH);

    //Clear the background to black
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    
    //Clear the depth buffer to 1.0
    glClearDepth(1.0f);

    //Enable depth testing
    glEnable(GL_DEPTH_TEST);
    

    //Specify the depth test to use
    glDepthFunc(GL_LEQUAL);

    //Turn on best persepctive correction
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    GLenum err=glewInit();
    if(GLEW_OK!=err)
    {
        /*Problem: glewInit failed, something is seriously wrong*/
        std::cout<<"Error: "<<glewGetErrorString(err)<<std::endl;
    }
}

void Graphics::setViewport(int width, int height)
{
    //Setup viewport
    glViewport(0,0,(GLsizei)width, (GLsizei)height);

    
}