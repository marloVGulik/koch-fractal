#pragma once
#include "headers.h"

static class Renderer {
public:
	static unsigned int frameCounter;
	static bool isActive;
	static std::thread _renderer_thread;
	static GLFWwindow* window;
	static GLFWmonitor* monitor;

	static int width;
	static int height;

	static void startRendering();
	static void stopRendering();

	static void main();
};

