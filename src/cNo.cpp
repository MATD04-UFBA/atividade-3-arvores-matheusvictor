#include <cstddef>
#include <iostream>

#include "cNo.h"
#include "cQuadrante.h"

// ***********************************************
// ******                                   ******
// ***********************************************
cNo::cNo(cQuadrante* q) {
	this->quadrante = q;
}

// ***********************************************
// ******                                   ******
// ***********************************************
cQuadrante* cNo::getQuadrante() {
	return this->quadrante;
}
