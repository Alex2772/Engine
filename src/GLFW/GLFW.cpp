#include "GLFW.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

GLFW::GLFW()
{
	if (!glfwInit())
	{
		throw std::runtime_error("Could not initialize GLFW");
	}

	// зададим требуемую версию OpenGL. если требуемая версия не поддерживается, то создать окно не получится
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL X.3

	// профиль OpenGL. выставляем нормальный режим, а не режим совместимости
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFW::~GLFW()
{
	glfwTerminate();
}
