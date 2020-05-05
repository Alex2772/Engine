#include "Program.h"
#include <iterator>
#include <fstream>
#include <iostream>

GL::Program::Program(const std::string& name)
{
	mProgram = glCreateProgram();
	mVertexShader = loadShader("res/glsl/" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res/glsl/" + name + ".frag", GL_FRAGMENT_SHADER);
}

GL::Program::~Program()
{
	glDetachShader(mProgram, mVertexShader);
	glDetachShader(mProgram, mFragmentShader);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
	glDeleteProgram(mProgram);
}


/**
 * \brief Последний этап подготовки шейдерной программы. До вызова этой функции необходимо
 * объявить все атрибуты
 */
void GL::Program::link()
{
	// связываем шейдеы с программой
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);

	// линкуем
	glLinkProgram(mProgram);
}

/**
 * \brief Объявить атрибут. Вызывать строго до
 * \ref link
 */
void GL::Program::bindAttribute(GLuint index, const std::string& name)
{
	glBindAttribLocation(mProgram, index, name.c_str());
}

/**
 * \brief Активировать шейдерную программу
 */
void GL::Program::use()
{
	glUseProgram(mProgram);
}

/**
 * Загрузить юниформ
 */
void GL::Program::setFloat(const std::string& name, float value)
{
	glUniform1f(getLocation(name), value);
}


/**
 * \brief Получить ключ атрибута для glUniform
 * \param name Название атрибута
 * \return Ключ
 */
GLint GL::Program::getLocation(const std::string& name)
{
	return glGetUniformLocation(mProgram, name.c_str());
}

/**
 * \brief Загрузить шейдер из файла с заданным типом
 * \param path Путь к файлу
 * \param shaderType Тип шейдера
 * \return Хендл
 */
GLuint GL::Program::loadShader(const std::string& path, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	// загрузка кода шейдера
	// выглядит страшно, но так проще, отвечаю
	std::ifstream fis(path);
	// он посчитал, что это прототип функции (идиот просто), поэтому конструктор будет таким {}
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };

	// загрузка кода шейдера в OpenGL
	const char* c = shaderCode.c_str();
	// да, тут именно указатель на указатель, char**
	glShaderSource(shader, 1, &c, nullptr);

	// получить результат компиляции (успешно/неуспешно)
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0)
	{
		std::cout << "Failed to compile shader " << path << ":" << std::endl << buf;
	}
	
	return shader;
}
