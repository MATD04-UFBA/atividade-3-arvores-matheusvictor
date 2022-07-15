#include <cstddef>
#include <iostream>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"

#include "winGL.h"


cNo::cNo() {

	this->quadrante = cQuadrante();

	this->pai 				  = nullptr;
	this->noSuperiorEsquerdo  = nullptr;
    this->noSuperiorDireito   = nullptr;
	this->noInferiorEsquerdo  = nullptr;
	this->noInferiorDireito   = nullptr;
}

cNo::cNo(int altura, int largura, cPonto pBase) {

	this->quadrante = cQuadrante(pBase, cPonto(altura, largura), 0);

	this->pai 				  = nullptr;
	this->noSuperiorEsquerdo  = nullptr;
    this->noSuperiorDireito   = nullptr;
	this->noInferiorEsquerdo  = nullptr;
	this->noInferiorDireito   = nullptr;
}

void cNo::setPai(cNo* pai) {
	this->pai = pai;	
}

cNo* cNo::getPai() {
	return this->pai;
}

cQuadrante cNo::getQuadrante() {
	return this->quadrante;
}

void cNo::setFilhoSuperiorEsquerdo(cNo *no) {
	this->noSuperiorEsquerdo = no;
}

cNo* cNo::getFilhoSuperiorEsquerdo() {
	return this->noSuperiorEsquerdo;
}

void cNo::setFilhoSuperiorDireito(cNo *no) {
	this->noSuperiorDireito = no;
}

cNo* cNo::getFilhoSuperiorDireito() {
	return this->noSuperiorDireito;
}

void cNo::setFilhoInferiorDireito(cNo *no) {
	this->noInferiorDireito = no;
}

cNo* cNo::getFilhoInferiorDireito() {
	return this->noInferiorDireito;
}

void cNo::setFilhoInferiorEsquerdo(cNo *no) {
	this->noInferiorEsquerdo = no;
}

cNo* cNo::getFilhoInferiorEsquerdo() {
	return this->noInferiorEsquerdo;
}

bool cNo::ehRaiz() {
	return this->pai == nullptr;
}

bool cNo::ehFolha() {
	return this->noSuperiorEsquerdo == nullptr &&
	this->noSuperiorDireito == nullptr &&
	this->noInferiorEsquerdo == nullptr &&
	this->noInferiorDireito == nullptr;
}

void cNo::setQuadIntensidade(int i) {

	quadrante.setIntensidade(i);
}

// ******************************************************
// ***
// ******************************************************
void cNo::desenha() {

	desenhaQuadrante(quadrante.getPtoBase(), quadrante.getPtoOposto(), quadrante.getIntensidade());

	if (noSuperiorDireito)
		noSuperiorDireito->desenha();
	if (noSuperiorEsquerdo)
		noSuperiorEsquerdo->desenha();
	if (noInferiorDireito)
		noInferiorDireito->desenha();
	if (noInferiorEsquerdo)
		noInferiorEsquerdo->desenha();

}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cNo &no) { 

    output << no.quadrante << std::endl;

    if (no.noSuperiorEsquerdo)
    	output << *(no.noSuperiorEsquerdo) << std::endl;

    if (no.noSuperiorDireito)
    	output << *(no.noSuperiorDireito) << std::endl;

    if (no.noInferiorEsquerdo)
    	output << *(no.noInferiorEsquerdo) << std::endl;

    if (no.noInferiorDireito)
    	output << *(no.noInferiorDireito);

    return output;            
}
