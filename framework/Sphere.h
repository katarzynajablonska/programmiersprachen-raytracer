//
//  Sphere.h
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "Ray.h"
#include "color.hpp"
#include <glm/vec3.hpp>

#include <cmath>

class Sphere : public Shape
{
    float radius_;
    glm::vec3 center_;
    
public:
    Sphere();
    Sphere(float r, glm::vec3 const& s, Color const& c);
    float get_radius() const;
    glm::vec3 const& get_center() const;
    float area() const override;
    float volume() const override;
    
    //  Aufgabe 6.5
    
    std::ostream& print(std::ostream& os) const override;
    
    // Aufgabe 6.6
    
    bool intersect(Ray const& ray, float& distance) const;
    
    // Aufgabe 6.8
    ~Sphere();
    Sphere(glm::vec3 const& s, float r, Color const& c, std::string const& name);
};



#endif /* defined(SPHERE_H) */
