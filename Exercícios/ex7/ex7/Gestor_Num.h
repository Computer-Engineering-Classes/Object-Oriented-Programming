#pragma once
#include <iostream>
#include <list>

using namespace std;

class Gestor_Num
{
private:
	list<int> num_list;
public:
	Gestor_Num();
	~Gestor_Num();
	void Adicionar_Num(void);
	void Remover_Num(void);
	void Mostrar_Lista(void);
	int Obter_Posicao(void);
	void Ordenar_Lista(void);
};

