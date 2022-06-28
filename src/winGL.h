#pragma once

#include <string>

#include "cPonto.h"
#include "cQuadrante.h"

void 			desenhaQuadrante(cPonto p0, cPonto p1, int intensidade);
unsigned char* 	leImagem(std::string filename);

void 			display(void);

void 			initOpenGL (void);

void 			reshape (int w, int h);

void 			keyboard (unsigned char key, int x, int y);

void 			criaJanela(int argc, char** argv);

void 			initEventos();
