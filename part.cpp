#include "part.h"

part::part() {
	this->set('.');
}

part::part(char c) {
	this->set(c);
}

void part::set(char c) {
	if(c=='X'||c=='O'||c=='.') {
		this->c = c;
	}
	else throw IllegalCharException(c);
}

const char part::get()const {
	return this->c;
}

part&part::operator=(char c) {
	this->set(c);
	return *this;
}


ostream & operator<<(ostream & os, const part & s) {
	os<<s.get();
	return os;
}

square::operator char() const {
	return c;
}

bool operator==(square& s, char c){
	
	if(s.get()==c) return true;
	return false;
}