#ifndef ELECTRON_GLUT_H
#define ELECTRON_GLUT_H

#include <nan.h>
#include <v8.h>

using namespace v8;

typedef unsigned int GLuint;

void GLUT_Init(const Nan::FunctionCallbackInfo<Value>& info);
void GLUT_TextureUpdate(const Nan::FunctionCallbackInfo<Value>& info);

#endif