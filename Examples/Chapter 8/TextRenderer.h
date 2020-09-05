#pragma once

#include <map>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <ft2build.h>

#include "Dependencies/glm/glm/glm.hpp"
#include "Dependencies/glm/glm/gtc/matrix_transform.hpp"
#include "Dependencies/glm/glm/gtc/type_ptr.hpp"
#include FT_FREETYPE_H  

struct Character
{
	GLuint TextureID;
	glm::ivec2 Size;
	glm::ivec2 Bearing;
	GLuint Advance;
};

class TextRenderer
{
private:
	std::string text;
	GLfloat scale;
	glm::vec3 color;
	glm::vec2 position;
	GLuint VAO, VBO, program;
	std::map<GLchar, Character> Characters;

public:
	TextRenderer(std::string text, std::string font, int size, glm::vec3 color, GLuint program);
	~TextRenderer();

	void draw();
	void setPosition(glm::vec2 _position);
	void setText(std::string _text);
};