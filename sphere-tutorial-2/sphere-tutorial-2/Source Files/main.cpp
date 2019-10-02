//
//  main.cpp
//  sphere-tutorial-2
//
//  Created by Matthew Honour on 27/09/2019.
//  Copyright © 2019 Matthew Honour. All rights reserved.
//
#define GL_SILENCE_DEPRECATION // this line silences the yellow warnings of deprecation of OpenGL from
#include <GLUT/GLUT.h>
#include "../Header Files/app.h"

GLfloat timeinterval = 1.0f;
extern Application* getApplication();
Application* app;

void display(void){
    app->display();
}
void createWindow(const char* title){
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow(title);
}
void resize(int width, int height){
    app->resize(width, height);
}
void TimerFunc(int value)
{
    app->update();
    glutTimerFunc(timeinterval, TimerFunc, 1);
}
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    app = getApplication();
    createWindow("Sphere");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutTimerFunc(timeinterval, TimerFunc, 1);
    app->initGraphics();
    glutMainLoop();
    delete app;
    return 0;
}
