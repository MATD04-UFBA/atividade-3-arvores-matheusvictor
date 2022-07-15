#include "winGL.h"
#include <iostream>
#include <GL/glut.h>
#include <string> 

#include "cPonto.h"
#include "cQuadrante.h"

#include "compressao.h"


cQuadrante::cQuadrante() {

	pBase.setXY(0, 0);
	altura		= 0;
	largura		= 0;
	nivel 		= 0;
	intensidade = 0;
	erro 		= 0.0f;
}

cQuadrante::cQuadrante(cPonto p1, cPonto p2, int i){

	pBase.setXY(p1.getX(), p1.getY());
	altura 		= p2.getY() - p1.getY();
	largura 	= p2.getX() - p1.getX();
	nivel 		= 0;
	intensidade = i;
	erro 		= 0.0f;
}

void cQuadrante::setPtoBase(int p0, int p1) {
	this->pBase = cPonto(p0, p1);
}

cPonto cQuadrante::getPtoBase() {

	cPonto p(pBase);

	return p;
}

cPonto cQuadrante::getPtoOposto() {

	cPonto p(pBase.getX() + largura, pBase.getY() + altura);

	return p;
}

void cQuadrante::setAltura(int a) {
	this->altura = a;
}

int cQuadrante::getAltura() {
	return this->altura;
}

void cQuadrante::setLargura(int l) {
	this->largura = l;
}

int cQuadrante::getLargura() {
	return this->largura;
}

int cQuadrante::calcularIntensidade(unsigned char* imagem, int largura, int altura) {

	int intensidade = 0;

	for(int i = 0; i < largura; i ++) {

		for(int j = 0; j < altura; j ++) {
			unsigned int intensidadePixel = imagem[i*largura+j];
	 		intensidade += intensidadePixel;
		}
	}
	
	int intensidadeMedia = intensidade/(largura*altura);

	return intensidadeMedia;
}

void cQuadrante::setIntensidade(int intensidade) {
	this->intensidade = intensidade;
}

int cQuadrante::getIntensidade() {
	return this->intensidade;
}

int cQuadrante::getTamnhoQuadrante() {
	return this->largura * this->altura;
}