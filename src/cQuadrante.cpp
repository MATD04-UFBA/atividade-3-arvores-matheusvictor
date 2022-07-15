#include "winGL.h"
#include <iostream>
#include <GL/glut.h>

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

cQuadrante::cQuadrante(cPonto p1, cPonto p2, unsigned char* _imagem, int _larguraImagem){

	pBase.setXY(p1.getX(), p1.getY());
	altura 		= p2.getY() - p1.getY();
	largura 	= p2.getX() - p1.getX();
	nivel 		= 0;
	erro 		= 0.0f;
	imagem = _imagem;
	larguraImagem = _larguraImagem;

    //calcular intensidade média:        
    intensidade = 0;
    for(int i = p1.getX(); i < p2.getX(); i ++) {
		for(int j = p1.getY(); j < p2.getY(); j ++) {
			unsigned int intensidadePixel = imagem[i*larguraImagem + j]; // corrigir acesso ao pixel
			intensidade += intensidadePixel;
		}
	}
	if(altura < 1 || largura < 1) {
		intensidade = intensidade/1;
	} else {
		intensidade = intensidade/(altura*largura);
	}

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

int cQuadrante::calcularIntensidade() {
	return 0; //TODO: calcular intensidade média
}

int cQuadrante::getIntensidade() {
	return this->intensidade;
}
