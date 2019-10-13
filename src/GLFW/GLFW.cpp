#include "GLFW.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

GLFW::GLFW()
{
	if (!glfwInit())
	{
		throw std::runtime_error("Could not initialize GLFW");
	}
}

GLFW::~GLFW()
{
	glfwTerminate();
}
