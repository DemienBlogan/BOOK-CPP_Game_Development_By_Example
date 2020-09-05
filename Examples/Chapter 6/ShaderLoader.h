#pragma once

#include <iostream>
#include <GL/glew.h>

class ShaderLoader
{
private:
	std::string readShader(const char* filename);
	GLuint createShader(GLenum shaderType, std::string source, const char* shaderName);

public:
	GLuint createProgram(const char* vertexShaderFilename, const char* fragmentShaderFilename);
};