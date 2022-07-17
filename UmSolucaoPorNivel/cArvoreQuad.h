#pragma once
#include <string> 
#include "math.h"
#include <stdlib.h>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"

class cArvoreQuad { 	

private:
	cNo *raiz;	// representa a imagem
	
	cNo* construirArvorePorRecursao(int largura, int altura, cPonto pBase, int nivel, long int &sum);
			
public:

	cArvoreQuad();
	cArvoreQuad(int altura, int largura, cPonto pBase);
	cArvoreQuad(unsigned char* imagem);
	
	~cArvoreQuad();

	void setRaiz(cNo* n);
	cNo* getRaiz();

	void desenha(int n);

	friend std::ostream &operator<<( std::ostream &output, const cArvoreQuad &r);

};
