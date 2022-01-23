#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec2 aUv;
layout (location=2) in vec3 aNormal;

out vec2 Uv;
out vec3 Normal;
out vec3 crntPos;

uniform mat4 cam;
uniform mat4 model;

void main(){
   crntPos=vec3(model*vec4(aPos, 1.0f));
   gl_Position=cam*vec4(crntPos, 1.0);
   Uv=aUv;
   Normal=aNormal;
}