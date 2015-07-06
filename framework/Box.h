//
//  Box.h
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#ifndef BOX_H
#define BOX_H

#include "Shape.h"
#include "color.hpp"
#include <glm/vec3.hpp>

class Box : public Shape
{
    glm::vec3 min_, max_;
    
public:
    Box();
    Box(glm::vec3 const& min, glm::vec3 const& max, Color const& c);
    glm::vec3 const& get_min() const;
    glm::vec3 const& get_max() const;
    float area() const override;
    float volume() const override;
    float width() const;
    float height() const;
    float length() const;
    
//  Aufgabe 6.5
    
    std::ostream& print(std::ostream& os) const override;
    
//  Aufgabe 6.8
    ~Box();
    
//  Aufgabe 7.3
    
    //bool intersect(Ray const& ray, float& t) const override;
};

#endif /* defined(BOX_H) */
