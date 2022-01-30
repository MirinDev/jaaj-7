#ifndef MAP_H
#define MAP_H
#include <Player.h>
#include <Block.h>
#include <file.h>

class Map{
    public:
        Map(const char *file);
        void render();
        void update(float dt);
        void setCam(Cam *cam);
        void setShader(Shader *shader);
    private:
        std::vector<GameObject*> objs;
};

#endif