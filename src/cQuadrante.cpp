#include "winGL.h"
#include <iostream>
#include <GL/glut.h>

#include "cPonto.h"
#include "cQuadrante.h"

#include "compressao.h"

// *****************************************************
// ***                                               ***
// *****************************************************
cQuadrante::cQuadrante() {

	pBase.setXY(0, 0);
	altura		= 0;
	largura		= 0;
	nivel 		= 0;
	intensidade = 0;
	erro 		= 0.0f;
}

// *****************************************************
// ***                                               ***
// *****************************************************
cQuadrante::cQuadrante(cPonto p1, cPonto p2, int i){

	pBase.setXY(p1.getX(), p1.getY());
	altura 		= p2.getY() - p1.getY();
	largura 	= p2.getX() - p1.getX();
	nivel 		= 0;
	intensidade = i;
	erro 		= 0.0f;
}

// *****************************************************
// ***                                               ***
// *****************************************************
cPonto cQuadrante::getPtoBase() {

	cPonto p(pBase);

	return p;
}

// *****************************************************
// ***                                               ***
// *****************************************************
cPonto cQuadrante::getPtoOposto() {

	cPonto p(pBase.getX() + largura, pBase.getY() + altura);

	return p;
}

// *****************************************************
// ***                                               ***
// *****************************************************
int cQuadrante::getIntensidade() {
	return this->intensidade;
}
