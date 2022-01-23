#include <Map.h>

Map::Map(const char *file, Shader *shader, Cam *cam){
    std::string result=openFile(file);
    int x=0;
    int y=0;
    for(int i=0; i<result.size(); i++){
        if(result[i]=="1"){
            this->objs.push_back((new Player(shader, cam, x, y)));
        }
        
        if(result[i]=="\n"){
            x=0;
            y++;
        }
        if(result[i]==" "){
            x++;
        }
    }
    
    //this->objs.push_back((new Player(shader, cam, 0.0f, 0.0f)));
    //this->objs.push_back((new Block(shader, cam, 0.0f, 1.0f)));
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