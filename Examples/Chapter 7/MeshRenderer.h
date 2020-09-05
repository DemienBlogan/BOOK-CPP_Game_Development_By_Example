#pragma once

#include <vector>
#include <GL/glew.h>
#include <btBulletDynamicsCommon.h>

#include "Camera.h"
#include "LightRenderer.h"
#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/matrix_transform.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"

class MeshRenderer
{
private:
	std::vector<Vertex>vertices;
	std::vector<GLuint>indices;
	glm::mat4 modelMatrix;
	Camera* camera;
	glm::vec3 position, scale;
	GLuint vao, vbo, ebo, texture, program;
	btRigidBody* rigidBody;

public:
	MeshRenderer(MeshType modelType, Camera* _camera, btRigidBody* _rigidBody);
	~MeshRenderer();

	void draw();
	void setPosition(glm::vec3 _position);
	void setScale(glm::vec3 _scale);
	void setProgram(GLuint _program);
	void setTexture(GLuint _textureID);
};