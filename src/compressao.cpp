#include <cmath>
#include <math.h>
#include <iterator>
#include <ostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <GL/glut.h>

#include "winGL.h"

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cArvoreQuad.h"

#include "compressao.h"

		
using namespace std;	

unsigned char* 	image = NULL;	// image file
int 			iHeight, 
				iWidth,
				iChannels;

bool 			desenha = false;

cArvoreQuad *arvore = NULL;

// *****************************************************
// ***                                               ***
// *****************************************************
void desenhaArvore() {

	arvore->desenha();
}

void montaArvore() {
		
	cPonto pontoBase = cPonto(0,0);
	arvore = new cArvoreQuad(iWidth, iHeight, pontoBase);

	std::cout << "arvore Montada" << std::endl;
	std::cout << *arvore << std::endl;
	std::cout << "********************" << std::endl;


	// cQuadrante quadrante = cQuadrante(cPonto(0,0), cPonto(iWidth, iHeight), 0);

	// std::cout << "Imagem => " << image << std::endl;

	// std::cout << "Tamanho do quadrante => " << quadrante.getTamnhoQuadrante() << std::endl;
	// std::cout << "Intensidade media => " << quadrante.calcularIntensidade(image, iWidth, iHeight) << std::endl;


	// cNo *noRaiz = new cNo(quadrante);
	// arvore->setRaiz(noRaiz);
	// std::cout << "No raiz" << arvore->getRaiz() << endl;

	// cNo* noAtual = arvore->getRaiz();
	
}


// *****************************************************
// ***                                               ***
// *****************************************************
void teclado(unsigned char key, int x, int y) {

	switch (key) {
		case 27		: 	exit(0);
						break;				
		case 'q'	:
		case 'Q'	: 	montaArvore();
						break;				
		case 'i'	:
		case 'I'	: 	desenha = !desenha;
						break;				
		}
	glutPostRedisplay();
}

// *****************************************************
// ***                                               ***
// *****************************************************
void mouse(int button, int button_state, int x, int y ) {

	if 	(button_state == GLUT_DOWN ) {
		switch (button) {
			
			case GLUT_LEFT_BUTTON	: 	printf("botao esquerdo?\n");
										break;
	
			case GLUT_RIGHT_BUTTON	:	printf("botao direito?\n");
										break;
			}
		glutPostRedisplay();
		}
}

// *****************************************************
// ***                                               ***
// *****************************************************
void desenho(void) {

    glClear (GL_COLOR_BUFFER_BIT); 
    
    glColor3f (1.0, 1.0, 1.0);
    
    if (desenha)
    	desenhaArvore();
    else
    	glDrawPixels( iWidth, iHeight, GL_LUMINANCE, GL_UNSIGNED_BYTE, image );
   	
    glutSwapBuffers ();
}

// *****************************************************
// ***                                               ***
// *****************************************************
int main(int argc, char** argv) {
	
std::string filename("images/lena.png");

    if (argc > 1)
		filename = argv[1];

	image = leImagem(filename);
			
	criaJanela(argc, argv);

    initOpenGL();
    
    initEventos();

    return 0;   
}
