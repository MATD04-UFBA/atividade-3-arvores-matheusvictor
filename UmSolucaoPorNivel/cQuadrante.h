#pragma once

#include <string>
 
#include "cPonto.h"

class cQuadrante { 	

private:
	cPonto	pBase;
	int 	altura,largura;
	int 	nivel;
	int		intensidade;
	float	erro;
		
public:
	cQuadrante();
	cQuadrante(cPonto p0, cPonto p1, int i);
	
	void 	setPtoBase(int p0, int p1);
	cPonto 	getPtoBase();

	cPonto 	getPtoOposto();
	
	void	setAltura(int a);
	int 	getAltura();

	void	setLargura(int l);
	int 	getLargura();

	int 	calcularIntensidade(unsigned char* imagem, int largura, int altura);	 
	void 	setIntensidade(int intensidade);
	int 	getIntensidade();

	int 	getTamanhoQuadrante();

	int 	getNivel();
	void 	setNivel(int n);

	friend std::ostream &operator<<( std::ostream &output, const cQuadrante &q);

};
