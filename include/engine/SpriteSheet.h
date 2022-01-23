#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H
#include <glad/glad.h>
#include <Mesh.h>
#include <Plane.h>
#include <iostream>

struct Sheet{
    int frameXPosition;
    int frameYPosition;
    int frameWidth;
    int frameHeight;
    float timeForFrame;
};


class SpriteSheet{
    public:
        SpriteSheet(Shader *shader, Cam *cam, std::vector<Texture> textures, Sheet sheet){
            this->shader=shader;
            this->textures=textures;
            this->sheet=sheet;
            this->cam=cam;
        }
        void render(glm::mat4 model){
            float sw=1.0f/(this->textures[0].getWidth()/this->sheet.frameWidth);
            float sh=1.0f/(this->textures[0].getHeight()/this->sheet.frameHeight);

            Mesh mesh(createPlane(1.0f, 1.0f, this->sheet.frameXPosition*sw, this->sheet.frameYPosition*sh, (this->sheet.frameXPosition+1)*sw, (this->sheet.frameYPosition+1)*sh), planeI, textures);
            this->shader->use();
            glUniformMatrix4fv(glGetUniformLocation(this->shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
            mesh.draw(this->shader, this->cam);
        }
        void update(float dt){
            if(this->time>=this->sheet.timeForFrame){
                this->sheet.frameXPosition++;
                this->time=0.0f;
            }
            if(this->sheet.frameXPosition>=this->textures[0].getWidth()/this->sheet.frameWidth){
                this->sheet.frameXPosition=0;
            }
            this->time+=dt;
        }
    private:
        Shader *shader;
        Cam *cam;
        Sheet sheet;
        std::vector<Texture> textures;

        float time=0.0f;
};

#endif