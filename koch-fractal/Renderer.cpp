#include "Renderer.h"

unsigned int Renderer::frameCounter = 0;
bool Renderer::isActive = false;

int Renderer::height = 600;
int Renderer::width = 800;

GLFWwindow* Renderer::window = nullptr;
GLFWmonitor* Renderer::monitor = nullptr;
//GLFWvidmode* Renderer::mode;

std::thread Renderer::_renderer_thread;

void Renderer::startRendering() { // open thread for rendering
	Renderer::isActive = true;
	Renderer::_renderer_thread = std::thread(&Renderer::main);
}

void Renderer::stopRendering() {
	std::cout << "Stopping rendering process and killing window!\n";
	Renderer::isActive = false;
	if (Renderer::_renderer_thread.joinable()) {
		Renderer::_renderer_thread.join();
	}
	glfwDestroyWindow(Renderer::window);
	Renderer::window = nullptr;
}

void Renderer::main() {// initialize openGL in this thread!
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	Renderer::window = glfwCreateWindow(Renderer::width, Renderer::height, "KOCH FRACTAL", nullptr, nullptr);
	glfwGetFramebufferSize(Renderer::window, &Renderer::width, &Renderer::height);

	if (Renderer::window == nullptr) {
		std::cout << "Error creating a window!\n";
		glfwTerminate();

		return;
	}

	glfwMakeContextCurrent(Renderer::window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing GLEW!\n";
		return;
	}
	glViewport(0, 0, Renderer::width, Renderer::height);
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // end right here :D

	while(!glfwWindowShouldClose(Renderer::window) && Renderer::window != nullptr && Renderer::isActive) { // Start rendering loop
		glfwPollEvents();

		glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw triangles here
		


		glfwSwapBuffers(Renderer::window);
		//std::cout << "Updating... ";
		Renderer::frameCounter++;
	}
	std::cout << "Stopping window!\n";
}
