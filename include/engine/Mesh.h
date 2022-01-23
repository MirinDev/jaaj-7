#ifndef MESH_H
#define MESH_H
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <VAO.h>
#include <EBO.h>
#include <Cam.h>
#include <Texture.h>
#include <Shader.h>

class Mesh{
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures){
            this->vertices=vertices;
            this->indices=indices;
            this->textures=textures;

            this->vao.bind();
            VBO vbo(vertices);
            EBO ebo(indices);
            vao.linkVBO(&vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
            vao.linkVBO(&vbo, 1, 2, GL_FLOAT, sizeof(Vertex), (void*)(3*sizeof(float)));
            vao.linkVBO(&vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(5*sizeof(float)));

            this->vao.unbind();
            vbo.unbind();
            ebo.unbind();
        }
        void draw(Shader *shader, Cam *cam){
            shader->use();
            cam->use(shader, "cam");

            /*for(int i=0; i<textures.size(); i++){
                this->textures[i].alocShader(shader);
                this->textures[i].bind();
            }*/
            if(this->textures.size()>1){
                this->textures[slotSpec].alocShader(shader);
                this->textures[slotSpec].bind();
            }
            if(this->textures.size()>0){
                this->textures[slot].alocShader(shader);
                this->textures[slot].bind();
            }

            glUniform3f(glGetUniformLocation(shader->getID(), "pos"), cam->pos.x, cam->pos.y, cam->pos.z);

            this->vao.bind();
            glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
            this->vao.unbind();

            if(this->textures.size()>1){
                this->textures[slotSpec].unbind();
            }
            if(this->textures.size()>0){
                this->textures[slot].unbind();
            }
            /*for(int i=0; i<textures.size(); i++){
                this->textures[i].unbind();
            }*/
        }
        int slot=0;
        int slotSpec=1;
    private:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;

        VAO vao;
};

#endif