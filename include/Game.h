#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <Mesh.h>
#include <Plane.h>
#include <parent.h>

#include <SpriteSheet.h>

#include <Player.h>

class Game{
    public:
        Game(int width, int height, const char *title, bool resize);
        void run();
        void render();
        void update();
        void quit();
        void poolEvents();
    private:
        SDL_Window *window;
        SDL_Event event;
        bool isRunning=true;

        Cam *cam;
        Shader *shader;

        Mesh *mesh;

        Player *player;

        float dt=0.0f;
        float lastTime=0.0f;
};

#endif