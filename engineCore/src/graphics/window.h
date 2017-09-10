#pragma once
#include <glew.h> //GLEW must be loaded before GLFW
#include<glfw3.h>
#include <iostream>



namespace engine {	namespace graphics {
#define KEYCOUNT 1024
#define MOUSECOUNT 32

	class Window
	{
	private:
		friend struct GLFWwindow;
		int m_Width, m_Height;
		const char *m_Name;
		GLFWwindow *m_Window;
		bool m_Closed;
		bool m_Keys[KEYCOUNT];
		bool m_MouseButtons[MOUSECOUNT];
		double m_X, m_Y;
	private:
		bool init();		
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	public:
		Window(int, int , const char*);
		~Window();
		void clear() const;
		void update();
		bool closed() const;
		bool isKeyPressed(unsigned int) const;
		bool isMouseButtonPressed(unsigned int) const;
		void getMousePosition(double &x, double &y) const;

	};

	







}}

