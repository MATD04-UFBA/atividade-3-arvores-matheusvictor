#include <cstddef>
#include <iostream>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"


cNo::cNo() {

	this->quadrante = cQuadrante();

	this->pai 				  = nullptr;
	this->noSuperiorEsquerdo  = nullptr;
    this->noSuperiorDireito   = nullptr;
	this->noInferiorEsquerdo  = nullptr;
	this->noInferiorDireito   = nullptr;
}

// TODO, verificar como alterar isso tudo para apenas um quadrante como parametro
cNo::cNo(int altura, int largura, cPonto pBase, unsigned char * imagem, int larguraImagem) {

	this->quadrante = cQuadrante(pBase, cPonto(altura, largura), imagem, larguraImagem);

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
