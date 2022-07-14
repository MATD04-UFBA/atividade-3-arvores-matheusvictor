#pragma once

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"

class cArvoreQuad { 	

private:
	cNo *raiz;	// representa a imagem

	cNo* construirArvorePorRecursao(int largura, int altura, cPonto pBase);
			
public:

	cArvoreQuad();
	cArvoreQuad(int altura, int largura, cPonto pBase);
	cArvoreQuad(unsigned char* imagem);
	
	~cArvoreQuad();

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
