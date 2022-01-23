#include <Player.h>

float lerp(float a, float b, float f){
    return a+f*(b-a);
}

Player::Player(Shader *shader, Cam *cam, float x, float y){
    this->shader=shader;
    this->cam=cam;

    std::vector<Texture> texturesRun{
        Texture(("."+bar+"res"+bar+"run.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };
    std::vector<Texture> texturesIdle{
        Texture(("."+bar+"res"+bar+"idle.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };

    this->idle=new SpriteSheet(shader, cam, texturesIdle, Sheet{0, 0, 32, 32, 0.25f});
    this->run=new SpriteSheet(shader, cam, texturesRun, Sheet{0, 0, 32, 32, 0.1f});
}

void Player::render(){
    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, this->pos);
    if(this->fliph){
        model=glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    if(this->state=="idle"){
        this->idle->render(model);
    }
    if(this->state=="run"){
        this->run->render(model);
    }
}

void Player::update(float dt){
    this->hspd=(keys[SDL_SCANCODE_LEFT]-keys[SDL_SCANCODE_RIGHT])*this->spd;
    if(!this->jumpp && keys[SDL_SCANCODE_C]){
        if(this->jump>0){
            this->vspd=12.0f;
            this->jump--;
        }
    }
    this->jumpp=bool(keys[SDL_SCANCODE_C]);
    
    if(this->vspd>-this->grv){
        this->vspd-=1.0f;
    }

    if(this->hspd>0){
        this->fliph=true;
    }
    if(this->hspd<0){
        this->fliph=false;
    }

    this->move(dt);
    this->moveCam();
    this->updateState();

    this->idle->update(dt);
    this->run->update(dt);
}

void Player::move(float dt){
    if(this->pos.y+this->vspd*dt<-1.0f){
        this->jump=this->maxJump;
        this->vspd=0.0f;
    }

    this->pos.x+=this->hspd*dt;
    this->pos.y+=this->vspd*dt;
}

void Player::moveCam(){
    this->cam->pos.x=lerp(this->cam->pos.x, this->pos.x, 0.1f);
    this->cam->pos.y=lerp(this->cam->pos.y, this->pos.y, 0.1f);
}

void Player::updateState(){
    if(this->hspd!=0.0f){
        this->state="run";
    }else{
        this->state="idle";
    }
}