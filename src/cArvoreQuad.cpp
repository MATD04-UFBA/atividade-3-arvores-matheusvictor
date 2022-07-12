#include "cPonto.h"
#include "cNo.h"
#include "cArvoreQuad.h"

cArvoreQuad::cArvoreQuad() {
    this->raiz = nullptr;

    this->pixelBase = cPonto(0, 0);
    this->pixelOposto = cPonto(0, 0);

    this->arvoreSuperiorEsquerda = nullptr; // Q1
    this->arvoreSuperiorDireita= nullptr; // Q2
    this->arvoreInferiorDireita= nullptr; // Q3
    this->arvoreInferiorEsquerda = nullptr; // Q4    
}

cArvoreQuad::cArvoreQuad(cPonto pontoBase, cPonto pontoOposto) {
    this->raiz = nullptr;

    this->pixelBase = pontoBase;
    this->pixelOposto = pontoOposto;

    this->arvoreSuperiorEsquerda = nullptr; // Q1
    this->arvoreSuperiorDireita= nullptr; // Q2
    this->arvoreInferiorDireita= nullptr; // Q3
    this->arvoreInferiorEsquerda = nullptr; // Q4
}

void cArvoreQuad::inserir(cNo* n) {
    if (n == nullptr) {
        return;
    }

    if (this->ehLimite(n->getQuadrante()->getPtoBase())) {
        return;
    }

    if (
        abs(this->pixelBase.getX() - this->pixelOposto.getX()) <= 1 &&
        abs(this->pixelBase.getY() - this->pixelOposto.getY()) <= 1
    ) {
        if (n == nullptr) {
            this->raiz = n;
        }
        return;
    }

    if ((pixelBase.getX() + this->pixelOposto.getX()) / 2 >= this->raiz->getQuadrante()->getPtoBase().getX()) {
        // Indicates topLeftTree
        if ((pixelBase.getY() + this->pixelOposto.getY()) / 2 >= this->raiz->getQuadrante()->getPtoBase().getY()) {
            if (this->arvoreSuperiorEsquerda == nullptr)
            {
                this->arvoreSuperiorEsquerda = new cArvoreQuad(
                    cPonto(pixelBase.getX(), pixelBase.getY()),
                    cPonto((pixelBase.getX() + pixelOposto.getX()) / 2,(pixelBase.getX() + pixelOposto.getY()) / 2)
                );
                this->arvoreSuperiorEsquerda->inserir(n);
            }
        }
 
        // Indicates botLeftTree
        else {
            if (this->arvoreInferiorEsquerda == nullptr)
                this->arvoreInferiorEsquerda = new cArvoreQuad(
                    cPonto(pixelBase.getX(), (pixelBase.getY() + pixelOposto.getY()) / 2),
                    cPonto((pixelBase.getX() + pixelOposto.getX()) / 2, pixelOposto.getY())
                );
            this->arvoreInferiorEsquerda->inserir(n);
        }
    }

    else {
        // Indicates topRightTree
        if ((pixelBase.getY() + pixelOposto.getY()) / 2 >= n->getQuadrante()->getPtoBase().getY()) {
            if (this->arvoreSuperiorDireita == nullptr) {
                this->arvoreSuperiorDireita = new cArvoreQuad(
                    cPonto((pixelBase.getX() + pixelOposto.getX()) / 2, pixelBase.getY()),
                    cPonto(pixelOposto.getX(), (pixelBase.getY() + pixelOposto.getY()) / 2));
            }
            this->arvoreSuperiorDireita->inserir(n);
        }
 
        // Indicates botRightTree
        else {
            if (this->arvoreInferiorDireita == nullptr)
                this->arvoreInferiorDireita = new cArvoreQuad(
                    cPonto((pixelBase.getX() + pixelOposto.getX()) / 2, (pixelBase.getY() + pixelOposto.getY()) / 2),
                    cPonto(pixelOposto.getX(), pixelOposto.getY()));
            this->arvoreInferiorDireita->inserir(n);
        }
    }

    

}

// Check if current quadtree contains the point
bool cArvoreQuad::ehLimite(cPonto p)
{
    return (p.getX() >= pixelBase.getX() && p.getX() <= pixelOposto.getX() &&
            p.getY() >= pixelBase.getY() && p.getY() <= pixelOposto.getY());
}