//g++ main.cpp -lGL -lglfw -lGLEW -lcurses -no-pie
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
#include "drawengine.cpp"
#include "key.cpp"
#include "gameEngine.cpp"







static GLuint createObject(GLuint vertices, const GLfloat(*position)[2])
{
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
GLuint createTexture(GLenum internalFormat, GLsizei width, GLsizei height)
{
    // 境界色
    const GLfloat border[] = { 0.0f, 0.0f, 0.0f, 0.0f };

    GLuint t;

    glGenTextures(1, &t);
    glBindTexture(GL_TEXTURE_2D, t);
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

    return t;
}
void Mainloop();
int main()
{
    d_Engine = new DrawEngine();
    if(!d_Engine->Init()){
        std::cerr << "Initに失敗したため終了" << std::endl;
    }
    
    /*
    
    // GLFW初期化
    if (glfwInit() == GL_FALSE)
    {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return -1;
    }
    

    
    //window_size
    GLsizei weigth(1200), hight(1000);
    //shader_file_name
    const std::string vertex_filename = "shader.vert";
    const std::string fragment_filename = "depth.frag";
    const float FRAMETIME = 1./60.;

    // ウィンドウ生成
    GLFWwindow* window = glfwCreateWindow(weigth, hight, "OpenGL Sample", NULL, NULL);
    if (!window)
    {
        std::cerr << "Can't create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    // バージョン3.1/140指定
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    // GLEW初期化
    if (glewInit() != GLEW_OK)
    {
        return -1;
    }
        
    // プログラムオブジェクト作成
    GLint outshader = makeShader(vertex_filename, "outshader.frag", "pv", "fc");


    // 諸々初期化
    float time=80.0;
    //BYTE mInputByteBuffer[256];
    vec3 pos;
    pos.x = 0.0;   pos.y = 30.0;   pos.z = -30.0;
    vec2 dir;


    // 図形データ作成
    static const GLfloat position[][2] =
    {
        { -1.0f, -1.0f },
        { 1.0f, -1.0f },
        { -1.0f, 1.0f },
        { 1.0f, 1.0f }
    };
    static const int vertices = sizeof(position) / sizeof(position[0]);
    // 頂点配列オブジェクト
    GLuint vao = createObject(vertices, position);
    */
    

    //==============texture1 実装===================================================
    /*const GLsizei fboWeigth = weigth, fboHight = hight;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //カラーバッファ
    GLuint colorBuffer = createTexture(GL_RGBA32F, fboWeigth, fboHight);
    //デプスバッファ
    GLuint depthBuffer = [] {GLuint t; glGenTextures(1, &t); return t; }();
    glBindTexture(GL_TEXTURE_2D, depthBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32F, fboWeigth, fboHight, 0, GL_R, GL_FLOAT, NULL);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);//ここまでデプスバッファの用意のやつ
    //フレームバッファオブジェクト作成
    GLuint fbo = [] {GLuint t; glGenFramebuffers(1, &t); return t; }();
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    //フレームバッファにカラー，デプスを組み込む
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, colorBuffer, 0);
    //glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, depthBuffer, 0);
    
    //================================================================================*/
    //==============texture2 実装===================================================
    /*glClearColor(0.0, 0.0, 0.0, 0.0);
    //カラーバッファ
    GLuint colorBuffer2 = createTexture(GL_RGBA, fboWeigth, fboHight);
    //デプスバッファ
    GLuint depthBuffer2 = [] {GLuint t; glGenTextures(1, &t); return t; }();
    glBindTexture(GL_TEXTURE_2D, depthBuffer2);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_R32F, fboWeigth, fboHight, 0, GL_R, GL_FLOAT, NULL);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);//ここまでデプスバッファの用意のやつ
    //フレームバッファオブジェクト作成
    GLuint fbo2 = [] {GLuint t; glGenFramebuffers(1, &t); return t; }();
    glBindFramebuffer(GL_FRAMEBUFFER, fbo2);
    //フレームバッファにカラー，デプスを組み込む
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, colorBuffer2, 0);
    //glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, depthBuffer2, 0);

    //================================================================================*/

    //----------------フレームへの書き込み（なはず）-------------------------------
    /*GLint bufferprogram = makeShader(vertex_filename, "Buffer.frag", "pv", "fc");
        glClear(GL_COLOR_BUFFER_BIT);
        //shadre program start
        glUseProgram(bufferprogram);
        // 色指定
        glColor4f(1.0, 0.0, 0.0, 1.0);
        // Windowのサイズ調整
        glfwGetFramebufferSize(window, &weigth, &hight);
        glfwSetWindowSize(window, weigth, hight);
        glViewport(0, 0, weigth, hight);

        glUniform2f(0, weigth, hight);
        // 描画
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices);
        glBindVertexArray(0);
        // shader program finish
        //glUseProgram(0);
        // ダブルバッファのスワップ
        glfwSwapBuffers(window);
        //glFlush();
        //glfwPollEvents();
    //-----------------------------------------------------------------------------------*/
    
    static int outshader = makeShader("shader.vert", "outshader.frag", "pv", "fc");
    glUseProgram(outshader);

    // フレームループ
    Mainloop();


    glBindVertexArray(0);
    glUseProgram(0);
    // GLFWの終了処理
    glfwTerminate();

    return 0;
}

void Mainloop(){
    characterinf player;
    player.pos = {0,0,0};
    player.dir = {0,0,0};
    static const float FRAMETIME = 1./60.;
    float now, sleeptime, prev = 0.0,speed=0.001;
    while (glfwWindowShouldClose(d_Engine->window) == GL_FALSE)
    {
        
        
     
        now = glfwGetTime();
        
        if (now - prev > FRAMETIME) {
            prev = now;
            //============キー入力========================================================================================================
            player.pos.z += (float(GetKey(GLFW_KEY_W)) - float(GetKey(GLFW_KEY_S))) * speed * cos(player.dir.x)
                + (float(GetKey(GLFW_KEY_A)) - float(GetKey(GLFW_KEY_D))) * speed * sin(player.dir.x);
            player.pos.x += -(float(GetKey(GLFW_KEY_A)) - float(GetKey(GLFW_KEY_D))) * speed * cos(player.dir.x)
                    + (float(GetKey(GLFW_KEY_W)) - float(GetKey(GLFW_KEY_S))) * speed * sin(player.dir.x);
            player.pos.y += (float(GetKey(GLFW_KEY_SPACE)) - float(GetKey(GLFW_KEY_V))) * speed;
            player.dir.x -= (float(GetKey(GLFW_KEY_LEFT)) - float(GetKey(GLFW_KEY_RIGHT))) * speed / 10.;// 0x41==A, 0x44==D
            player.dir.y += (float(GetKey(GLFW_KEY_UP)) - float(GetKey(GLFW_KEY_DOWN))) * speed / 10.;// 0x57==W, 0x53==S
            //time += (float(GetKey(GLFW_KEY_O)) - float(GetKey(GLFW_KEY_P))) * speed;
            
                
            //*/==========================================================================================================================

            // Windowのサイズ調整
            d_Engine->setwindow();
            
            

            // uniform関数指定
            /*
            glUniform2f(glGetUniformLocation(drawEngine::outshader, "Res"),
                        drawEngine::windowsize.x, drawEngine::windowsize.y);
            glUniform3f(glGetUniformLocation(drawEngine::outshader, "Pos"),
                        player.pos.x, player.pos.y, player.pos.z);
            glUniform2f(glGetUniformLocation(drawEngine::outshader, "turn"),
                        player.dir.x, player.dir.y);
            //glUniform1f(glGetUniformLocation(drawEngine::outshader, "time"), time);
            */
            
            // 描画
            d_Engine->drawcall();


        }
    }
}