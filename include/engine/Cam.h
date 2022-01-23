#ifndef CAM_H
#define CAM_H
#include <iostream>
#include <math.h>

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <Shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <Key.h>

class Cam{
    public:
        glm::vec3 pos=glm::vec3(0.0f, 0.0f, -2.0f);
        
        Cam(){
            //
        }

        void update(float dt, SDL_Window *window){
            if(keys[SDL_SCANCODE_D]){
                this->pos+=this->spd*glm::normalize(glm::cross(front, up))*dt;
            }
            if(keys[SDL_SCANCODE_A]){
                this->pos-=this->spd*glm::normalize(glm::cross(front, up))*dt;
            }
            if(keys[SDL_SCANCODE_W]){
                this->pos+=this->spd*front*dt;
            }
            if(keys[SDL_SCANCODE_S]){
                this->pos-=this->spd*this->front*dt;
            }
            if(keys[SDL_SCANCODE_SPACE]){
                this->pos+=this->spd*this->up*dt;
            }
            if(keys[SDL_SCANCODE_LSHIFT]){
                this->pos-=this->spd*this->up*dt;
            }

            int w, h;
            SDL_GetWindowSize(window, &w, &h);
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(this->first){
                x=w/2;
                y=h/2;
                this->first=false;
            }

            float sx=(float(x)-float(w)/2.0f)/float(w)*sens, sy=(float(y)-float(h)/2.0f)/float(h)*sens;

            glm::vec3 newFront=glm::rotate(this->front, glm::radians(-sy), glm::normalize(glm::cross(front, up)));

            if(std::abs(glm::angle(newFront, this->up)-glm::radians(90.0f))<=glm::radians(89.0f)){
                this->front=newFront;
            }
            SDL_WarpMouseInWindow(window, w/2, h/2);

            this->front=glm::rotate(this->front, glm::radians(-sx), this->up);
        }

        void updateMatrixPespective(float fov, float aspect, float near, float far){
            this->proj=glm::perspective(glm::radians(fov), aspect, near, far);
        }
        void updateMatrixOrtografic(float scale, float aspect, float near, float far){
            this->proj=glm::ortho(-aspect*scale, aspect*scale, -1.0f*scale, 1.0f*scale, near, far);
        }

        void use(Shader *shader, const char *unit){
            glm::mat4 view=glm::mat4(1.0f);
            view=glm::lookAt(this->pos, this->pos+this->front, this->up);
            
            glUniformMatrix4fv(glGetUniformLocation(shader->getID(), unit), 1, GL_FALSE, glm::value_ptr(this->proj*view));
        }
    private:
        glm::mat4 proj=glm::mat4(1.0f);
        glm::vec3 front=glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 up=glm::vec3(0.0f, 1.0f, 0.0f);
        float spd=4.0f;
        float sens=100.0f;
        bool first=true;
};

#endif