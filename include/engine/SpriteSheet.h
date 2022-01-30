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
        SpriteSheet(std::vector<Texture> textures, Sheet sheet){
            this->textures=textures;
            this->sheet=sheet;
        }
        void render(Shader *shader, Cam *cam, glm::mat4 model){
            float sw=1.0f/(this->textures[0].getWidth()/this->sheet.frameWidth);
            float sh=1.0f/(this->textures[0].getHeight()/this->sheet.frameHeight);

            Mesh mesh(createPlane(1.0f, 1.0f, this->sheet.frameXPosition*sw, this->sheet.frameYPosition*sh, sw, sh), planeI, textures);
            shader->use();
            glUniformMatrix4fv(glGetUniformLocation(shader->getID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
            mesh.draw(shader, cam);
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
        Sheet sheet;
        std::vector<Texture> textures;

        float time=0.0f;
};

#endif