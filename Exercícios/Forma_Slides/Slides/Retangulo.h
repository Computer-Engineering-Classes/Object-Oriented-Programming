#pragma once
#include "Forma.h"
class Retangulo :
	public Forma
{
private:
	Point CSE;
	Point CID;
public:
	Retangulo();
	Retangulo(float x1, float y1, float x2, float y2, int cor);
	virtual ~Retangulo();
	bool Desenha(void) const;
	bool Pintar(int nova_cor);
	bool Mover(float x, float y);
	float perimetro(void) const;
	float area(void) const;
};