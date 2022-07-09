#include "cNo.h"
#include "cQuadtree.h"

cQuadtree::cQuadtree() {
    this->raiz = nullptr; 
}

void cQuadtree::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cQuadtree::getRaiz() {
    return this->raiz;
}
