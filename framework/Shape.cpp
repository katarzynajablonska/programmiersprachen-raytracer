//
//  Shape.cpp
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#include "Shape.h"

using namespace std;

Shape::Shape() : name_{}, color_{0.0,0.0,0.0}
{
    cout<<"Konstruktor der Klasse Shape"<<endl;
}

Shape::Shape(string const& name, Color const& color) : name_{name}, color_{color}
{
    cout<<"Konstruktor der Klasse Shape"<<endl;
}

Color const& Shape::get_color() const
{
    return color_;
}
string const& Shape::get_name() const
{
    return name_;
}

ostream& operator<<(ostream& os, Shape const& s) //returns a reference to the original ostream object, which means insertions can be combined
{
    return s.print(os);
}

ostream& Shape::print(ostream& os) const  //the function takes an ostream
{
    os<<endl<<"Name: "<<name_<<endl<<"Color: "<<color_.r<<" "<<color_.g<<" "<<color_.b<<endl;
    return os;  //and writes to that stream
}

Shape::~Shape()
{
    std::cout<<"Destruktor der Klasse Shape"<<std::endl;
}

