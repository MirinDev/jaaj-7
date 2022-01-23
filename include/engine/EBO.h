#ifndef EBO_H
#define EBO_H
#include <iostream>
#include <vector>
#include <glad/glad.h>

class EBO{
    public:
        EBO(std::vector<GLuint> &indices){
            glGenBuffers(1, &this->ID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
        }
        void bind(){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
        }
        void unbind(){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        void del(){
            glDeleteBuffers(1, &this->ID);
        }
    private:
        GLuint ID;
};

#endif