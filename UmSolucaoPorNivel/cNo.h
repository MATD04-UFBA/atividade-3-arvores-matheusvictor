#pragma once

#include "cPonto.h"
#include "cQuadrante.h"

class cNo	{ 	

private:
	cQuadrante quadrante;
	
	cNo* pai;
    cNo* noSuperiorEsquerdo;
    cNo* noSuperiorDireito;
	cNo* noInferiorDireito;
	cNo* noInferiorEsquerdo;

public:
	cNo();
	cNo(cQuadrante quadrante);
	cNo(int largura, int altura, cPonto pBase);

	void setQuadrante(cQuadrante q);
	cQuadrante getQuadrante();

	void 	setPai(cNo* pai); 
	cNo* 	getPai();

	void 	setFilhoSuperiorEsquerdo(cNo* no);
	cNo* 	getFilhoSuperiorEsquerdo();

	void 	setFilhoSuperiorDireito(cNo* no);
	cNo* 	getFilhoSuperiorDireito();

	void 	setFilhoInferiorDireito(cNo* no);
	cNo* 	getFilhoInferiorDireito();

	void 	setFilhoInferiorEsquerdo(cNo* no);
	cNo* 	getFilhoInferiorEsquerdo();

	bool ehRaiz();
	bool ehFolha();

	void desenha();

	void desenhaQuadrantesPorNivel(int n);
	void setQuadIntensidade(int i);
	void setQuadNivel(int n);

		
	friend std::ostream &operator<<( std::ostream &output, const cNo &no);

};