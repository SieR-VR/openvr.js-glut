#include <nan.h>
#include "electron-glut.h"

void Initialize(v8::Local<v8::Object> exports)
{
    v8::Local<v8::Context> context = exports->CreationContext();

    exports->Set(context,
                Nan::New("GLUT_Init").ToLocalChecked(),
                Nan::New<v8::FunctionTemplate>(GLUT_Init)->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                Nan::New("GLUT_TextureUpdate").ToLocalChecked(),
                Nan::New<v8::FunctionTemplate>(GLUT_TextureUpdate)->GetFunction(context).ToLocalChecked());
}

NODE_MODULE(glut, Initialize);