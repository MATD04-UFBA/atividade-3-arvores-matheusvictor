#include <iostream>
#include <cstdlib>
#include <string> 

#include <GL/glut.h>

#include "SOIL/SOIL.h"

#include "winGL.h"
#include "compressao.h"


extern int 	iHeight, 
				iWidth,
				iChannels;
		
// *****************************************************
// ***                                               ***
// *****************************************************
void revertImage(unsigned char* img, int w, int h) {

	unsigned char 	aux;
	int 			i,
					j;
	
	if (img == NULL)
		return;

	for (j = 0 ; j < h / 2 ; j++) 
		for (i = 0 ; i < w ; i++) {
			aux 			 	= img[j*w+i]; 
			img[j*w+i] 		 	= img[(h-j-1)*w+i];
			img[(h-j-1)*w+i] 	= aux;
			}				
}

// *****************************************************
// ***                                               ***
// *****************************************************
unsigned char* leImagem(std::string filename) {
	
	unsigned char 	*image 	= NULL;
	
	image = SOIL_load_image (filename.c_str(), &iWidth, &iHeight, &iChannels, SOIL_LOAD_L);
	
    if (image == NULL) {
    	std::cout << "Erro carregando imagem " << filename << std::endl;
    	exit(0);
    }

	std::cout << "Imagem    => " << filename << std::endl;
	std::cout << "Resolucao => " << iHeight << " x " << iWidth << std::endl;
	std::cout << "Channels  => " << iChannels << std::endl;

	revertImage(image, iWidth, iHeight);

	return image;	
}

// *****************************************************
// ***                                               ***
// *****************************************************
void desenhaQuadrante(cPonto p0, cPonto p1, int intensidade) {
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glColor3ub(intensidade, intensidade, intensidade);

    glBegin(GL_QUADS);
		glVertex2f(p0.getX(), p0.getY());
		glVertex2f(p1.getX(), p0.getY());
		glVertex2f(p1.getX(), p1.getY());
		glVertex2f(p0.getX(), p1.getY());
    glEnd(); 

}

// *****************************************************
// ***                                               ***
// *****************************************************
void initOpenGL (void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	glShadeModel(GL_FLAT);
	glPixelStorei( GL_UNPACK_ALIGNMENT, 1);
}

// *****************************************************
// ***                                               ***
// *****************************************************
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, w, 0.0, h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// *****************************************************
// ***                                               ***
// *****************************************************
void criaJanela(int argc, char** argv) {
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (iWidth, iHeight);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Quadtree - Estrutura de Dados");
}

// *****************************************************
// ***                                               ***
// *****************************************************
void initEventos() {
	
	glutDisplayFunc(desenho);
	glutKeyboardFunc(teclado);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	
	glutMainLoop();
}
