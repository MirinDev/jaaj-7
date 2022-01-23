#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

static std::string openFile(const char *file){
	std::ifstream in(file, std::ios::binary);
	if(in){
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

class Shader{
    public:
        Shader(const char *fragmentShaderFile, const char *vertexShaderFile){
            std::string fragment=openFile(vertexShaderFile);
            std::string vertex=openFile(fragmentShaderFile);

            const char *vertexShaderSource=fragment.c_str();
            const char *fragmentShaderSource=vertex.c_str();
            
            GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);

            GLuint fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);

            glAttachShader(this->ID, vertexShader);
            glAttachShader(this->ID, fragmentShader);
            glLinkProgram(this->ID);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
        }
        void use(){
            glUseProgram(this->ID);
        }
        void del(){
            glDeleteProgram(this->ID);
        }
        GLuint getID(){return this->ID;};
    private:
        GLuint ID=glCreateProgram();
};

#endif