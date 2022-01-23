#version 330 core

out vec4 FragColor;

in vec2 Uv;
in vec3 Normal;
in vec3 crntPos;

uniform sampler2D tex;
uniform sampler2D texSpec;
uniform vec3 pos;

struct Light{
	vec3 pos;
	vec3 dir;
	vec4 color;
	int type;
};

uniform Light lights[]=Light[](
	Light(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 0.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f), 0)
);

float ambient=0.5f;

vec4 pointLight(vec3 position, vec4 color, float intencity){
	vec3 lightVec=position-crntPos;
	float dist=length(lightVec);
	float a=3.0f;
	float b=0.7f;
	float inten=intencity/(a*dist*dist+b*dist+1.0f);
	vec3 normal=normalize(Normal);
	vec3 lightDirection=normalize(lightVec);
	float diffuse=max(dot(normal, lightDirection), 0.0f);
	float specularLight=0.5f;
	vec3 viewDirection=normalize(pos-crntPos);
	vec3 reflectionDirection=reflect(-lightDirection, normal);
	float specAmount=pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16.0f);
	float specular=specAmount*specularLight;
	return (texture(tex, Uv)*(diffuse*inten+ambient)+texture(texSpec, Uv).r*specular*inten)*color;
}

vec4 directLight(vec3 dir, vec4 color){
	vec3 normal=normalize(Normal);
	vec3 lightDirection=normalize(dir);
	float diffuse=max(dot(normal, lightDirection), 0.0f);
	float specularLight=0.5f;
	vec3 viewDirection=normalize(pos-crntPos);
	vec3 reflectionDirection=reflect(-lightDirection, normal);
	float specAmount=pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16.0f);
	float specular=specAmount*specularLight;
	return (texture(tex, Uv)*(diffuse+ambient)+texture(texSpec, Uv).r*specular)*color;
}

vec4 spotLight(vec3 position, vec3 dir, vec4 color){
	float outerCone=0.9f;
	float innerCone=0.95f;
	vec3 normal=normalize(Normal);
	vec3 lightDirection=normalize(position-crntPos);
	float diffuse=max(dot(normal, lightDirection), 0.0f);
	float specularLight=0.5f;
	vec3 viewDirection=normalize(pos-crntPos);
	vec3 reflectionDirection=reflect(-lightDirection, normal);
	float specAmount=pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16.0f);
	float specular=specAmount*specularLight;
	float angle=dot(dir, -lightDirection);
	float inten=clamp((angle-outerCone)/(innerCone-outerCone), 0.0f, 1.0f);
	return (texture(tex, Uv)*(diffuse*inten+ambient)+texture(texSpec, Uv).r*specular*inten)*color;
}
void main(){
   if(texture(tex, Uv).a<0.1f){
       discard;
   }

	vec4 result=vec4(0.0f, 0.0f, 0.0f, 1.0f);
	for(int i=0; i<lights.length(); i++){
		if(lights[i].type==0){
			result+=directLight(lights[i].dir, lights[i].color);
		}
		if(lights[i].type==1){
			result+=pointLight(lights[i].pos, lights[i].color, 40.0f);
		}
		if(lights[i].type==2){
			result+=spotLight(lights[i].pos, lights[i].dir, lights[i].color);
		}
	}
	FragColor=result;
}