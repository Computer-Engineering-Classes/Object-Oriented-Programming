#include "Quadrado.h"

Quadrado::Quadrado()
{
}

Quadrado::Quadrado(float x1, float y1, float Dim, int cor)
	:Retangulo(x1, y1, x1 + Dim, y1 - Dim, cor)
{
}

Quadrado::~Quadrado()
{
}
