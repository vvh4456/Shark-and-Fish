#pragma once
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"


typedef GLFWwindow* ZWindow;
typedef void(*proceinputfunction)(ZWindow);
class GLWINDOWS
{
private:
	 ZWindow windowid;
	 proceinputfunction inputHandleFun=nullptr;
public:
	ZWindow getWindowID();
	ZWindow createWindow(std::string);
	void processInput();
	void setProcessInputFun(proceinputfunction);
	void setErrorCallBack();
	void setMouseButtonCallBack();
	void setKeyCallBack();
	void setCursorPositionCallBack();
	void setScrollCallBack();
	GLWINDOWS();
	~GLWINDOWS();
};
#define WINDOW_WIDTH_DEFINE 800
#define WINDOW_HEIGHT_DEFINE 640