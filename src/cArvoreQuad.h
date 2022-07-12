#pragma once

#include "math.h"

#include "cNo.h"
#include "cArvoreQuad.h"
#include "cPonto.h"
#include "cQuadrante.h"

class cArvoreQuad { 	

private:
	cNo* raiz;

	cPonto pixelBase;
	cPonto pixelOposto;
 
    // Children of this tree
    cArvoreQuad* arvoreSuperiorEsquerda;
    cArvoreQuad* arvoreSuperiorDireita;
    cArvoreQuad* arvoreInferiorDireita;
    cArvoreQuad* arvoreInferiorEsquerda;	
		
public:
	cArvoreQuad();
	cArvoreQuad(cPonto pontoBase, cPonto pontoOposto);

	void inserir(cNo* n);
    bool ehLimite(cPonto p);

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
