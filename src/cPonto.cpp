#include <iostream>

#include "cPonto.h"

cPonto::cPonto() {
	this->x = 0;
	this->y = 0;
}

cPonto::cPonto(int x, int y) {
	this->x = x;
	this->y = y;
}

cPonto::cPonto(const cPonto& p) {

	x = p.x;
	y = p.y;
}

int cPonto::getX() {
	return x;
}

int cPonto::getY() {
	return y;
}

void cPonto::setX(int x) {
	this->x = x; 
}

void cPonto::setY(int y) {
	this->y = y;
}

void cPonto::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}
	
// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cPonto &p) { 

    output << "( " << p.x << " , " << p.y << " )" << std::endl;

    return output;            
}

