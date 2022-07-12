#pragma once

#include "cPonto.h"

class cQuadrante { 	

private:
	cPonto	pBase;
	int 	altura,largura;
	int 	nivel;
	int		intensidade;
	float	erro;
		
public:
	cQuadrante();
	cQuadrante(cPonto p0, cPonto p1, int i);
	
	cPonto 	getPtoBase();
	cPonto 	getPtoOposto();
	int 	getIntensidade();

};
