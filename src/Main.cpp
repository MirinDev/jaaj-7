#include <Game.h>

#define width 1280
#define height 720

Game *game;

int main(){
    game=new Game(width, height, "mini", true);
    game->run();

    return 0;
}

int WinMain(){
    return main();
}