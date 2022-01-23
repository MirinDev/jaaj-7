#include <Light.h>

/*LightObj::LightObj(Shader *shader, Cam *cam, Light light):GameObject(shader, cam){
    std::vector<Texture> textures{
        //
    };
    this->light=light;
    this->mesh=new Mesh(cubeV, cubeI, textures);
    std::cout << "\tmalha de luz criada com susseco" << std::endl;
}

void LightObj::render(){
    this->model=glm::mat4(1.0f);
    this->model=glm::translate(this->model, light.pos);
    this->model=glm::scale(this->model, glm::vec3(0.1f, 0.1f, 0.1f));
    this->drawSelf();
}

void LightObj::update(Shader *shader, int i){
    shader->use();
    std::string local="lights[";
    glUniform3f(glGetUniformLocation(shader->getID(), (local+std::to_string(i)+"].pos").c_str()), this->light.pos.x, this->light.pos.y, this->light.pos.z);
    glUniform3f(glGetUniformLocation(shader->getID(), (local+std::to_string(i)+"].dir").c_str()), this->light.dir.x, this->light.dir.y, this->light.dir.z);
    glUniform4f(glGetUniformLocation(shader->getID(), (local+std::to_string(i)+"].color").c_str()), this->light.color.x, this->light.color.y, this->light.color.z, this->light.color.w);
    glUniform1i(glGetUniformLocation(shader->getID(), (local+std::to_string(i)+"].type").c_str()), this->light.type);
}*/