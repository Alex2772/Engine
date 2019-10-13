#include <iostream>

#include "GLFW/GLFW.h"
#include "GLFW/Window.h"

int main()
{
	try {
		GLFW glfw;
		Window w("Engine", 854, 500);
		w.loop();
	} catch (const std::runtime_error& e)
	{
		std::cout << "EXCEPTION: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
