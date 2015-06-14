/*
 * Utils.hpp
 *
 *  Created on: 24 sept. 2014
 *      Author: Romain
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <iostream>
#include <math.h>

#include "Board.hpp"

namespace Utils
{

    void getCastling(std::string const& castleString, bool (&castleBool)[4]);
    void getCastling(std::string const& castleString, int &castlingRights);
    int convertStringToInt(std::string const& fenMoveCounter);
    void getPerformanceIndicator();
    inline constexpr int getOppositeColor(const int color){return (1+color)%2;};
};


#endif /* UTILS_HPP_ */
