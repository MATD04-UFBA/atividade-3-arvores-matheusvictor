#pragma once

#include "cPonto.h"

class cQuadrante { 	

private:
	cPonto	pBase;
	int 	altura,largura;
	int 	nivel;
	int		intensidade;
	unsigned char* imagem;
	int larguraImagem;
	float	erro;
		
public:
	cQuadrante();
	cQuadrante(cPonto p0, cPonto p1, unsigned char* _imagem, int _larguraImagem);
	
	void 	setPtoBase(int p0, int p1);
	cPonto 	getPtoBase();

	cPonto 	getPtoOposto();
	
	void	setAltura(int a);
	int 	getAltura();

	void	setLargura(int l);
	int 	getLargura();

	int 	calcularIntensidade();	 
	int 	getIntensidade();
};
