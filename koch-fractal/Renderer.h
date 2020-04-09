#pragma once
#include "headers.h"

static class Renderer {
public:
	static bool isActive;
	static std::thread _renderer_thread;


	static void startRendering();
	static void stopRendering();

	static void _update(int num);
};

