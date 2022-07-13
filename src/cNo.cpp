#include <cstddef>
#include <iostream>

#include "cNo.h"
#include "cQuadrante.h"


cNo::cNo() {
	
	this->quadrante.setAltura(0);
	this->quadrante.setLargura(0);

	this->pai 				  = nullptr;
	this->noSuperiorEsquerdo  = nullptr;
    this->noSuperiorDireito   = nullptr;
	this->noInferiorEsquerdo  = nullptr;
	this->noInferiorDireito   = nullptr;
}

cNo::cNo(int altura, int largura, cPonto pBase) {

	this->quadrante.setAltura(altura);
	this->quadrante.setLargura(largura);
	pBase.setXY(0, 0);

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
