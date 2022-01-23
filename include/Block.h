#ifndef BLOCK_H
#define BLOCK_H
#include <GameObject.h>
#include <Plane.h>

class Block: public GameObject{
    public:
        Block(Shader *shader, Cam *cam);
        void render() override;
    private:
        Mesh *mesh;
        Shader *shader;
        Cam *cam;
};

#endif