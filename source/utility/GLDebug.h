#pragma once
#ifndef GLDEBUG_H_INCLUDED
#define GLDEBUG_H_INCLUDED

#include <glad/glad.h>

GLenum glCheckError_(const char* file, int line);
#define glCheckError() glCheckError_(__FILE__, __LINE__)
void GLAPIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#endif