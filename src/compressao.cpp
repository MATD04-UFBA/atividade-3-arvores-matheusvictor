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
#include "cQuadtree.h"

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
	
	// cPonto p0(0,0);
	// cPonto p1(iWidth/2, iHeight/2);
	// cPonto p2(iWidth, iHeight);
	 
	// cQuadrante q0(p0, p1, 64);
	// cQuadrante q1(p2, p1, 222);

	// desenhaQuadrante(q0.getPtoBase(), q0.getPtoOposto(), q0.getIntensidade());
	// desenhaQuadrante(q1.getPtoBase(), q1.getPtoOposto(), q1.getIntensidade());
}


vector<cQuadrante> obterQuadrantesFilhos(cQuadrante* quadrante) {
	vector<cQuadrante> quadrantesFilhos;

	// se PtoBase tiver as mesmas cordenadas X,Y de PtoOposto, retorná um vector vazio (sem coodernadas)
	if (
		quadrante->getPtoBase().getX() == quadrante->getPtoOposto().getX() &&
		quadrante->getPtoBase().getY() == quadrante->getPtoOposto().getY()
	) {
		return quadrantesFilhos;
	}

	// verifica se o quadrante (pai) precisa ser quebrado em quadrantes filhos
	int intensidade = 0;
	int quantidadePixels = 0;
	for(int i = quadrante->getPtoBase().getX(); i < quadrante->getPtoBase().getX()+ iWidth; i ++) {
		for(int j = quadrante->getPtoOposto().getY(); j < quadrante->getPtoOposto().getY() + iHeight; j ++) {
			unsigned int intensidadePixel = image[i*iWidth+j];
			intensidade += intensidadePixel;
			quantidadePixels++;
		}
	}

	int quantidadePixelsIgualIntensidadeMedia = 0;
	int intensidadeMedia = intensidade/(quantidadePixels);

	// for praticamente igual?
	for(int i = quadrante->getPtoBase().getX(); i < quadrante->getPtoBase().getX()+ iWidth; i ++) {
		for(int j = quadrante->getPtoOposto().getY(); j < quadrante->getPtoOposto().getY() + iHeight; j ++) {
			unsigned int intensidadePixel = image[i*iWidth+j];
			if (intensidadePixel == quantidadePixelsIgualIntensidadeMedia) {
				quantidadePixelsIgualIntensidadeMedia++;
			}
		}
	}

	// se todos os pixels do quadrante (pai) tiverem o mesmo valor da intensidadeMedia, não preciso ter filhos
	if (quantidadePixelsIgualIntensidadeMedia == quantidadePixels)
	{
		return quadrantesFilhos;
	}


	// //calcular intensidade média:	
	// int intensidade = 0;
	// int quantidadePixels = 0;
	// for(int i = p1.getX(); i < p1.getX() + largura; i ++) {
	// 	for(int j = p1.getY(); j < p1.getY() + altura; j ++) {
	// 		unsigned int intensidadePixel = imagem[i*larguraImagem+j];
	// 		intensidade += intensidadePixel;
	// 		quantidadePixels++;
	// 	}
	// }
	
	// int intensidadeMedia = intensidade/(quantidadePixels);

	quadrantesFilhos.push_back(
		cQuadrante(
			quadrante->getPtoBase(),
			cPonto(
				quadrante->getPtoOposto().getX() / 2, 
				quadrante->getPtoOposto().getY() / 2
			),
			0
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
			0
		)
	); //q2

	quadrantesFilhos.push_back(
		cQuadrante(
			cPonto(
				quadrante->getPtoOposto().getX() / 2 +1,
				quadrante->getPtoOposto().getY() / 2 +1 
			),
			quadrante->getPtoOposto(),
			0
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
			0
		)
	); //q4

	return quadrantesFilhos; 
}

// *****************************************************
// ***                                               ***
// *****************************************************
void montaArvore() {
	
	cQuadtree *arvore = new cQuadtree();

	cPonto pontoBase(0,0);
	cPonto pontoOposto(iWidth, iHeight);
	cQuadrante *quadrante = new cQuadrante(pontoBase, pontoOposto, 0);

	cNo *noRaiz = new cNo(quadrante);
	arvore->setRaiz(noRaiz);
	std::cout << "No raiz => " << arvore->getRaiz() << endl;

	cNo* noAtual = arvore->getRaiz();
	
	// faça até que o quadrante tenha apenas 1 pixel
	bool quadranteMaiorQueUmPixel = true;
	while(quadranteMaiorQueUmPixel) {

		cout << "Entrei no While" << endl;

		vector<cQuadrante> quadrantesFilhos = obterQuadrantesFilhos(noAtual->getQuadrante());

		if (quadrantesFilhos.empty()) {			
			cout << "Entrei no if " << endl;
			quadranteMaiorQueUmPixel = false;
			break;
		}

		cNo* noSuperiorEsquerdo  = new cNo(&quadrantesFilhos[0]);
    	cNo* noSuperiorDireito   = new cNo(&quadrantesFilhos[1]);
		cNo* noInferiorDireito   = new cNo(&quadrantesFilhos[2]);
		cNo* noInferiorEsquerdo  = new cNo(&quadrantesFilhos[3]);

		noAtual->addNosFilhos(
			noSuperiorEsquerdo,
			noSuperiorDireito,
			noInferiorDireito,
			noInferiorEsquerdo
		);
	}
}


// *****************************************************
// ***                                               ***
// *****************************************************
void teclado(unsigned char key, int x, int y) {

	switch (key) {
		case 27		: 	exit(0); // equivale ao ESC na
								 // tabela ASC II
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
