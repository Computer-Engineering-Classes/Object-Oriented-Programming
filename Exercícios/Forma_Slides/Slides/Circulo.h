#pragma once
#include "Forma.h"

class Circulo :
	public Forma
{
private:
	float raio;
	Point centro;
public:
	Circulo();
	Circulo(float x, float y, float raio, int cor);
	virtual ~Circulo();
	float Get_raio(void) const { return raio; };
	bool Desenha(void) const;
	bool Pintar(int nova_cor);
	bool Mover(float x, float y);
	float perimetro(void) const;
	float area(void) const;
};