#include <Block.h>
#include <SpriteSheet.h>

Block::Block(Shader *shader, Cam *cam, float x, float y, int tile):GameObject(shader, cam){
    this->shader=shader;
    this->cam=cam;

    std::vector<Texture> textures{
        Texture(("."+bar+"res"+bar+"images"+bar+"block.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };
    std::vector<Texture> texturesGram{
        Texture(("."+bar+"res"+bar+"images"+bar+"grama.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };

    std::vector<Vertex> plane;
    if(tile==0){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    if(tile==1){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f), (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f/3.0f);
        this->gram=true;
    }
    if(tile==2){
        plane=createPlane(1.0f, 1.0f, 0.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    
    if(tile==3){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, 1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    if(tile==4){
        plane=createPlane(1.0f, 1.0f, 1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    if(tile==5){
        plane=createPlane(1.0f, 1.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
    }

    if(tile==6){
        plane=createPlane(1.0f, 1.0f, (1.0f/3.0f)*2.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    if(tile==7){
        plane=createPlane(1.0f, 1.0f, 1.0f/3.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f);
    }
    if(tile==8){
        plane=createPlane(1.0f, 1.0f, 0.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f);
    }

    this->mesh=new Mesh(plane, planeI, textures);
    this->grama=new SpriteSheet(shader, cam, texturesGram, Sheet{0, 0, 32, 32, 0.25f});
    this->pos.x=x;
    this->pos.y=y;

    this->type="block";
}

void Block::render(){
    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, this->pos);
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    this->mesh->draw(this->shader, this->cam);

    if(this->gram){
        glm::mat4 model2=glm::mat4(1.0f);
        model2=glm::translate(model2, this->pos+glm::vec3(0.0f, 0.6f, 0.1f));
        model2=glm::scale(model2, glm::vec3(0.6f, 0.6f, 0.6f));
        this->grama->render(model2);
    }
}

void Block::update(float dt){
    this->grama->update(dt);
}