#pragma once
#include "Point.h"

enum Cores { VERMELHO, AZUL, VERDE, BRANCO, PRETO, AMARELO };

class Forma
{
private:
	int Cor_interior;
	int Cor_contorno;
	static int flag;
public:
	Forma();
	Forma(int cor_int, int cor_cont);
	virtual ~Forma();
	void Set_cor_int(int cor_int) { Cor_interior = cor_int; };
	void Set_cor_cont(int cor_cont) { Cor_contorno = cor_cont; };
	int Get_cor_int(void) const { return Cor_interior; };
	int Get_cor_cont(void) const { return Cor_contorno; };
	static int Get_flag(void);
	virtual bool Desenha(void) const = 0;
	virtual bool Pintar(int nova_cor) = 0;
	virtual bool Mover(float x, float y) = 0;
	virtual float perimetro(void) const = 0;
	virtual float area(void) const = 0;
	friend void testa_forma(Forma& ref);
};