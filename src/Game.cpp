#include <Game.h>

Game::Game(int width, int height, const char *title, bool resize){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    this->window=SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | (resize ? SDL_WINDOW_RESIZABLE : SDL_WINDOW_SHOWN));
    SDL_GLContext context=SDL_GL_CreateContext(window);

    gladLoadGL();

    this->cam=new Cam();
    this->cam->pos.z=-4.0f;
    this->shader=new Shader(("."+bar+"res"+bar+"image.frag").c_str(), ("."+bar+"res"+bar+"image.vert").c_str());

    std::vector<Texture> texturesRun{
        Texture(("."+bar+"res"+bar+"run.png").c_str(), GL_REPEAT, GL_NEAREST, 0, "tex")
    };
    std::vector<Texture> texturesIdle{
        Texture(("."+bar+"res"+bar+"idle.png").c_str(), GL_REPEAT, GL_NEAREST, 0, "tex")
    };
    std::vector<Texture> texturesBase{
        Texture(("."+bar+"res"+bar+"base.png").c_str(), GL_REPEAT, GL_NEAREST, 0, "tex")
    };

    std::vector<Texture> textures{
        Texture(("."+bar+"res"+bar+"engine.png").c_str(), GL_REPEAT, GL_LINEAR, 0, "tex")
    };
    
    this->mesh=new Mesh(createPlane(textures[0].getWidth()/textures[0].getHeight(), 1.0f, 0.0f, 0.0f, 1.0f, 1.0f), planeI, textures);

    this->objs.push_back(Player(shader, cam, 0.0f, 0.0f));
    //this->player=new Player(shader, cam, 0.0f, 0.0f);

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
    SDL_GetWindowSize(window, &w, &h);
    
    this->cam->updateMatrixPespective(45.0f, float(w)/float(h), 0.1f, 1000.0f);
    //this->cam->updateMatrixOrtografic(4.0f, float(w)/float(h), 0.1f, 1000.0f);
    
    glViewport(0, 0, w, h);
    glClearColor(0.01f, 0.1f, 0.18f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int i=0; i<this->objs.size(); i++){
        this->objs[i].render();
    }
    //this->player->render();

    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    this->mesh->draw(shader, cam);

    SDL_GL_SwapWindow(this->window);
}

void Game::update(){
    for(int i=0; i<this->objs.size(); i++){
        this->objs[i].update(dt);
    }
    //this->player->update(dt);
    
    //this->cam->update(this->dt, this->window);

    this->dt=float(SDL_GetTicks()-lastTime)/1000.0f;
    if(this->lastTime==0){
        this->dt=0.0f;
    }
    this->lastTime=SDL_GetTicks();
}

void Game::quit(){
    SDL_Quit();
}

void Game::poolEvents(){
    while(SDL_PollEvent(&this->event)){
        if(this->event.type==SDL_QUIT){
            isRunning=false;
        }
    }
}