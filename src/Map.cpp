#include <Map.h>

Map::Map(const char *file, Shader *shader, Cam *cam){
    std::string result=openFile(file);
    int x=0;
    int y=0;
    for(int i=0; i<result.size(); i++){
        std::string process(1, result[i]);
        if(process=="1"){
            this->objs.push_back((new Player(shader, cam, x, -y+5)));
        }
        if(process=="2"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 0)));
        }
        if(process=="3"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 1)));
        }
        if(process=="4"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 2)));
        }
        if(process=="5"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 3)));
        }
        if(process=="6"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 4)));
        }
        if(process=="7"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 5)));
        }
        if(process=="8"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 6)));
        }
        if(process=="9"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 7)));
        }

        if(process=="4"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 2)));
        }
        
        if(process=="\n"){
            x=0;
            y++;
        }
        if(process==" "){
            x++;
        }
    }
}

void Map::render(){
    for(int i=0; i<objs.size(); i++){
        this->objs[i]->render();
    }
}

void Map::update(float dt){
    for(int i=0; i<objs.size(); i++){
        this->objs[i]->update(dt);

        this->objs[i]->physics(objs);
    }
}