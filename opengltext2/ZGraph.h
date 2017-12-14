#pragma once
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
class ZGraph_gl
{	
	GLFWwindow* window;
private:
	static int createProgram();
	static int createShader(std::string,GLenum);
	static int deleteShader(int);
	static int attachShader(int program,int shader);
	static int linkProgram(int program);
	static int deleteProgram(int program);
	static bool useProgram(int program);
	static void setFloat(int program, const std::string &name, float value);
	static int CreateVAO();
	static int setVBO(float*,int);
	static int setEBO(int *,int,int);
	static int useVector(int VectorID);
	
	static int privatefun();
public:
	ZGraph_gl();
	~ZGraph_gl();
	static void Init();
	void useThisWindow(GLFWwindow*);
	static int clear();
	int DrewLine(float x, float y, float x2, float y2);
	int DrewRect(float x, float y, float x2, float y2, int a, int b, int g);
	int done();
	
};

#ifdef _WIN32
typedef ZGraph_gl ZGraph;
#endif
#ifdef __linux

#endif