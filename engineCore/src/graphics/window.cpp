#include "window.h"


namespace engine {	namespace graphics {
	//Non-Member Declarations
	void windowResize(GLFWwindow *window, int width, int height);


	Window::Window(int width, int height, const char *name)
	{
		m_Height = height;
		m_Width = width;
		m_Name = name;

		if (!init())
		{
			glfwTerminate();
		}

		for (int i = 0; i < KEYCOUNT; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MOUSECOUNT; i++)
		{
			m_MouseButtons[i] = false;
		}

	}

	Window::~Window()
	{
		glfwTerminate();
	}
	
	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name,NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		if (glewInit() != GLEW_OK) //Must happen after glfwMakeContext 
		{
			std::cout << "Failed to initialize GLEW!" << std::endl;
			return false;
		}



		return true;
	}

	bool Window::isKeyPressed(unsigned int keyCode) const
	{
		if (keyCode >= KEYCOUNT)
		{
			return false;
		}
		return m_Keys[keyCode];
	}
	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		if (button >= MOUSECOUNT)
		{
			return false;
		}
		return m_MouseButtons[button];
	}

	void Window::getMousePosition(double &x, double &y) const
	{
		x = m_X;
		y = m_Y;
	}
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() 
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	

	//Non-Memeber Functions
	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		if (action != GLFW_RELEASE)
		{
			win->m_Keys[key] = true;
		}
		

	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->m_X = xpos;
		win->m_Y = ypos;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		if (action != GLFW_RELEASE)
		{
			win->m_MouseButtons[button] = true;
		}
		
	}
}}