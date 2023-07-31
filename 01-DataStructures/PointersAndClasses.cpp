#include <iostream>

using namespace std;

//***PART 1: CLASSES & POINTERS***
class Cookie
{
private:
    string color;

public:
    Cookie(string color)
    {
        this->color = color;
    }

    string getColor()
    {
        return color;
    }

    string setColor(string color)
    {
        return this->color = color;
    }
};
//----------------------------------------------

//***PART 1 TESTING***: CLASSES & POINTERS***

int main()
{
    //-----------------------------------------------
    Cookie *cookieOne = new Cookie("green"); // new -> constructor
    Cookie *cookieTwo = new Cookie("blue");  // new -> constructor

    cookieOne->setColor("yellow");

    cout << "C1: " << cookieOne->getColor() << endl;
    cout << "C2: " << cookieTwo->getColor() << endl;
}

//----------------------------
