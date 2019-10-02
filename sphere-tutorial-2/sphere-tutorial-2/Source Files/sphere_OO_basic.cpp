//
//  sphere_OO_basic.cpp
//  sphere-tutorial-2
//
//  Created by Matthew Honour on 27/09/2019.
//  Copyright © 2019 Matthew Honour. All rights reserved.
//
#define GL_SILENCE_DEPRECATION // this line silences the yellow warnings of deprecation of OpenGL from
#include <GLUT/GLUT.h>
#include "../Header Files/app.h"
#include "sphere.cpp"

class SphereDemo : public Application
{
    Sphere *sphere1;
    Sphere *sphere2;
public:
    SphereDemo();
    virtual void display();
    virtual void update();
};

SphereDemo::SphereDemo()
{
//    just hard code it to create 2 spheres;
    sphere1 = new Sphere(0, 0, 10, 255, 150, 2, 2, 10);
    sphere2 = new Sphere(90, 0, 255, 0, 255,-2, -2, 10);
}
void SphereDemo::update(void)
{
//    !THE LOGIC OF DETECTING EDGES DOES NOT WORK WITH 2 SPHERES! NOT SURE WHY? MAYBE TRY AND JUST GET THEM TO COLLIDE.
//     check whether the sphere1 has touched an edge of the window.
    if ((sphere1->getX() + sphere1->getRadius()) > width || (sphere1->getX() - sphere1->getRadius()) < -width) {
        sphere1->setXStep(-(sphere1->getXStep()));
    }
    if ((sphere1->getY() + sphere1->getRadius()) > height || (sphere1->getY() - sphere1->getRadius()) < -height){
        sphere1->setYStep(-(sphere1->getYStep()));
    }
    sphere1->setX(sphere1->getX() + sphere1->getXStep());
    sphere1->setY(sphere1->getY() + sphere1->getYStep());
    
    // check whether the sphere2 has touched an edge of the window.
    if ((sphere2->getX() + sphere2->getRadius()) > width || (sphere2->getX() - sphere2->getRadius()) < -width) {
        sphere2->setXStep(-(sphere2->getXStep()));
    }
    if ((sphere2->getY() + sphere2->getRadius()) > height || (sphere2->getY() - sphere2->getRadius()) < -height){
        sphere2->setYStep(-(sphere2->getYStep()));
    }

    sphere2->setX(sphere2->getX() + sphere2->getXStep());
    sphere2->setY(sphere2->getY() + sphere2->getYStep());

    Application::update();
}
void SphereDemo::display(void)
{
    Application::display();
    
    //render the first sphere to the screen;
    glTranslatef(sphere1->getX(), sphere1->getY(), 0.0f);
    glColor3ub(sphere1->getRed(), sphere1->getGreen(), sphere1->getBlue());
    glutSolidSphere(sphere1->getRadius(), 30, 30);
    
    //render the second sphere to the screen;
    glTranslatef(sphere2->getX(), sphere2->getY(), 0.0f);
    glColor3ub(sphere2->getRed(), sphere2->getGreen(), sphere2->getBlue());
    glutSolidSphere(sphere2->getRadius(), 30, 30);
    
    glutSwapBuffers();
}
//this methods is not a part of the sphere class and only exists to get the sphere demo object
Application* getApplication(){
     return new SphereDemo();
}
