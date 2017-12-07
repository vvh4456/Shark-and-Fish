#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <gl/GL.h>
//一旦创建这个类的实例就表示使用opengl来创建窗口等
class ZGraph_gl
{	
public:

	ZGraph_gl();
	~ZGraph_gl();
	void createWindow(std::string WinName,int,int);
	int createProgram();
	int createShader(std::string,GLenum);
	int deleteShader(int);
	int attachShader(int program,int shader);
	int linkProgram(int program);
	int deleteProgram(int program);
	bool useProgram(int program);
	void setFloat(int program, const std::string &name, float value) const;
	int CreateVAO();
	int setVBO(float*,int);
	int setEVO(int *,int);
	GLFWwindow* getWindowID()const;
	int DrewLine(float x,float y,float x2,float y2);
	int DrewRect(float x, float y, float x2, float y2, int a, int b, int g);
	int useVector(int VectorID);
	int clear();
	int done();
	int pri();
};

#ifdef _WIN32
typedef ZGraph_gl ZGraph;
#endif
#ifdef __linux

#endif