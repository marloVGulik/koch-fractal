#include "main.h"

int main() {
	std::cout << "Starting...\n";
	
	Renderer::startRendering();
	std::cin.ignore();
	//Renderer::_renderer_thread.join();
	Renderer::stopRendering();
	std::cout << Renderer::frameCounter << "\n";
	std::cout << "Program ended with code 0! Success!" << std::endl;
	return 0;
}