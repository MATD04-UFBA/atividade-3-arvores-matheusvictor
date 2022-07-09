#include <cstddef>
#include <iostream>

#include "cNo.h"
#include "cQuadrante.h"

// ***********************************************
// ******                                   ******
// ***********************************************
cNo::cNo(cQuadrante* q) {
	this->quadrante = q;

	noSuperiorEsquerdo  = nullptr;
    noSuperiorDireito   = nullptr;
	noInferiorEsquerdo  = nullptr;
	noInferiorDireito  	= nullptr;
}

// ***********************************************
// ******                                   ******
// ***********************************************
void cNo::addNosFilhos(cNo *n1, cNo *n2, cNo *n3, cNo *n4) {
	noSuperiorEsquerdo  = n1;
    noSuperiorDireito   = n2;
	noInferiorDireito  	= n3;
	noInferiorEsquerdo  = n4;

	noSuperiorEsquerdo->setPai(this);
    noSuperiorDireito->setPai(this);
	noInferiorDireito->setPai(this);
	noInferiorEsquerdo->setPai(this);
}

// ***********************************************
// ******                                   ******
// ***********************************************
cQuadrante* cNo::getQuadrante() {
	return this->quadrante;
}

// ***********************************************
// ******                                   ******
// ***********************************************
bool cNo::ehRaiz() {
	return this->pai == nullptr;
}

// ***********************************************
// ******                                   ******
// ***********************************************
bool cNo::ehFolha() {
	return this->noSuperiorEsquerdo == nullptr &&
	this->noSuperiorDireito == nullptr &&
	this->noInferiorEsquerdo == nullptr &&
	this->noInferiorDireito == nullptr;
}
