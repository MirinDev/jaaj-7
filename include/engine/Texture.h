#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <std/std_image.h>
#include <Shader.h>

class Texture{
    public:
        Texture(const char *file, GLenum repeat, GLenum buffer, GLuint slot, const char *type){
            this->slot=slot;
            this->type=type;
            glGenTextures(1, &ID);
            glActiveTexture(GL_TEXTURE0+this->slot);
            glBindTexture(GL_TEXTURE_2D, ID);

            stbi_set_flip_vertically_on_load(true);
            int nrChannels;
            unsigned char *data=stbi_load(file, &width, &height, &nrChannels, 0);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeat);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeat);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, buffer);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, buffer);
 
            
            GLenum format;
            if(nrChannels==4){
                format=GL_RGBA;
            }
            if(nrChannels==3){
                format=GL_RGB;
            }
            if(nrChannels==1){
                format=GL_RGB;
            }

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(data);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
        void bind(){
	        glActiveTexture(GL_TEXTURE0+this->slot);
            glBindTexture(GL_TEXTURE_2D, this->ID);
        }
        void unbind(){
    	    glBindTexture(GL_TEXTURE_2D, 0);
        }
        void del(){
	        glDeleteTextures(1, &this->ID);
        }
        void alocShader(Shader *shader){
            shader->use();
            glUniform1i(glGetUniformLocation(shader->getID(), this->type), this->slot);
        }
        int getWidth(){return this->width;};
        int getHeight(){return this->height;};
    private:
        GLuint ID;
        GLuint slot;
        const char *type;
        int width, height;
};

#endif