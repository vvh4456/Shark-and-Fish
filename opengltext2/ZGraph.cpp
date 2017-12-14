#include "ZGraph.h"

#include <iostream>
#include <glad/glad.h>
#include "glfw/glfw3.h"
#include "glm/glm.hpp"




GLFWwindow* window = nullptr;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static int isrun = 0;
void ZGraph_gl::Init() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
#ifdef __glad_h_
#endif
	
};

ZGraph_gl::ZGraph_gl()
{

}
const char *LineShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 sour;\n"
"out vec4 color;\n"
"uniform vec3 ab;\n"
"uniform vec3 b;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(b,0.0f)+vec4(ab.x*sour.x,ab.y*sour.y,ab.z*sour.z,1.0f);\n"
"	color=vec4(0.5f,0.0f,0.0f,0.5f);\n"
"}\0"
;
const char *RectangleShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 sour;\n"
"out vec4 color;\n"
"uniform vec4 col;\n"
"uniform vec2 hw;\n"
"uniform vec3 LifeDown;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(LifeDown.x, LifeDown.y, LifeDown.z, 0.0f)\n"
"				+vec4(hw.x*sour.x, hw.y*sour.y, 0.0f*sour.z, 1.0f);\n"
"	color=col;\n"
"}\0"
;
const char *fragmentShaderSource =
"#version 330 core\n"
"in vec4 color;\n"
"uniform vec4 ourColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = color;\n"
//"   FragColor = vec4(color.x, ourColor.y, 0.2f, 1.0f);\n"
"}\n\0"
;
float ComVector[] = {
0.0f,0.0f,1.0f,
0.0f,1.0f,1.0f,
1.0f,0.0f,1.0f,
1.0f,1.0f,1.0f
};
int LineEBO[] = {
0,3
};
int RectEBO[] = {
	0,2,1,
	1,2,3
};

static int LineID;
static int RectID;

static int LineShader;
static int RectShader;



ZGraph_gl::~ZGraph_gl()
{

}

void ZGraph_gl::useThisWindow(GLFWwindow* window)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	if (isrun == 0) { privatefun(); isrun++; }
	this->window = window;
}

int ZGraph_gl::createProgram()
{
	return glCreateProgram();
}

int ZGraph_gl::createShader(const std::string sharderSource, GLenum g)
{
	const char* vertexShaderSource = sharderSource.c_str();
	int vertexShader = glCreateShader(g);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}
	return vertexShader;
}

int ZGraph_gl::deleteShader(int shader)
{
	glDeleteShader(shader);
	return 1;
}

int ZGraph_gl::attachShader(int program, int shader)
{
	glAttachShader(program, shader);
	return 1;
}

int ZGraph_gl::linkProgram(int program)
{
	glLinkProgram(program);
	int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return 0;
	}
	return 1;
}

int ZGraph_gl::deleteProgram(int program)
{
	glDeleteProgram(program);
	return 1;
}

bool ZGraph_gl::useProgram(int program)
{
	glUseProgram(program);
	return true;
}

void ZGraph_gl::setFloat(int program, const std::string & name, float value)
{
	glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

int ZGraph_gl::CreateVAO()
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	return VAO;
}

int ZGraph_gl::setVBO(float *vertices, int n)
{
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*n, vertices, GL_STATIC_DRAW);
	return 0;
}

int ZGraph_gl::setEBO(int *indices, int n, int location=0)
{
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*n, indices, GL_STATIC_DRAW);
	//______________________i know it should'n on here but i am so l
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(location);
	//________________________
	return 0;
}

int ZGraph_gl::DrewLine(float x, float y, float x2, float y2)
{
	float abx = x2 - x;
	float aby = y2 - y;
	useProgram(LineShader);
	useVector(LineID);
	glUniform3f(glGetUniformLocation(LineShader, "ab"),abx,aby, 0.0f);
	glUniform3f(glGetUniformLocation(LineShader, "b"), x, y,0.0f);
	glDrawElements(GL_LINE_STRIP, 2, GL_UNSIGNED_INT, 0);
	return 0;
}

int ZGraph_gl::DrewRect(float x, float y, float x2, float y2,int a,int b,int g)
{
	float cx = x2 - x;
	float cy = y2-y;
	useProgram(RectShader);
	useVector(RectID);
	glUniform2f(glGetUniformLocation(RectShader, "hw"),cx,cy );
	glUniform3f(glGetUniformLocation(RectShader, "LifeDown"), x,y,0.0f);
	glUniform4f(glGetUniformLocation(RectShader, "col"), a/256.0f, b / 256.0f,g/256.0f,1.0f);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return 1;
}

int ZGraph_gl::useVector(int VectorID)
{
	glBindVertexArray(VectorID);
	return 1;
}

int ZGraph_gl::clear()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return 1;
}

int ZGraph_gl::done()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
	return 0;
}

int ZGraph_gl::privatefun()
{
	int s2; int s1;
	LineShader = createProgram();
	s1=createShader(LineShaderSource,GL_VERTEX_SHADER);
	
	s2 = createShader(fragmentShaderSource,GL_FRAGMENT_SHADER);
	attachShader(LineShader, s1);
	attachShader(LineShader, s2);
	linkProgram(LineShader);
	deleteShader(s1);
	deleteShader(s2);

	RectShader = createProgram();
	s1 = createShader(RectangleShaderSource,GL_VERTEX_SHADER);
	s2 = createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	attachShader(RectShader, s1);
	attachShader(RectShader, s2);
	linkProgram(RectShader);
	deleteShader(s1);
	deleteShader(s2);

	
	LineID = CreateVAO();
	setVBO(ComVector,12);
	setEBO(LineEBO,2);

	RectID = CreateVAO();
	setVBO(ComVector, 12);
	setEBO(RectEBO, 6);


	return 0;
}

/*

const char *vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 col;\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
"	color=vec4(0.0f,0.0f,0.0f,0.0f);\n"
"}\0";
const char *fragmentShaderSource = 
"#version 330 core\n"
"in vec4 color;\n"
"uniform vec4 ourColor;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = color*ourColor;\n"
//"   FragColor = vec4(color.x, ourColor.y, 0.2f, 1.0f);\n"
"}\n\0";

*/