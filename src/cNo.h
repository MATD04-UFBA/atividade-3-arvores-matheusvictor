#pragma once

#include "cQuadrante.h"

class cNo	{ 	

private:
	cQuadrante* quadrante;
	
	cNo* pai;
    cNo* noSuperiorEsquerdo;
    cNo* noSuperiorDireito;
	cNo* noInferiorEsquerdo;
	cNo* noInferiorDireito;

	void setPai(cNo* pai); 

public:

	cNo(cQuadrante* q);

	void addNosFilhos(cNo *n1, cNo *n2, cNo *n3, cNo *n4);

	cQuadrante*	getQuadrante();

	bool ehRaiz();
	bool ehFolha();

};