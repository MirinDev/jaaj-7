#include <Block.h>

Block::Block(Shader *shader, Cam *cam, float x, float y, int tile):GameObject(shader, cam){
    this->shader=shader;
    this->cam=cam;

    std::vector<Texture> textures{
        Texture(("."+bar+"res"+bar+"block.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };

    std::vector<Vertex> plane;
    if(tile==0){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, (1.0f/3.0f)*2.0f, 1.0f, 1.0f);
    }
    if(tile==1){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f), (1.0f/3.0f)*2.0f, (1.0f/3.0f)*2.0f, 1.0f);
    }
    if(tile==2){
        plane=createPlane(1.0f, 1.0f, 0.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f);
    }
    
    if(tile==3){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f, (1.0f/3.0f)*2.0f);
    }
    if(tile==4){
        plane=createPlane(1.0f, 1.0f, 1.0f/3.0f, 1.0f/3.0f, (1.0f/3.0f)*2.0f, (1.0f/3.0f)*2.0f);
    }
    if(tile==5){
        plane=createPlane(1.0f, 1.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f, (1.0f/3.0f)*2.0f);
    }

    if(tile==6){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, 0.0f, 1.0f, 1.0f/3.0f);
    }
    if(tile==7){
        plane=createPlane(1.0f, 1.0f, 1.0f/3.0f, 0.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f);
    }

    this->mesh=new Mesh(plane, planeI, textures);
    this->pos.x=x;
    this->pos.y=y;
    this->type="block";
}

void Block::render(){
    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, this->pos);
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    this->mesh->draw(shader, cam);
}