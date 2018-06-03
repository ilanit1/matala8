#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
#include "Coordinate.h"
#include "part.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};


class Board{

public:
	part** board;
	int size;
	
	Board();
	Board(int);
	Board(const Board&);
	~Board();
	
	void makeO(RGB rgb[] ,int row, int col, int numPixel);
	void makeX(RGB rgb[], int col, int row, int numPixel);
	void makeTable(RGB rgb[], int numPixel);
	
	part& operator [](Coordinate c);
	Board& operator =(char);
	Board& operator =(Board&);
	
	friend ostream& operator <<(ostream&, const Board&);
	friend std::istream& operator>> (std::istream &input, Board& board);
	
	string draw(int pixel);
};