//
//  Material.h
//  
//
//  Created by Katarzyna Jablonska on 06.07.15.
//
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "color.hpp"

class Material
{
    std::string name;
    Color ka, kd, ks;
    float m;
};

#endif /* defined(MATERIAL_H) */
