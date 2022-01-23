#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Mesh.h>

class GameObject{
    public:
        GameObject(Shader *shader, Cam *cam);
        virtual void update(float dt);
        virtual void render();
};

#endif