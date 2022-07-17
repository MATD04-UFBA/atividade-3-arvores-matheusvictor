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
	return this->altura +1;
}

void cQuadrante::setLargura(int l) {
	this->largura = l;
}

int cQuadrante::getLargura() {
	return this->largura +1;
}

int cQuadrante::calcularIntensidade(unsigned char* imagem, int larguraImagem, int altura) {

	int intensidade = 0;

	/*
	====== Testando acesso ao valor de intensidade de um pixel específico ========

	unsigned char 	aux = imagem[7*8+7]; 
	std::cout << aux << std::endl;
	std::cout << int(aux) << std::endl;
	exit(1);

	*/

	for(int x = pBase.getX(); x < pBase.getX() + this->getLargura(); x++) {

		for(int y = pBase.getY(); y < pBase.getY() + this->getAltura(); y++) {

			unsigned int intensidadePixel = int(imagem[y*larguraImagem+x]);

			std::cout << "intensidadePixel (" <<x <<","<<y<<") = " << intensidadePixel << std::endl;
	 		intensidade += intensidadePixel;
		}
	}
	
	int intensidadeMedia = intensidade/(this->getLargura()*this->getAltura());

	return intensidadeMedia;
}

void cQuadrante::setIntensidade(int intensidade) {
	this->intensidade = intensidade;
}

int cQuadrante::getIntensidade() {
	return this->intensidade;
}

int cQuadrante::getTamanhoQuadrante() {
	return this->getLargura() * this->getAltura();
}

// ******************************************************
// ***
// ******************************************************
int cQuadrante::getNivel() {
	return this->nivel;
}

// ******************************************************
// ***
// ******************************************************
void cQuadrante::setNivel(int n) {
	this->nivel = n;
}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cQuadrante &q) { 

    output << "------------------------------"<< std::endl;
    // output << q.pBase 		<< std::endl;
    // output << q.altura 		<< " x " 
    // 						<< q.largura << std::endl;
    // output << q.nivel 		<< std::endl;
    output << q.intensidade << std::endl;
    // output << q.erro		<< std::endl;

    return output;            
}
