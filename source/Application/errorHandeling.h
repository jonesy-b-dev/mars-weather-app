#pragma once
class ErrorHandeling
{
public:
	static void CheckShader(unsigned int shader, const char* type);
	static void CheckShaderProgram(unsigned int program);
	static void ValidateShaderProgram(unsigned int program);
};	