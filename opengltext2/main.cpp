#ifndef MAIN
#define MAIN
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "ZGraph.h"
void processInput(GLFWwindow *window);

// settings
int k = 1;//it is no mean
unsigned char colors[3][3] = { {0,0,255} ,{0,255,0} ,{255,0,0} };
int seanceH;
int seanceW;
char* seaMap = nullptr;
int seaH;
int seaW;
int setfish(int h,int w,int kind);
int setSeaHW(int h, int w);
int NextBout();
int getNeighbor(int h,int w,char*);
int drawSea(ZGraph& a) {
	int i,j;
	for (i = 0; i < seaH; i++) {
		for (j = 0; j < seaW;j++) {
			if (colors[seaMap[i*seaH + j] % 3][2] == 255)continue;
			a.DrewRect(
				(i+1)/(float)seaH*2-1, (j+1)/(float)seaW*2-1 ,
				(i) / (float)seaH * 2 - 1, (j) / (float)seaW*2-1 ,
				colors[seaMap[i*seaH+j]%3][0],
				colors[seaMap[i*seaH + j]%3][1],
				colors[seaMap[i*seaH + j]%3][2]
				);
		}
	}
	return 1;
}
//map (seaH,seaW)->(seanceH,seanceW)->(-1,1)

int main()
{
	setSeaHW(20,20);
	int i = 1;
	setfish(1,1,2);
	ZGraph test;
	test.pri();
	int counter=0;

	test.clear();
	test.done();
	test.clear();
	test.done();
	//twice because it have two buffer

	while (!glfwWindowShouldClose(test.getWindowID()))
	{
		processInput(test.getWindowID());
		i=(i++)%seaH+1;
		setfish((i*23)%seaH+1,i%seaW+1,i%2+1);
		//test.clear();
		drawSea(test);
		test.done();
		Sleep(100);
	}
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	//if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)k=0;
	if (glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS)k=0;
}

int setfish(int h, int w, int kind)
{
	seaMap[seaH*(h-1)+w-1] = (char)kind;
	return 1;
}

int setSeaHW(int h, int w)
{
	if (seaMap != nullptr) {
	//to do delete;
	};
	seaMap =new char[h*w];
	memset(seaMap,0,sizeof(char)*h*w);
	seaH = h;
	seaW = w;
	return 1;
}

int NextBout()
{
	


	return 0;
}

int getNeighbor(int h, int w, char *)
{




	return 0;
}

#endif