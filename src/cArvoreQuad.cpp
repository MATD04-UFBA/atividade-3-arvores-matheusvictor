#include <cmath>
#include <iostream>
#include <ostream>
#include <stdlib.h>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

cArvoreQuad::cArvoreQuad() {
    this->raiz = nullptr;
}

cArvoreQuad::cArvoreQuad(int largura, int altura, cPonto pBase) {
    this->raiz = construirArvorePorRecursao(largura -1, altura - 1, pBase, 0, 1);
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(int _largura, int _altura, cPonto pBase, int nivel, int numeroQuadrante) {
    
    int largura = _largura;
    int altura  = _altura;

    cPonto pOposto = cPonto(
        (pBase.getX() + largura),
        (pBase.getY() + altura)
    );
        
    cQuadrante quadrante = cQuadrante(pBase, pOposto, 0);

    std::cout << "Tamanho do quadrante => " << quadrante.getTamnhoQuadrante() << std::endl;
	std::cout << "Intensidade media do quadrante => " << quadrante.calcularIntensidade(0, _largura, _altura) << std::endl;

    cNo *novoNo = new cNo(largura, altura, pBase);
    if (novoNo == nullptr) return novoNo; // alocação de novoNo mau-sucedida

    if (quadrante.getPtoBase().getX() == quadrante.getPtoOposto().getX() &&
        quadrante.getPtoBase().getY() == quadrante.getPtoOposto().getY()
    ) return novoNo;

    cPonto q1   = cPonto(
                                            quadrante.getPtoBase().getX(),
                                            quadrante.getPtoBase().getY()
                                        );

    cPonto q4   = cPonto(
                                            quadrante.getPtoBase().getX(),
                                            ceil( (quadrante.getPtoBase().getY() + altura) / 2) + 1
                                        );                                        

    cPonto q2    = cPonto(
                                            ceil( (quadrante.getPtoBase().getX() + largura) / 2 ) + 1,
                                            quadrante.getPtoBase().getY()
                                        );
                                        
    cPonto q3    = cPonto(
                                            ceil( (quadrante.getPtoBase().getX() + largura) / 2) + 1, 
                                            ceil( (quadrante.getPtoBase().getY() + altura) / 2) + 1
                                        );

    novoNo->setFilhoSuperiorEsquerdo( construirArvorePorRecursao(floor(_largura / 2), _altura/2, q1, nivel + 1, 1) );
    novoNo->setFilhoSuperiorDireito( construirArvorePorRecursao((_largura / 2), (_altura/2), q2, nivel + 1, 2) );
    novoNo->setFilhoInferiorDireito( construirArvorePorRecursao((_largura / 2), (_altura/2), q3, nivel + 1, 3) );
    novoNo->setFilhoInferiorEsquerdo( construirArvorePorRecursao((_largura / 2), (_altura/2), q4, nivel + 1, 4) );

    return novoNo;
}
