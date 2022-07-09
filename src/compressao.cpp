#include <cmath>
#include <string>
#include <cstdlib>
#include <iostream>

#include <GL/glut.h>

#include "winGL.h"

#include "cNo.h"
#include "cPonto.h"
#include "cQuadrante.h"
#include "cQuadtree.h"

#include "compressao.h"
		
unsigned char* 	image = NULL;	// image file
int 			iHeight, 
				iWidth,
				iChannels;

bool 			desenha = false;


// *****************************************************
// ***                                               ***
// *****************************************************
void desenhaArvore() {

	printf("Aqui eu vou desenhar a arvore\n");
	
	// rotina que deve ser implementada para visualizacao da arvore
	// utilize a rotina desenhaQuadrante(p0, p1, cor)
	// fornecendo os pontos inicial e final do quadrante e a sua cor
	// funcao do valor do pixel ou da regiao que voce quer desenhar
	
	cPonto p0(0,0);
	cPonto p1(iWidth/2, iHeight/2);
	cPonto p2(iWidth, iHeight);
	 
	cQuadrante q0(p0, p1, 64);
	cQuadrante q1(p2, p1, 222);

	desenhaQuadrante(q0.getPtoBase(), q0.getPtoOposto(), q0.getIntensidade());
	desenhaQuadrante(q1.getPtoBase(), q1.getPtoOposto(), q1.getIntensidade());
}

// *****************************************************
// ***                                               ***
// *****************************************************
void montaArvore() {
	
	cQuadtree  *arvore = new cQuadtree();

	cPonto pontoBase(0,0);
	cPonto pontoOposto(iWidth, iHeight);

	cQuadrante *quadrante = new cQuadrante(pontoBase, pontoOposto, 0); // TODO: corrigir intensidade

	cNo *raiz = new cNo(quadrante);

	arvore->setRaiz(raiz);
	
	printf("Aqui eu vou montar a arvore\n");
	
	// codifique aqui a sua rotina de montagem da arvore 
	
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
