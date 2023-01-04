#include "./libraries/Window/Window.h"
#include <iostream>

int main (int argc, char** argv){
    Window w(800, 600, "Teste");

    
    while(1){
        w.update();
    }

    return 0;

}