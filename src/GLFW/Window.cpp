#include <gl.h>

#include "Window.h"
#include <stdexcept>
#include "GL/VAO.h"
#include <GLFW/glfw3.h>
#include "GL/Program.h"
#include "GL/Texture.h"
#include "Util/Image.h"


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
		{-0.5f, 0.5f, 0.f},
		{-0.5f, -0.5f, 0.f},
		{0.5f, 0.5f, 0.f},
		{0.5f, -0.5f, 0.f},
	});

	// 2х компонентный массив
	// неявно задаём трёхкомпонетные векторы
	// UV-координаты
	// (см. 5 туториал)
	vao.addVertexBufferObject({
		{0, 1},
		{0, 0},
		{1, 1},
		{1, 0},
	});

	// индексы (см. 4 туториал)
	vao.addIndices({
		0, 1, 2,
		2, 1, 3
	});

	GL::Program first("first");
	// название атрибута здесь должно совпадать с шейдером
	first.bindAttribute(0, "position");
	first.bindAttribute(1, "uv");
	first.link();

	first.use();

	GL::Texture texture;
	Image image = Image::loadFromFile("dirt.png");
	texture.setImage(image);
	
	while (!glfwWindowShouldClose(mWindow))
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		texture.bind();
		vao.draw();
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}
}
