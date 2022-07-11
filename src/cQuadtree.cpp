#include "cQuadtree.h"
#include "cNo.h"

cQuadtree::cQuadtree() {
    this->raiz = nullptr; 
}

void cQuadtree::setRaiz(cNo* n) {
    this->raiz = n;
}

cNo* cQuadtree::getRaiz() {
    return this->raiz;
}
