#ifndef PLANE_H
#define PLANE_H
#include <Mesh.h>

static std::vector<Vertex> createPlane(float w, float h, float repeatx, float repeaty, float repeatw, float repeath){
    return std::vector<Vertex>{
        Vertex{glm::vec3(-w/2.0f, -h/2.0f, 0.0f), glm::vec2(repeatw, repeaty), glm::vec3(0.0f, 0.0f, -1.0f)},
        Vertex{glm::vec3(w/2.0f, -h/2.0f, 0.0f), glm::vec2(repeatx, repeaty), glm::vec3(0.0f, 0.0f, -1.0f)},
        Vertex{glm::vec3(w/2.0f, h/2.0f, 0.0f), glm::vec2(repeatx, repeath), glm::vec3(0.0f, 0.0f, -1.0f)},
        Vertex{glm::vec3(-w/2.0f, h/2.0f, 0.0f), glm::vec2(repeatw, repeath), glm::vec3(0.0f, 0.0f, -1.0f)},
    };
}

static std::vector<Vertex> planeV{
    Vertex{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
};

static std::vector<GLuint> planeI{
    0, 1, 2,
    2, 3, 0
};

#endif