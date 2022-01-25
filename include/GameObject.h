#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Mesh.h>

class GameObject{
    public:
        GameObject(Shader *shader, Cam *cam){};
        virtual void update(float dt){};
        virtual void render(){};
        virtual void physics(std::vector<GameObject*> objs){};
    protected:
        glm::vec3 pos=glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif