#pragma once

#include "cNo.h"

class cQuadtree { 	

private:
	cNo* raiz;	
		
public:
	cQuadtree();

	void setRaiz(cNo* n);
	cNo* getRaiz();

};
