#include "Window.h"
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <GL/glew.h>
#include "./Cores/Cores.h"
#include <iostream>


Window::Window(int w, int h, const char* title){

    //-> Iniciando GLFW
    if(!glfwInit()){
        std::cout << "[WINDOW] Falha ao iniciar GLFW." << std::endl;
        return;
    };


    // -> Definindo atributos de contexto OPENGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback(Window::error_callback);


    // -> Criando janela
    m_Window = glfwCreateWindow(w, h, title, NULL, NULL);
    if(!m_Window){
        std::cout << "[WINDOW] Falha ao criar janela." << std::endl;
        glfwTerminate();
        return;
    }


    // -> Define com contexto atual
    glfwMakeContextCurrent(m_Window);
    GLenum glewInitError = glewInit();
    if(glewInitError != GLEW_OK){
        std::cout << "[WINDOW] Falha ao iniciar GLEW:" << glewGetErrorString(glewInitError) << std::endl;
        return;
    }


    // -> Mostra os dados do ambiente
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "[WINDOW] Renderer: " << renderer << std::endl;
    std::cout << "[WINDOW] OpenGL versão suportada: " << version << std::endl;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::update(){

}

Window::~Window(){
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::error_callback(int error, const char* description){
    std::cout << "[WINDOW] Erro" << error << ": " << description << std::endl;
}