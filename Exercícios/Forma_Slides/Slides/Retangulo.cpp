#include "Retangulo.h"

Retangulo::Retangulo()
{
}

Retangulo::Retangulo(float x1, float y1, float x2, float y2, int cor)
	:Forma(cor, cor), CSE(x1, y1), CID(x2, y2)
{
}

Retangulo::~Retangulo()
{
}

bool Retangulo::Desenha(void) const
{
	return true;
}

bool Retangulo::Pintar(int nova_cor)
{
	Set_cor_cont(nova_cor);
	Set_cor_int(nova_cor);
	return true;
}

bool Retangulo::Mover(float x, float y)
{
	float x1, x2, y1, y2;
	x1 = CSE.Get_x() + x;
	y1 = CSE.Get_y() + y;
	x2 = CID.Get_x() + x;
	y2 = CID.Get_y() + y;
	CSE.Set_P(x1, y1);
	CID.Set_P(x2, y2);
	return true;
}

float Retangulo::perimetro(void) const
{
	float largura, comprimento;
	largura = fabs(CSE.Get_y() - CID.Get_y());
	comprimento = fabs(CID.Get_x() - CSE.Get_x());
	return 2 * (comprimento + largura);
}

float Retangulo::area(void) const
{
	float largura, comprimento;
	largura = fabs(CSE.Get_y() - CID.Get_y());
	comprimento = fabs(CID.Get_x() - CSE.Get_x());
	return largura * comprimento;
}
