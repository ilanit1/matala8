#pragma once
#include <iostream>
#include <string>
#include "Board.h"
class IllegalCoordinateException{
public:
    int i,j;
    IllegalCoordinateException(int,int);
    string theCoordinate() const;
};