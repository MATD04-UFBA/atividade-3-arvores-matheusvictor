#include <cmath>
#include <iostream>
#include <ostream>
#include <stdlib.h>

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

extern unsigned char* image;
extern int 		iHeight, 
				iWidth,
				iChannels;

cArvoreQuad::cArvoreQuad() {
    this->raiz = nullptr;
}

cArvoreQuad::cArvoreQuad(int largura, int altura, cPonto pBase) {

    long int soma;

    this->raiz = construirArvorePorRecursao(largura, altura, pBase, 0, soma);
}

void cArvoreQuad::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cArvoreQuad::getRaiz() {
    return this->raiz;
}

cNo* cArvoreQuad::construirArvorePorRecursao(int _largura, int _altura, cPonto pBase, int nivel, long int &sum) {

long int soma;

    sum = 0;

    if (_largura == 0 && _altura == 0) {
        return NULL;
        }

    int largura = _largura / 2;
    int altura = _altura / 2;

    cPonto pOposto = cPonto(    (pBase.getX() + _largura),
                                (pBase.getY() + _largura)
                            );
        
    cQuadrante quadrante = cQuadrante(pBase, pOposto, 0);

    cNo *novoNo = new cNo(quadrante);
    if (novoNo == nullptr) 
        return novoNo; // alocação de novoNo mau-sucedida

    if (_largura == 1 && _altura == 1) 
        sum = int(image[pBase.getY() * iWidth + pBase.getX()]);
        
    else {        

        cPonto q1   = cPonto(   pBase.getX(),
                                pBase.getY() );

        cPonto q4   = cPonto(   pBase.getX(),
                                pBase.getY() + altura);                                        

        cPonto q2    = cPonto(  pBase.getX() + largura,
                                pBase.getY() );
                                            
        cPonto q3    = cPonto(  pBase.getX() + largura, 
                                pBase.getY() + altura);


        novoNo->setFilhoSuperiorEsquerdo( construirArvorePorRecursao(largura, altura, q1, nivel + 1, soma) );
        sum += soma;
        novoNo->setFilhoSuperiorDireito( construirArvorePorRecursao(largura, altura, q2, nivel + 1, soma) );
        sum += soma;
        novoNo->setFilhoInferiorDireito( construirArvorePorRecursao(largura, altura, q3, nivel + 1, soma) );
        sum += soma;
        novoNo->setFilhoInferiorEsquerdo( construirArvorePorRecursao(largura, altura, q4, nivel + 1, soma) );
        sum += soma;
        }
    
    novoNo->setQuadIntensidade(sum/(_altura*_largura));
    novoNo->setQuadNivel(nivel);
    return novoNo;
}

// ******************************************************
// ***
// ******************************************************
void cArvoreQuad::desenha(int n) {

    if (raiz)
        raiz->desenhaQuadrantesPorNivel(n);
}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cArvoreQuad &r) {

    output << *(r.raiz) << std::endl;

    return output;

} 
