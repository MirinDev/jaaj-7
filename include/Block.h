#ifndef BLOCK_H
#define BLOCK_H
#include <GameObject.h>
#include <Plane.h>
#include <SpriteSheet.h>

class Block: public GameObject{
    public:
        Block(float x, float y, int tile);
        void update(float dt) override;
        void render() override;
    private:
        bool gram=false;
        SpriteSheet *grama;
};

#endif