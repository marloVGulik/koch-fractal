#include "Renderer.h"

bool Renderer::isActive = false;
std::thread Renderer::_renderer_thread;

void Renderer::startRendering() {
	Renderer::isActive = true;
	Renderer::_renderer_thread = std::thread(&Renderer::_update, 1);
}

void Renderer::stopRendering() {
	Renderer::isActive = false;
	Renderer::_renderer_thread.join();
}

void Renderer::_update(int num) {
	while(isActive) {
		std::cout << "testing " << num << "\n";
	}
}
