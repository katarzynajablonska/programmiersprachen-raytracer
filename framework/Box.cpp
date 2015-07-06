//
//  Box.cpp
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#include "Box.h"

using namespace std;

Box::Box() : Shape{"box", {0.0, 0.0, 0.0}}, min_{0.0, 0.0, 0.0}, max_{0.0, 0.0, 0.0}
{
    cout<<"Konstruktor der Klasse Box"<<endl;
}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& c) : Shape{"box", c}, min_{min}, max_{max}
{
    cout<<"Konstruktor der Klasse Box"<<endl;
}

glm::vec3 const& Box::get_min() const
{
    return min_;
}

glm::vec3 const& Box::get_max() const
{
    return max_;
}

float Box::length() const
{
    return max_.x - min_.x;
}

float Box::width() const
{
    return max_.y - min_.y;
}

float Box::height() const
{
    return max_.z - min_.z;
}

float Box::area() const
{
    return 2*width()*height()+2*width()*length()+2*height()*length();
}
float Box::volume() const
{
    return width()*length()*height();
}

std::ostream& Box::print(std::ostream& os) const //ostream jest typem(klasa)
{
    Shape::print(os)<<"Minimum: "<<min_.x<<" "<<min_.y<<" "<<min_.z<<endl;
    os<<"Maximum: "<<max_.x<<" "<<max_.y<<" "<<max_.z<<endl<<endl;
    return os;
}

Box::~Box()
{
    cout<<"Destruktor der Klasse Box"<<endl;
}
