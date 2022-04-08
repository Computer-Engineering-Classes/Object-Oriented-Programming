#pragma once
#include "Funcionario.h"

class Administrativo :
	public Funcionario
{
public:
	Administrativo();
	Administrativo(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra);
	~Administrativo();
	float Calcula_ordenado(void);
	void Ask2Set(void);
	void ReadFile(ifstream& file);
	void SaveFile(ofstream& file);
};

