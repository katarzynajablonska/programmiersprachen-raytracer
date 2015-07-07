//
//  Box.cpp
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#include "Box.h"
#include <algorithm>

using namespace std;

Box::Box() : Shape{"box", {}}, min_{0.0, 0.0, 0.0}, max_{0.0, 0.0, 0.0}
{
    cout<<"Konstruktor der Klasse Box"<<endl;
}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Material const& m) : Shape{"box", m}, min_{min}, max_{max}
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
    
bool Box::intersect(Ray const& ray, float& t) const
{
    float tmin, tmax, tymin, tymax, tzmin, tzmax;
    tmin = (min_.x-ray.origin.x)/ray.direction.x;
    tmax = (max_.x-ray.origin.x)/ray.direction.x;
    tymin = (min_.y-ray.origin.y)/ray.direction.y;
    tymax = (max_.y-ray.origin.y)/ray.direction.y;
    tzmin = (min_.z-ray.origin.z)/ray.direction.z;
    tzmax = (max_.z-ray.origin.z)/ray.direction.z;
    if (tmin>tmax)
    {
        swap(tmin, tmax);
    }
    if (tymin>tymax)
    {
        swap(tymin, tymax);
    }
    if (tzmin>tzmax)
    {
        swap(tzmin, tzmax);
    }
    if ((tmin > tymax)||(tymin > tmax))
    {
        return false;
    }
    if (tymin > tmin)
    {
        tmin = tymin;
    }
    if (tymax < tmax)
    {
        tmax = tymax;
    }
    if ((tmin > tzmax)||(tzmin > tmax))
    {
        return false;
    }
    if (tzmin > tmin)
    {
        tmin = tzmin;
    }
    if (tzmax < tmax)
    {
        tmax = tzmax;
    }
    return ((t>=tmin)&&(t<=tmax));
}
