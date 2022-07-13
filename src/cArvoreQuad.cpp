#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

cArvoreQuad::cArvoreQuad() {
    this->raiz = new cNo();
    // this->raiz = construirArvorePorRecursao();
}

cArvoreQuad::cArvoreQuad(int largura, int altura) {
    
    cPonto pontoBase = cPonto(0, 0);
    cQuadrante quadrante = cQuadrante();

    quadrante.getPtoOposto();
    this->raiz->setQuadrante(quadrante);
    this->raiz = new cNo();
    // this->raiz = construirArvorePorRecursao();
    
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(int largura, int altura) {
    
    if (largura == 1 && altura == 1) return nullptr; // chegou ao pixel, não precisa mais continuar a divisão

    cNo *novoNo = new cNo();
    if (novoNo == nullptr) return novoNo; // alocação mau-sucedida

}
