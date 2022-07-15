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

cArvoreQuad::cArvoreQuad(
    int largura,
    int altura,
    cPonto pBase,
    unsigned char* imagem
) {
    this->raiz = construirArvorePorRecursao(largura -1, altura - 1, pBase, 0, 1, imagem, largura);
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(
    int _largura,
    int _altura,
    cPonto pBase,
    int nivel,
    int numeroQuadrante,
    unsigned char* imagem,
    int larguraImagem
) {
    
    int largura = _largura;
    int altura  = _altura;

    cPonto pOposto = cPonto(
        (pBase.getX() + largura),
        (pBase.getY() + altura)
    );
        
    cQuadrante quadrante = cQuadrante(pBase, pOposto, imagem, larguraImagem);
    cNo *novoNo = new cNo(largura, altura, pBase, imagem, larguraImagem);

    std::cout << "========================================================" << std::endl;
    std::cout << "NIVEL " << nivel << std::endl; //getNivel
    std::cout << "CRIADO O Q" << numeroQuadrante << std::endl;
    std::cout << "========================================================" << std::endl;

    std::cout << "pBase quadrante = (" << quadrante.getPtoBase().getX() << ", " << quadrante.getPtoBase().getY() << ")" << std::endl;
    std::cout << "pOposto quadrante = (" << quadrante.getPtoOposto().getX() << ", " << quadrante.getPtoOposto().getY() << ")" << std::endl;
    std::cout << "intensidade quadrante = " << quadrante.getIntensidade() << std::endl;

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

    novoNo->setFilhoSuperiorEsquerdo( construirArvorePorRecursao((_largura / 2), _altura/2, q1, nivel + 1, 1, imagem, larguraImagem) );
    novoNo->setFilhoSuperiorDireito( construirArvorePorRecursao((_largura / 2), (_altura/2), q2, nivel + 1, 2, imagem, larguraImagem) );
    novoNo->setFilhoInferiorDireito( construirArvorePorRecursao((_largura / 2), (_altura/2), q3, nivel + 1, 3, imagem, larguraImagem) );
    novoNo->setFilhoInferiorEsquerdo( construirArvorePorRecursao((_largura / 2), (_altura/2), q4, nivel + 1, 4, imagem, larguraImagem) );

    return novoNo;
}
