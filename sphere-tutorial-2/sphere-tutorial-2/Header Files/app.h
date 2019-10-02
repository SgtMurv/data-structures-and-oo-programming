//
//  app.h
//  sphere-tutorial-2
//
//  Created by Matthew Honour on 27/09/2019.
//  Copyright © 2019 Matthew Honour. All rights reserved.
//

class Application{
protected:  //only inheriting classes have access to these properties.
    int height;
    int width;
public:
    virtual void initGraphics();
    virtual void display();
    virtual void update();
    virtual void resize(int width, int height);
};

/*
 Exercise 1: What is the benefit of using virtual methods in the Application class?
 - They can be overwritten by child classes, and the application class doesnt need tp know about 
 */
