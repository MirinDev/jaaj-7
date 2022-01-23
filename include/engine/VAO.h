#ifndef VAO_H
#define VAO_H
#include <glad/glad.h>
#include <VBO.h>

class VAO{
    public:
        VAO(){
            glGenVertexArrays(1, &this->ID);
        }
        void linkVBO(VBO *vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset){
            vbo->bind();
            glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
            glEnableVertexAttribArray(layout);
            vbo->unbind();
        }
        void bind(){
            glBindVertexArray(this->ID);
        }
        void unbind(){
            glBindVertexArray(0);
        }
        void del(){
            glDeleteVertexArrays(1, &this->ID);
        }
    private:
        GLuint ID;
};

#endif