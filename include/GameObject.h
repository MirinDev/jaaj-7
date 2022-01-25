#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Mesh.h>

class GameObject{
    public:
        GameObject(Shader *shader, Cam *cam){};
        virtual void update(float dt){};
        virtual void render(){};
        virtual void physics(std::vector<GameObject*> objs, float dt){};
        bool colision(float x, float y, float w, float h){
            return (x+w/2.0f>this->pos.x-this->size.x/2.0f && x-w/2.0f<this->pos.x+this->size.x/2.0f && y+h/2.0f>this->pos.y-this->size.y/2.0f && y-h/2.0f<this->pos.y+this->size.y/2.0f);
        }
        glm::vec4 getArgs(){
            return glm::vec4(this->pos.x, this->pos.y, this->size.x, this->size.y);
        }
        std::string type="none";
    protected:
        glm::vec3 pos=glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 size=glm::vec3(1.0f, 1.0f, 1.0f);
};

#endif