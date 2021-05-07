#include "electron-glut.h"

#include <glut.h>
#include <GLFW/glfw3.h>
#include <array>
#include <node_buffer.h>

#include <wingdi.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint bufferTexture = 0;

void GLUT_Init(const Nan::FunctionCallbackInfo<Value> &info)
{
    auto context = info.GetIsolate()->GetCurrentContext();
    int32_t width = info[0]->Int32Value(context).FromJust();
    int32_t height = info[1]->Int32Value(context).FromJust();

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    GLFWwindow* glWindow = glfwCreateWindow(width, height, "electron-glut", nullptr, nullptr);
    glfwMakeContextCurrent(glWindow);

    info.GetReturnValue().Set(Nan::New<Number>((uint64_t) glWindow));
}

void GLUT_TextureUpdate(const Nan::FunctionCallbackInfo<Value> &info)
{
    auto context = info.GetIsolate()->GetCurrentContext();
    Local<ArrayBufferView> input = info[0].As<ArrayBufferView>();
    Nan::TypedArrayContents<uint8_t> buf(input);

    int32_t width, height, channel;
    stbi_set_flip_vertically_on_load(true);
    auto image = stbi_load_from_memory(*buf, buf.length(), &width, &height, &channel, 0);

    if(bufferTexture == 0) {
        glGenTextures(1, &bufferTexture);

        glBindTexture(GL_TEXTURE_2D, bufferTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    else {
        glBindTexture(GL_TEXTURE_2D, bufferTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    glFlush();
	glFinish();

    info.GetReturnValue().Set(Nan::New<Number>(bufferTexture));
}