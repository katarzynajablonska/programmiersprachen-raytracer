//
//  Shape.h
//  
//
//  Created by Katarzyna Jablonska on 22.06.15.
//
//

#ifndef SHAPE_H
#define SHAPE_H

#include "color.hpp"
#include "Ray.h"

#include <string>
#include <ostream>

class Shape
{
//  Aufgabe 6.3
    
    std::string name_;
    Color color_;
    
public:
    
//  Aufgabe 6.1
    
    virtual float area() const = 0;
    virtual float volume() const = 0;
    
//  Aufgabe 6.3
    
    Shape();
    Shape(std::string const& name, Color const& color);
    Color const& get_color() const;
    std::string const& get_name() const;
    
//  Aufgabe 6.4
    virtual std::ostream& print(std::ostream& os) const;
    
//  Aufgabe 6.8
    //virtual ~Shape();
    ~Shape();
    
//  Aufgabe 7.3
    
    virtual bool intersect(Ray const& ray, float& t) const = 0;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);


#endif /* defined(SHAPE_H) */
