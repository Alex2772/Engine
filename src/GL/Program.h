#pragma once
#include <string>
#include "gl.h"

namespace GL {
	class Program
	{
	private:
		GLuint mProgram;
		GLuint mVertexShader;
		GLuint mFragmentShader;

		GLuint loadShader(const std::string& path, GLenum shaderType);

		GLint getLocation(const std::string& name);
	public:
		Program(const std::string& name);
		~Program();

		void link();

		void bindAttribute(GLuint index, const std::string& name);
		void use();

		void setFloat(const std::string& name, float value);
	};
}
