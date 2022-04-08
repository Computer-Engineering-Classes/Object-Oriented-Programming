#pragma once
#include "Funcionario.h"

class Operario :
	public Funcionario
{
private:
	bool f_turno;
public:
	Operario();
	Operario(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra, bool f_turno);
	~Operario();
	void SetF_Turno(bool f_turno) { this->f_turno = f_turno; };
	bool GetF_Turno(void) const { return f_turno; };
	float Calcula_ordenado(void);
	void Ask2Set(void);
	void ReadFile(ifstream& file);
	void SaveFile(ofstream& file);
};

