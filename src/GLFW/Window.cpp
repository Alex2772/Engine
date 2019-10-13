#include <gl.h>

#include "Window.h"
#include <stdexcept>
#include "GL/VAO.h"
#include <GLFW/glfw3.h>


Window::Window(const std::string& title, int width, int height)
{
	mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!mWindow)
	{
		throw std::runtime_error("Could not initialize window");
	}
	setContextCurrent();
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Could not initialize GLEW");
	}
}
Window::~Window()
{
	glfwDestroyWindow(mWindow);
}


void Window::setContextCurrent()
{
	glfwMakeContextCurrent(mWindow);
}

void Window::loop()
{

	GL::VAO vao;
	vao.addVertexBufferObject({
		0, 0.5f, 0,
		-0.5f, -0.5f, 0,
		0.5f, -0.5f, 0
	});
	while (!glfwWindowShouldClose(mWindow))
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.draw(3);
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}
