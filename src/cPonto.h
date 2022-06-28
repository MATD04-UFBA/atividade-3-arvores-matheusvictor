#pragma once

class cPonto {	

private:
	int x;
	int y;

public:
	cPonto();
	cPonto(int x0, int x1);
	cPonto(const cPonto& p);

	int 	getX();
	int 	getY();

	void 	setX(int x);
	void 	setY(int y);
	void 	setXY(int x, int y);
};
						