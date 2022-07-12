#pragma once

#include "cQuadrante.h"

class cNo	{ 	

private:
	cQuadrante* quadrante;

public:

	cNo(cQuadrante* q);

	cQuadrante*	getQuadrante();
};