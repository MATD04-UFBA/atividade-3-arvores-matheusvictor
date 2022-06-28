#include <iostream>

#include <GL/glut.h>

#include "cPonto.h"
#include "cQuadrante.h"
#include "winGL.h"
#include "compressao.h"

// *****************************************************
// ***                                               ***
// *****************************************************
cQuadrante::cQuadrante() {

	pBase.setXY(0, 0);
	h 			= 
	w 			= 0;
	nivel 		= 0;
	intensidade = 0;
	erro 		= 0.0f;
}

// *****************************************************
// ***                                               ***
// *****************************************************
cQuadrante::cQuadrante(cPonto p, cPonto q, int i){

	pBase.setXY(p.getX(), p.getY());
	h 			= q.getY() - p.getY();
	w 			= q.getX() - p.getX();
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

	cPonto p(pBase.getX() + w, pBase.getY() + h);

	return p;
}

// *****************************************************
// ***                                               ***
// *****************************************************
int cQuadrante::getIntensidade() {

	return intensidade;
}
