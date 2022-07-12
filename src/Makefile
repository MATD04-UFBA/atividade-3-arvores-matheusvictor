.cpp.o:
	g++	-c $*.cpp -I./external/SOIL/inc 

all:	compressao

compressao:  compressao.o winGL.o cPonto.o cQuadrante.o cNo.o cQuadtree.o
	g++ -o $@ $^ -L./external/SOIL/lib -lglut -lGL -lGLU -lsoil 2>&1 | cat

clean:
	rm *.o compressao