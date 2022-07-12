#include <cmath>
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


vector<cQuadrante> obterQuadrantesFilhos(cQuadrante* quadrante) {
	vector<cQuadrante> quadrantesFilhos;

	if (
		quadrante->getPtoBase().getX() == quadrante->getPtoOposto().getX() &&
		quadrante->getPtoBase().getY() == quadrante->getPtoOposto().getY()
	) {
		return quadrantesFilhos;
	}

	quadrantesFilhos.push_back(
		cQuadrante(
			quadrante->getPtoBase(),
			cPonto(
				quadrante->getPtoOposto().getX() / 2, 
				quadrante->getPtoOposto().getY() / 2
			),
			0 // corrigir calculo da intensidade
		)
	); //q1

	quadrantesFilhos.push_back(
		cQuadrante(
			cPonto(
				quadrante->getPtoOposto().getX() / 2 +1,
				quadrante->getPtoBase().getY() 
			),
			cPonto(
				quadrante->getPtoOposto().getX(), 
				quadrante->getPtoOposto().getY() / 2
			),
			0 // corrigir calculo da intensidade
		)
	); //q2

	quadrantesFilhos.push_back(
		cQuadrante(
			cPonto(
				quadrante->getPtoOposto().getX() / 2 +1,
				quadrante->getPtoOposto().getY() / 2 +1 
			),
			quadrante->getPtoOposto(),
			0 // corrigir calculo da intensidade
		)
	); //q3


	quadrantesFilhos.push_back(
		cQuadrante(
			cPonto(
				quadrante->getPtoBase().getX(),
				quadrante->getPtoOposto().getY() / 2 +1 
			),
			cPonto(
				quadrante->getPtoOposto().getX() / 2, 
				quadrante->getPtoOposto().getY()
			),
			0 // corrigir calculo da intensidade
		)
	); //q4

	return quadrantesFilhos; 
}

// *****************************************************
// ***                                               ***
// *****************************************************
void montaArvore() {
		
	cPonto pontoBase = cPonto(0,0);
	cPonto pontoOposto = cPonto(iWidth, iHeight);

	cArvoreQuad *arvore = new cArvoreQuad(pontoBase, pontoOposto);
	
	// //calcular intensidade média:	
	// int intensidade = 0;
	// for(int i = 0; i < iWidth; i ++) {
	// 	for(int j = 0; j < iHeight; j ++) {
	// 		unsigned int intensidadePixel = image[i*iWidth+j];
	// 		intensidade += intensidadePixel;
	// 	}
	// }
	
	// int intensidadeMedia = intensidade/(iWidth*iHeight);
	// std::cout << "Intensidade media => " << intensidadeMedia << std::endl;

	// cQuadrante *quadrante = new cQuadrante(pontoBase, pontoOposto, intensidadeMedia);

	// cNo *noRaiz = new cNo(quadrante);
	// arvore->setRaiz(noRaiz);
	// std::cout << "No raiz" << arvore->getRaiz() << endl;

	// cNo* noAtual = arvore->getRaiz();
	
	// // faça até que o quadrante tenha apenas 1 pixel
	// while(true) {

	// 	vector<cQuadrante> quadrantesFilhos = obterQuadrantesFilhos(noAtual->getQuadrante());

	// 	if (quadrantesFilhos.empty()) {
	// 		break;
	// 	}

	// 	cNo* noSuperiorEsquerdo  = new cNo(&quadrantesFilhos[0]);
    // 	cNo* noSuperiorDireito   = new cNo(&quadrantesFilhos[1]);
	// 	cNo* noInferiorDireito   = new cNo(&quadrantesFilhos[2]);
	// 	cNo* noInferiorEsquerdo  = new cNo(&quadrantesFilhos[3]);

	// } 
	
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
