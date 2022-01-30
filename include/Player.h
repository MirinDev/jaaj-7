#ifndef PLAYER_H
#define PLAYER_H
#include <GameObject.h>
#include <file.h>
#include <SpriteSheet.h>

#include <Key.h>

class Player:public GameObject{
    public:
        Player(float x, float y);
        void render() override;
        void update(float dt) override;
        void physics(std::vector<GameObject*> objs, float dt) override;
    private:
        void move(float dt);
        void moveCam();
        void updateState();

        SpriteSheet *idle;
        SpriteSheet *run;

        std::string state="idle";

        float spd=6.0f;
        float grv=8.0f;
        int jump=0;
        int maxJump=1;
        float jumpForce=14.0f;
        float timeForJump=0.0f;
        float defaultTimeForJump=0.2;

        float hspd=0.0f;
        float vspd=0.0f;
        bool jumpp=false;

        bool fliph=false;

        bool seramovecam=true;
};

#endif