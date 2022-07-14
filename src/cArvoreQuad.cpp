#include <iostream>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

cArvoreQuad::cArvoreQuad() {
    this->raiz = nullptr;
    // this->raiz = construirArvorePorRecursao();
}

cArvoreQuad::cArvoreQuad(int largura, int altura, cPonto pBase) {
    this->raiz = construirArvorePorRecursao(largura, altura, pBase);
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(int _largura, int _altura, cPonto pBase) {
    
    int largura = _largura;
    int altura  = _altura;

    // O código está quebrando aqui
    std::cout << "quebrei aqui" << std::endl;

    cPonto pOposto = cPonto(largura, altura);
    cQuadrante quadrante = cQuadrante(pBase, pOposto, 0); // 1ª vez: pBase = (0,0), pOposto = (7, 7)
    
    if (largura == 1 && altura == 1) return nullptr; // chegou ao pixel, não precisa mais continuar a divisão

    cNo *novoNo = new cNo(largura, altura, pBase);
    if (novoNo == nullptr) return novoNo; // alocação de novoNo mau-sucedida

    cPonto pBFSuperiorEsquerdo   = cPonto(
                                          quadrante.getPtoBase().getX(),
                                          quadrante.getPtoBase().getY()
                                        );

    cPonto pBFSuperiorDireito    = cPonto(
                                            quadrante.getPtoBase().getX() + largura / 2,
				                            quadrante.getPtoBase().getY() 
                                        );

    cPonto pBFInferiorDireito    = cPonto(
                                            quadrante.getPtoBase().getX() + largura / 2,
                                            quadrante.getPtoBase().getY() + altura / 2
                                        );
    
    cPonto pBFInferiorEsquerdo   = cPonto(
                                            quadrante.getPtoBase().getX(),
                                            quadrante.getPtoBase().getY() + altura / 2
                                        );                                        

    novoNo->setFilhoSuperiorEsquerdo( construirArvorePorRecursao(largura, altura, pBFSuperiorEsquerdo) );
    novoNo->setFilhoSuperiorDireito( construirArvorePorRecursao(largura, altura, pBFSuperiorDireito) );

    novoNo->setFilhoInferiorDireito( construirArvorePorRecursao(largura, altura, pBFInferiorDireito) );
    novoNo->setFilhoInferiorEsquerdo( construirArvorePorRecursao(largura, altura, pBFInferiorEsquerdo) );
        
    largura /= 2;
    altura /= 2;
    
    // pBase.setXY(largura, altura);

    return novoNo;

}
