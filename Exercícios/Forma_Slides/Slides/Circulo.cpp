#include "Circulo.h"

Circulo::Circulo()
	:raio(0.0)
{
}

Circulo::Circulo(float x, float y, float raio, int cor)
	:centro(x,y), raio(raio), Forma(cor, cor)
{
	if (raio < 0)
		raio = fabs(raio);
}

Circulo::~Circulo()
{
}

bool Circulo::Desenha(void) const
{
	return true;
}

bool Circulo::Pintar(int nova_cor)
{
	Set_cor_cont(nova_cor);
	Set_cor_int(nova_cor);
	return true;
}

bool Circulo::Mover(float x, float y)
{
	centro.Set_P(x, y);
	return true;
}

float Circulo::perimetro(void) const
{
	return float(2 * pi * raio);
}

float Circulo::area(void) const
{
	return float(pi * pow(raio, 2));
}
