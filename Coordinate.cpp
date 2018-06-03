#include "Coordinate.h"

Coordinate::Coordinate(uint i,uint j){
	this->x=i;
	this->y=j;
}

Coordinate::Coordinate(int i,int j){
	
	i=(uint)i;
	j=(uint)j;
	this->x=i;
	this->y=j;
}