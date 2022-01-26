#version 330 core

out vec4 FragColor;

uniform sampler2D tex;
uniform float time=1.0f;

in vec2 Uv;

void main(){
   if(texture(tex, Uv).a<0.1f){
       discard;
   }
   FragColor=vec4(texture(tex, Uv).xyz, time);
}