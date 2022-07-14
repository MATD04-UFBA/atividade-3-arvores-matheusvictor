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
    
    static int numeroDeQuadrantes = 0;
    int largura = _largura;
    int altura  = _altura;

    cPonto pOposto = cPonto(largura, altura);
    
    std::cout << "pBase = " << "(" << pBase.getX() << "," << pBase.getY() << ")" << std::endl;
    std::cout << "pOposto = " << "(" << pOposto.getX() << "," << pOposto.getY() << ")" << std::endl;
    
    cQuadrante quadrante = cQuadrante(pBase, pOposto, 0);
    
    numeroDeQuadrantes++;
    std::cout << "========================================================" << std::endl;
    std::cout << "CRIADO O Q" << numeroDeQuadrantes << std::endl;
    std::cout << "========================================================" << std::endl;

    std::cout << "pBase quadrante = (" << quadrante.getPtoBase().getX() << ", " << quadrante.getPtoBase().getY() << ")" << std::endl;
    std::cout << "pOposto quadrante = (" << quadrante.getPtoOposto().getX() << ", " << quadrante.getPtoOposto().getY() << ")" << std::endl;

    
    if (largura == 1 && altura == 1) {
        // pOposto.setXY(pBase.getX(), pBase.getY());
        return nullptr; // chegou ao pixel, não precisa mais continuar a divisão
    }

    /*
	if (quadrante.getPtoBase().getX() == quadrante.getPtoOposto().getY() &&
        quadrante.getPtoBase().getY() == quadrante.getPtoOposto().getY()
    ) return nullptr;
    */

    cNo *novoNo = new cNo(largura, altura, pBase);
    if (novoNo == nullptr) return novoNo; // alocação de novoNo mau-sucedida

    cPonto pBFSuperiorEsquerdo   = cPonto(quadrante.getPtoBase().getX(), quadrante.getPtoBase().getY());
    cPonto pBFSuperiorDireito    = cPonto(quadrante.getPtoBase().getX() + largura / 2, quadrante.getPtoBase().getY());

    cPonto pBFInferiorDireito    = cPonto(quadrante.getPtoBase().getX() + largura / 2, quadrante.getPtoBase().getY() + altura / 2);
    cPonto pBFInferiorEsquerdo   = cPonto(quadrante.getPtoBase().getX(), quadrante.getPtoBase().getY() + altura / 2);                                        
    
    std::cout << "pBFSuperiorEsquerdo = (" << pBFSuperiorEsquerdo.getX() << "), (" << pBFSuperiorEsquerdo.getY() << ")" << std::endl;
    std::cout << "pBFSuperiorDireito = (" << pBFSuperiorDireito.getX() << "), (" << pBFSuperiorDireito.getY() << ")" << std::endl;

    std::cout << "pBFInferiorDireito = (" << pBFInferiorDireito.getX() << "), (" << pBFInferiorDireito.getY() << ")" << std::endl;
    std::cout << "pBFInferiorEsquerdo = (" << pBFInferiorEsquerdo.getX() << "), (" << pBFInferiorEsquerdo.getY() << ")" << std::endl;

    std::cout << "========================================================" << std::endl;

    //std::cout << "pBase quadrante = (" << quadrante.getPtoBase().getX() << "), (" << quadrante.getPtoBase().getY() << ")" << std::endl;
    //std::cout << "pOposto quadrante = (" << quadrante.getPtoOposto().getX() << "), (" << quadrante.getPtoOposto().getY() << ")" << std::endl;
    
    largura = _largura / 2;
    altura  = _largura / 2;

    novoNo->setFilhoSuperiorEsquerdo( construirArvorePorRecursao(largura, altura, pBFSuperiorEsquerdo) );

    std::cout << novoNo->getQuadrante().getPtoBase().getX() << ", ";
    std::cout << novoNo->getQuadrante().getPtoBase().getY() << std::endl;

    std::cout << novoNo->getQuadrante().getPtoOposto().getX() << ", ";
    std::cout << novoNo->getQuadrante().getPtoOposto().getY() << std::endl;

    novoNo->setFilhoSuperiorDireito( construirArvorePorRecursao(largura, altura, pBFSuperiorDireito) );

    novoNo->setFilhoInferiorDireito( construirArvorePorRecursao(largura, altura, pBFInferiorDireito) );
    novoNo->setFilhoInferiorEsquerdo( construirArvorePorRecursao(largura, altura, pBFInferiorEsquerdo) );
    
    // pBase.setXY(largura, altura);

    return novoNo;

}
