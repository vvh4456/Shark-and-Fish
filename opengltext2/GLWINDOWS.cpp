#include "GLWINDOWS.h"
void framebuffer_size_callback(GLFWwindow*, int, int);
void defaultInputHandleF(ZWindow id) {
	if (glfwGetKey(id, GLFW_KEY_A) == GLFW_PRESS)
		glfwSetWindowShouldClose(id,GL_TRUE);
};
void defineKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
ZWindow GLWINDOWS::getWindowID()
{
	return windowid;
}

ZWindow GLWINDOWS::createWindow(std::string winTitle)
{

	windowid = glfwCreateWindow(WINDOW_WIDTH_DEFINE,
								WINDOW_HEIGHT_DEFINE,
								winTitle.c_str(), NULL, NULL);
	if (windowid == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(windowid);
	glfwSetFramebufferSizeCallback(windowid, framebuffer_size_callback);
	return windowid;
}

void GLWINDOWS::processInput()
{
	if(inputHandleFun!=nullptr)
	inputHandleFun(this->windowid);
	else defaultInputHandleF(this->windowid);
}

void GLWINDOWS::setProcessInputFun(proceinputfunction fun)
{
	this->inputHandleFun = fun;
}

void GLWINDOWS::setErrorCallBack()
{
}

void GLWINDOWS::setMouseButtonCallBack()
{
}

void GLWINDOWS::setKeyCallBack()
{
	glfwSetKeyCallback(windowid,defineKeyCallback);
}

void GLWINDOWS::setCursorPositionCallBack()
{
}

void GLWINDOWS::setScrollCallBack()
{

	

}

GLWINDOWS::GLWINDOWS()
{



}


GLWINDOWS::~GLWINDOWS()
{



}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void defineKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window,GLFW_TRUE);


}
