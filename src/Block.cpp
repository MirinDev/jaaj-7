#include <Block.h>

Block::Block(Shader *shader, Cam *cam, float x, float y):GameObject(shader, cam){
    this->shader=shader;
    this->cam=cam;

    std::vector<Texture> textures{
        Texture(("."+bar+"res"+bar+"block.png").c_str(), GL_CLAMP_TO_BORDER, GL_NEAREST, 0, "tex")
    };

    this->mesh=new Mesh(createPlane(1.0f, 1.0f, 0.0f, 0.0f, 1.0f/3.0f, 1.0f/3.0f), planeI, textures);
    this->pos.x=x;
    this->pos.y=y;
}

void Block::render(){
    glm::mat4 model=glm::mat4(1.0f);
    model=glm::translate(model, glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    this->mesh->draw(shader, cam);
}