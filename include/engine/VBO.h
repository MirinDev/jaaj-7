#ifndef VBO_H
#define VBO_H
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>

struct Vertex{
    glm::vec3 pos;
	glm::vec2 Uv;
	glm::vec3 normal;
};

class VBO{
    public:
        VBO(std::vector<Vertex> &vertices){
            glGenBuffers(1, &this->ID);
            glBindBuffer(GL_ARRAY_BUFFER, this->ID);
            glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
        }
        void bind(){
            glBindBuffer(GL_ARRAY_BUFFER, this->ID);
        }
        void unbind(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        void del(){
            glDeleteBuffers(1, &this->ID);
        }
    private:
        GLuint ID;
};

#endif