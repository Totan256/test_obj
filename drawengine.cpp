//#include "stdafx.h"
#include <iostream>
#include <math.h>
//#include "glfw3.lib"
//#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <GL/glew.h>
//#include <gl/glfw.h>
#include <GLFW/glfw3.h>
#include "sharestruct.h"
#include "readSouce.cpp"

class DrawEngine{
 private:
  int vertices;
  
 public:
  GLFWwindow* window;
  ivec2 windowsize;/*ウィンドウの大きさ*/
  


 public:
  bool Init();
  uint makeSquareData();
  void setwindow();
  uint createVertexObject(uint vertices, const GLfloat(*position)[2]);
  void drawcall();

};

bool DrawEngine::Init(){
    if (glfwInit() == GL_FALSE)    {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return false;
    }
    // ウィンドウ生成
    windowsize={200,200};
    window = glfwCreateWindow(windowsize.x, windowsize.y,
        "OpenGL Sample", NULL, NULL);
    if (!window)    {
        std::cerr << "Can't create GLFW window." << std::endl;
        glfwTerminate();
        return false;
    }
    // バージョン3.1/140指定
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    // GLEW初期化
    if (glewInit() != GLEW_OK){
        std::cerr << "Can't use GLEW." << std::endl;
        return false;
    }
    

    uint vao = makeSquareData();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindVertexArray(vao);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindVertexArray(vao);

    return true;
}

uint DrawEngine::makeSquareData(){
    // 図形データ作成
    static const GLfloat position[][2] =
    {
        { -1.0f, -1.0f },
        { 1.0f, -1.0f },
        { -1.0f, 1.0f },
        { 1.0f, 1.0f }
    };
    drawEngine:vertices = sizeof(position) / sizeof(position[0]);
    // 頂点配列オブジェクト
    return createVertexObject(vertices, position);
}
uint DrawEngine::createVertexObject(GLuint vertices, const GLfloat(*position)[2]){
    // 頂点配列オブジェクト
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // 頂点バッファオブジェクト
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 2 * vertices, position, GL_STATIC_DRAW);

    // 結合されている頂点バッファオブジェクトを attribute 変数から参照できるようにする
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    // 頂点バッファオブジェクトと頂点配列オブジェクトの結合を解除する
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return vao;
}
void DrawEngine::drawcall(){
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices);


    // ダブルバッファのスワップ
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void DrawEngine::setwindow(){
    // Windowのサイズ調整
    glfwGetFramebufferSize(window, &windowsize.x, &windowsize.y);
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glViewport(0, 0, windowsize.x, windowsize.y);
}

DrawEngine* d_Engine;
