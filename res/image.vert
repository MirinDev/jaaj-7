#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec2 aUv;

uniform mat4 cam;
uniform mat4 model;

out vec2 Uv;

void main(){
   gl_Position=cam*model*vec4(aPos, 1.0f);
   Uv=aUv;
}