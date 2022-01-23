#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.h>
#include <file.h>
#include <SpriteSheet.h>

#include <Key.h>

class Player:public GameObject{
    public:
        Player(Shader *shader, Cam *cam, float x, float y);
        void render();
        void update(float dt);
    private:
        void move(float dt);
        void moveCam();
        void updateState();
        
        Shader *shader;
        Cam *cam;

        SpriteSheet *idle;
        SpriteSheet *run;

        std::string state="idle";
        float spd=6.0f;
        float grv=6.0f;
        int jump=0;
        int maxJump=2;

        float hspd=0.0f;
        float vspd=0.0f;
        bool jumpp=false;

        bool fliph=false;
};

#endif