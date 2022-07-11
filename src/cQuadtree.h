#pragma once

#include "cNo.h"
#include "cQuadrante.h"

class cQuadtree { 	

private:
	cNo* raiz;	
		
public:
	cQuadtree();

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
