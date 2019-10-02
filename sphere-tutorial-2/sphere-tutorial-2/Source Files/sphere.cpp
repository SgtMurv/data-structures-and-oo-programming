//
//  sphere.cpp
//  sphere-tutorial-2
//
//  Created by Matthew Honour on 01/10/2019.
//  Copyright © 2019 Matthew Honour. All rights reserved.
//
class Sphere {
    int radius;
    int x;
    int y;
    int xstep;
    int ystep;
    int color[3];
public:
    Sphere(){};
    Sphere(int x, int y, int red, int green, int blue, int xstep, int ystep, int radius){
        setRadius(radius);
        setX(x);
        setY(y);
        setXStep(xstep);
        setYStep(ystep);
        setRed(red);
        setGreen(green);
        setBlue(blue);
    };
    int getRadius(){return this->radius;};
    void setRadius(int radius){this->radius = radius;};
    
    int getX(){return this->x;};
    void setX(int x){this->x = x;};
    
    int getY(){return this->y;};
    void setY(int y){this->y = y;};;
    
    int getXStep(){return this->xstep;};
    void setXStep(int xstep){this->xstep = xstep;};
    
    int getYStep(){return this->ystep;};
    void setYStep(int ystep){this->ystep = ystep;};
    
    int getRed(){return this->color[0];};
    void setRed(int red){this->color[0] = red;};
    
    int getGreen(){return this->color[1];};
    void setGreen(int green){this->color[1] = green;};
    
    int getBlue(){return this->color[2];};
    void setBlue(int blue){this->color[2] = blue;};

    void setColors(int red, int green, int blue){
        this->color[0] = red;
        this->color[1] = green;
        this->color[2] = blue;
    };
};
