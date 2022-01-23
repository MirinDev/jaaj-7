#ifndef MAP_H
#define MAP_H
#include <Player.h>
#include <Block.h>
#include <file.h>

class Map{
    public:
        Map(const char *file, Shader *shader, Cam *cam);
        void render();
        void update(float dt);
    private:
        std::vector<GameObject*> objs;
};

#endif