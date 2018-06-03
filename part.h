#pragma once
#include <iostream>
#include <string>
#include "IllegalCharException.h"
using namespace std;

class part{
	
public:

	char c;
	
	part();
	part(char);
	
	const char get()const;
	void set(char c);
	
	part& operator = (char);
	operator char() const;
	friend ostream& operator <<(ostream&, const part&);
	friend bool operator==(part&, char);
	
};