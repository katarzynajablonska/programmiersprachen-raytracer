//
//  Sphere.cpp
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#include "Sphere.h"
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

using namespace std;

Sphere::Sphere() : Shape{"sphere", {0.0, 0.0, 0.0}}, radius_{0.0}, center_{0.0, 0.0, 0.0}
{
    cout<<"Konstruktor der Klasse Sphere"<<endl;
}

Sphere::Sphere(float r, glm::vec3 const& s, Color const& c) : Shape{"sphere", c}, radius_{r}, center_{s}
{
    cout<<"Konstruktor der Klasse Sphere"<<endl;
}

float Sphere::get_radius() const
{
    return radius_;
}

glm::vec3 const& Sphere::get_center() const
{
    return center_;
}

float Sphere::area() const
{
    return 4*M_PI*radius_*radius_;
}

float Sphere::volume() const
{
    return 4*M_PI*radius_*radius_*radius_/3;
}

std::ostream& Sphere::print(std::ostream& os) const //ostream jest typem
{
    Shape::print(os)<<"Radius: "<<radius_<<endl;
    os<<"Mittelpunkt: "<<center_.x<<" "<<center_.y<<" "<<center_.z<<endl<<endl;
    return os;
}

bool Sphere::intersect(Ray const& ray, float& distance) const
{
    glm::vec3 norm = glm::normalize(ray.direction);
    float radiussquared=radius_*radius_;
    return glm::intersectRaySphere(ray.origin, norm, center_, radiussquared, distance);
}

Sphere::~Sphere()
{
    cout<<"Destruktor der Klasse Sphere"<<endl;
}

Sphere::Sphere(glm::vec3 const& s, float r, Color const& c, std::string const& name) : center_{s}, radius_{r}, Shape{name, c}
{
    cout<<"Konstruktor der Klasse Sphere"<<endl;
}
