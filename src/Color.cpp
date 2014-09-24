/*
 * Color.cpp
 *
 *  Created on: 31 ao�t 2014
 *      Author: Romain
 */

#include "Color.hpp"

Color::value Color::getOppositeColor(Color::value c)
{
    static Color::value opposite[] = {WHITE, BLACK};
    return opposite[c];
}

