#include <iostream>
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "ZGraph.h"
#include "GLWINDOWS.H"
//#pragma comment(lib,"glfw3.lib")
int main()
{
	GLWINDOWS testa, testb;
	ZGraph::Init();
	ZGraph testc, testd;
	testc.useThisWindow(testa.createWindow("hello"));
	//testd.useThisWindow(testb.createWindow("windows"));
	//abort();
	testa.setKeyCallBack();
	while (TRUE)
	{
		if (glfwWindowShouldClose(testa.getWindowID())) { std::cout << "should close"; break; }
		//testa.processInput();
		testc.clear();
		testc.DrewRect(-0.2,-0.4,0.6,0.7,0,100,200);
		testc.done();
		Sleep(500);
	}
	glfwTerminate();
	return 0;
}




//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//														 // glfw window creation
//														 // --------------------
//	GLFWwindow* window = glfwCreateWindow(800, 640, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		// -----
//		//processInput(window);
//
//		// render
//		// ------
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//	
void cursor_position_callback(GLFWwindow* window, double x, double y)
{
	float xpos, ypos;
	int width = 800;
	int height = 640;
	printf("Mouse position move to [%d:%d]", int(x), int(y));
	xpos = float((x - width / 2) / width) * 2;
	ypos = float(0 - (y - height / 2) / height) * 2;
	return;
}