#include <gl.h>

#include "Window.h"
#include <stdexcept>
#include "GL/VAO.h"
#include <GLFW/glfw3.h>
#include "GL/Program.h"


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

	// 3х компонентный массив
	// неявно задаём трёхкомпонетные векторы
	// вершины
	vao.addVertexBufferObject({
		{0, 0.5f, 0},
		{-0.5f, -0.5f, 0},
		{0.5f, -0.5f, 0}
	});

	// 3х компонентный массив
	// неявно задаём трёхкомпонетные векторы
	// цвета
	vao.addVertexBufferObject({
		{1, 0, 0}, // красный
		{0, 0, 1}, // синий
		{0, 1, 0} // зелёный
	});

	GL::Program first("first");
	// название атрибута здесь должно совпадать с шейдером
	first.bindAttribute(0, "position");
	first.bindAttribute(1, "color");
	first.link();

	first.use();

	float anim = 0.f;
	while (!glfwWindowShouldClose(mWindow))
	{
		anim += 0.01;
		first.setFloat("animation", glm::sin(anim) * 0.5f + 0.5f);
		
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.draw(3);
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}
