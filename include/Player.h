#ifndef PLAYER_H
#define PLAYER_H
#include <Mesh.h>
#include <parent.h>
#include <SpriteSheet.h>

#include <Key.h>

class Player{
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
        glm::vec3 pos=glm::vec3(0.0f, 0.0f, 0.0f);
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