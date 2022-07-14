#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

cArvoreQuad::cArvoreQuad() {
    this->raiz = new cNo();
    // this->raiz = construirArvorePorRecursao();
}

cArvoreQuad::cArvoreQuad(int largura, int altura, cPonto pBase, cPonto pOposto) {
    this->raiz = construirArvorePorRecursao(largura, altura, pBase, pOposto);
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(int largura, int altura, cPonto pBase, cPonto pOposto) {
    
    // cPonto     pontoBase = p;
    cQuadrante quadrante = cQuadrante(pBase, pOposto, 0);

    if (largura == 1 && altura == 1) return nullptr; // chegou ao pixel, não precisa mais continuar a divisão

    cNo *novoNo = new cNo(largura, altura, pBase);
    if (novoNo == nullptr) return novoNo; // alocação de novoNo mau-sucedida

    // int p0 = p.getX();

    cPonto pBFSuperiorEsquerdo   = cPonto(pBase.getX(), pBase.getY());
    cPonto pBFSuperiorDireito    = cPonto();

    cPonto pBFInferiorDireito    = cPonto();
    cPonto pBFInferiorEsquerdo   = cPonto(quadrante.getPtoBase().getX(), (quadrante.getPtoOposto().getY() / 2) + 1);

    // pBase.setXY(l, a);

    // novoNo->setFilhoSuperiorEsquerdo(construirArvorePorRecursao(l, 0, pBFSuperiorEsquerdo, pBFSuperiorEsquerdo));
    // novoNo->setFilhoSuperiorDireito(construirArvorePorRecursao(l, a));

    // novoNo->setFilhoInferiorDireito(construirArvorePorRecursao(l, a));
    // novoNo->setFilhoInferiorEsquerdo(construirArvorePorRecursao(l, a));

    return novoNo;

}
