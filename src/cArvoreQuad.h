#pragma once

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"

class cArvoreQuad { 	

private:
	cNo *raiz;	// representa a imagem

	cNo* construirArvorePorRecursao(int largura, int altura, cPonto pBase, cPonto pOposto);
			
public:

	cArvoreQuad();
	cArvoreQuad(int altura, int largura, cPonto p, cPonto pOposto);
	cArvoreQuad(unsigned char* imagem);
	
	~cArvoreQuad();

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
