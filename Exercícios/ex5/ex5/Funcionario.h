#pragma once
#include "Pessoa.h"

class Funcionario :
	public Pessoa
{
private:
	int num_func;
	string setor;
public:
	Funcionario();
	Funcionario(string nome, Data datan, string morada, int num_func, string setor);
	virtual ~Funcionario();
	void SetNum_Func(int n);
	void SetSetor(string s);
	int GetNum_Func(void) const { return num_func; };
	string GetSetor(void) const { return setor; };
	void ShowFunc(void);
	bool CompareDates(Funcionario f);
	void SaveFile(fstream& file);
	void ReadFile(fstream& file);
	friend void Switch(Funcionario& f1, Funcionario& f2);
	friend istream& operator>>(istream& is, Funcionario& p);
};