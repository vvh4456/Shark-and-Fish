#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
class Psi
{
public:
	Psi();
	~Psi();
	int inits() {
		float vertices[] = {
			0.5f,  0.5f, 0.0f,  0.1f,0.0f,1.0f,  
			0.5f, -0.5f, 0.0f,    0.0f,1.0f,0.0f,    
			-0.5f, -0.5f, 0.0f,    1.0f,0.0f,0.0f,     
			-0.5f,  0.5f, 0.0f,      0.0f,1.0f,0.0f,
			-0.7f,  0.7f, 0.0f,       1.0f,1.0f,1.0f
		};
		unsigned int indices[] = { 
			0, 1, 3, 
			1, 2, 3,
			4,0,3
		};
		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

//______________________________________________
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

};

