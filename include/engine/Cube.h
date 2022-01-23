#ifndef CUBE_H
#define CUBE_H
#include <Mesh.h>

static std::vector<Vertex> cubeV{
    //front
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 1.0f, -1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 1.0f, -1.0f)},
    //back
    Vertex{glm::vec3(-0.5f, -0.5, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, 1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 1.0f, 1.0f)},
    //top
    Vertex{glm::vec3(-0.5f, -0.5, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, -1.0f, 1.0f)},
    //down
    Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 1.0f, 1.0f)},
    //left
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, -1.0f, 1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 1.0f, 1.0f)},
    Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 1.0f, -1.0f)},
    //right
    Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, -1.0f, -1.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, -1.0f, 1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
    Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 1.0f, -1.0f)},
};

static std::vector<GLuint> cubeI{
    //front
    0, 1, 2,
    2, 3, 0,
    //back
    4, 5, 6,
    6, 7, 4,
    //top
    8, 9, 10,
    10, 11, 8,
    //down
    12, 13, 14,
    14, 15, 12,
    //left
    16, 17, 18,
    18, 19, 16,
    //right
    20, 21, 22,
    22, 23, 20
};

#endif