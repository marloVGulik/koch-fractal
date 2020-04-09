#include "main.h"

int main() {
	std::cout << "Starting...\n";

	Renderer::startRendering();
	//Renderer::isActive = false;
	std::cin.ignore();
	Renderer::stopRendering();

	std::cout << "Program ended with code 0! Success!" << std::endl;
	return 0;
}