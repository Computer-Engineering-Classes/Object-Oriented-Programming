#pragma once
#include "Retangulo.h"
class Quadrado :
	public Retangulo
{
public:
	Quadrado();
	Quadrado(float x1, float y1, float Dim, int cor);
	virtual ~Quadrado();
};