#pragma once

#include "cNo.h"
#include "cQuadrante.h"

class cArvoreQuad { 	

private:
	cNo *raiz;	// representa a imagem

	cNo* construirArvorePorRecursao(int largura, int altura);
			
public:

	cArvoreQuad();
	cArvoreQuad(int altura, int largura);
	cArvoreQuad(unsigned char* imagem);
	
	~cArvoreQuad();

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
