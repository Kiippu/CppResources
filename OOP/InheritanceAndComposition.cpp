/**
 * OOP - Inheritance and Composition
 * 
 * Composition - Object composed in another object
 *  - Represents a "has-a" relation
 *  - Reuse behavior
 * Example: a Car has an Engine so the car now has an implementation to move
 * 
 * Inheritance - A class inherits  the features of another class
 *  - Reuse & inherit behaviour
 *  - Represents "is-a/an" relationship
 * Example: a cow is an animal and therefore it has all the attributes of other animals
 * 
 * Access modifiers in inheritance 
 * If Public        then all inherited access modifiers stay the same
 * If Protected     then all inherited public turn into protected and and others stay the same
 * If Private       then all inherited access modifiers become protected
 * 
 * Object Construction
 *  - Construction: base  -> child -> ..
 *  - Destructors:  child -> base  -> ..
 *  - base data members will be part of child object
*/
#include <iostream>

class Window
{
public:
    void event()
    {
        std::cout << "Window Event" << std::endl;
    }
    void draw()
    {
        std::cout << "Window draw" << std::endl;
    }
    void update()
    {
        std::cout << "Window update" << std::endl;
    }
};

class Charts : public Window
{
public:
    void draw()
    {
        std::cout << "Charts draw" << std::endl;
    }
    void update()
    {
        std::cout << "Charts update" << std::endl;
    }

};

// int main(int argc, char const *argv[])
// {
//     Charts c;
//     c.draw();
//     c.update();
//     c.event();
//     return 0;
// }
