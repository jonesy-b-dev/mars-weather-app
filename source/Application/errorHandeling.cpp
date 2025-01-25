#include "glad\glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>
#include <vector>


#include "errorHandeling.h"


void ErrorHandeling::CheckShader(unsigned int shader, const char* type)
{
	static int success;
	static char infoLog[512];

	//check if the shader compiled correctly and print any errors
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	//If the shader failed to compile print the error
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::" << type << "::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else
	{
		std::cout << "Shader compilation completed successfully\n";
	}
}

void ErrorHandeling::CheckShaderProgram(unsigned int program)
{
	static int success;
	static char infoLog[512];

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	else
	{
		std::cout << "Shader linking completed successfully\n";
	}
}

void ErrorHandeling::ValidateShaderProgram(unsigned int program)
{
    glValidateProgram(program);
    GLint validationStatus;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &validationStatus);
    if (validationStatus == GL_FALSE)
    {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char> log(logLength);
        glGetProgramInfoLog(program, logLength, &logLength, log.data());
        std::cerr << "Shader program validation failed: " << log.data() << std::endl;
    }
    else
    {
		std::cout << "Shader program validated successfully.\n";
    }
}