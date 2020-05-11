#include "VAO.h"
#include <gl.h>

#include <glm/glm.hpp>

GL::VAO::VAO()
{
	glGenVertexArrays(1, &mVao);
	bind();
}


void GL::VAO::bind()
{
	glBindVertexArray(mVao);
}

/**
 * \brief ������ �����. ����� ���������� ���������, ��� �� ������� �������
 *		  ��� ������ ������� GL::VAO::indices.
 *		  
 * \param type ��������, ������� �� ������. �� ��������� - ������������.
 *	      - GL_TRIANGLES
 *	      - GL_TRIANGLE_STRIP
 *	      - GL_LINES
 *	      - GL_LINE_STRIP
 *	      - GL_POINTS
 */
void GL::VAO::draw(unsigned type)
{
	assert(mIndicesBuffer != 0);
	bind();
	for (size_t i = 0; i < mBuffers.size(); ++i)
	{
		glEnableVertexAttribArray(i);
	}
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesBuffer);
	glDrawElements(type, mIndicesCount, GL_UNSIGNED_INT, nullptr);
	
	for (size_t i = 0; i < mBuffers.size(); ++i)
	{
		glDisableVertexAttribArray(i);
	}
}

/**
 * \brief 1-������������ ������
 * \param data 
 */
void GL::VAO::addVertexBufferObject(const std::vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 1, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

/**
 * \brief 2-������������ ������
 * \param data 
 */
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec2>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}
/**
 * \brief 3-������������ ������
 * \param data 
 */
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec3>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}
/**
 * \brief 4-������������ ������
 * \param data 
 */
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec4>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

/**
 * \brief �������� ����� ��������
 * \param data 
 */
void GL::VAO::addIndices(const std::vector<unsigned>& data)
{
	assert(mIndicesBuffer == 0); // �� �� ����� ������� ��� ���� �����

	mIndicesCount = data.size();
	
	glGenBuffers(1, &mIndicesBuffer);

	// �������� ��������, ��� �� ���������� �� GL_ARRAY_BUFFER, � GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned), data.data(), GL_STATIC_DRAW);
}

GL::VAO::~VAO()
{
	glDeleteBuffers(mBuffers.size(), mBuffers.data());
	glDeleteBuffers(1, &mIndicesBuffer);
	glDeleteVertexArrays(1, &mVao);
}
