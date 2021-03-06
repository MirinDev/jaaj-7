#include <Game.h>

Game::Game(int width, int height, const char *title, bool resize){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    this->window=SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | (resize ? SDL_WINDOW_RESIZABLE : SDL_WINDOW_SHOWN));
    //this->debug=SDL_CreateWindow("debug", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    this->windowContext=SDL_GL_CreateContext(this->window);

    gladLoadGL();

    this->cam=new Cam();
    this->cam->pos.z=-4.0f;

    //this->debugCam=new Cam();

    //this->shader=new Shader(("."+bar+"res"+bar+"shaders"+bar+"image.frag").c_str(), ("."+bar+"res"+bar+"shaders"+bar+"image.vert").c_str());
    this->shader=new Shader(("."+bar+"res"+bar+"shaders"+bar+"defalt.frag").c_str(), ("."+bar+"res"+bar+"shaders"+bar+"defalt.vert").c_str());

    std::vector<Texture> textures{
        Texture(("."+bar+"res"+bar+"images"+bar+"engine.png").c_str(), GL_REPEAT, GL_LINEAR, 0, "tex")
    };
    std::vector<Texture> textureBack{
        Texture(("."+bar+"res"+bar+"images"+bar+"back.png").c_str(), GL_REPEAT, GL_NEAREST, 0, "tex")
    };
    
    this->mesh=new Mesh(createPlane(textures[0].getWidth()/textures[0].getHeight(), 1.0f, 0.0f, 0.0f, 1.0f, 1.0f), planeI, textures);
    this->mesh2=new Mesh(createPlane(textureBack[0].getWidth()/textureBack[0].getHeight()*10.0f, 1.0f, 0.0f, 0.0f, 10.0f, 1.0f), planeI, textureBack);

    this->map=new Map(("."+bar+"res"+bar+"maps"+bar+"map.txt").c_str());
    this->map->setShader(this->shader);
    this->map->setCam(this->cam);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);
    //glFrontFace(GL_CCW);
}

void Game::run(){
    while(this->isRunning){
        this->render();
        this->poolEvents();
        this->update();
    }
    this->quit();
}

void Game::render(){
    int w, h;
    SDL_GetWindowSize(this->window, &w, &h);

    //window --------------------------------------------
    //SDL_GL_MakeCurrent(this->window, this->windowContext);
    
    this->cam->updateMatrixPespective(45.0f, float(w)/float(h), 0.1f, 1000.0f);
    //this->cam->updateMatrixOrtografic(4.0f, float(w)/float(h), 0.1f, 1000.0f);

    glViewport(0, 0, w, h);
    glClearColor(0.01f, 0.1f, 0.18f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //this->map->setCam(this->cam);
    this->map->render();

    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, glm::vec3(6.0f, 0.0f, 0.5f));
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    this->mesh->draw(shader, cam);
    glm::mat4 model2=glm::mat4(1.0f);
    model2=glm::translate(model2, glm::vec3(6.0f, 0.0f, 1.0f));
    model2=glm::scale(model2, glm::vec3(5.0f, 5.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model2));
    this->mesh2->draw(shader, cam);

    SDL_GL_SwapWindow(this->window);

    //debug window --------------------------------------
    /*SDL_GL_MakeCurrent(this->debug, this->windowContext);

    int dw, dh;
    SDL_GetWindowSize(this->debug, &dw, &dh);

    this->debugCam->updateMatrixPespective(45.0f, float(dw)/float(dh), 0.1f, 1000.0f);
    this->cam->updateMatrixOrtografic(4.0f, float(w)/float(h), 0.1f, 1000.0f);

    glViewport(0, 0, dw, dh);
    glClearColor(0.01f, 0.1f, 0.18f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->map->setCam(this->debugCam);
    this->map->render();

    SDL_GL_SwapWindow(this->debug);*/
}

void Game::update(){
    //this->map->setCam(this->cam);
    this->map->update(dt);
    
    //this->cam->update(this->dt, this->window);
    //this->debugCam->update(this->dt, this->debug);

    this->dt=float(SDL_GetTicks()-lastTime)/1000.0f;
    if(this->lastTime==0){
        this->dt=0.0f;
    }
    this->lastTime=SDL_GetTicks();
}

void Game::quit(){
    SDL_DestroyWindow(this->window);
    //SDL_DestroyWindow(this->debug);
    SDL_Quit();
}

void Game::poolEvents(){
    while(SDL_PollEvent(&this->event)){
        //if(this->event.window.event==SDL_WINDOWEVENT_CLOSE){//this->event.window.windowID==SDL_GetWindowID(this->window)
            //this->isRunning=false;
        //}

        if(this->event.type==SDL_QUIT){
            this->isRunning=false;
        }
    }
}