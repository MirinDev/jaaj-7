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
        if(process=="3"){
            this->objs.push_back((new Block(shader, cam, x, -y+5, 1)));
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
    }
}