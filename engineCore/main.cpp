#include "src\graphics\window.h"
#include "src\spatial\spatial.h"

int main()
{
	using namespace engine;
	using namespace graphics;
	using namespace vectors;
	using namespace matrices;

	Window window(960, 540, "Test");
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	float arr[16] = { 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4 };

	mat4 m1(arr);
	mat4 m2(arr);
	mat4 position = mat4::translation(vec3(2, 3, 4));

	m1 *= m2;
		
	while (!window.closed())
	{
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << " " << y << std::endl;

		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(1.0f, 1.0f);
		glEnd();

		
		window.update();
	}



	return 0;
}