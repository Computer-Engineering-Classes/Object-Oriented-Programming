#pragma once
#include "Pessoa.h"

class Funcionario :
	public Pessoa
{
private:
	int num_func;
	string setor;
	float ord_base;
	int h_extra;
	float p_h_extra;
public:
	Funcionario();
	Funcionario(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra);
	virtual ~Funcionario();
	virtual float Calcula_ordenado() = 0;
	void SetNum_Func(int n) { num_func = n; };
	void SetSetor(string s) { setor = s; };
	void SetOrd_Base(float o) { ord_base = o; };
	void SetH_Extra(int h) { h_extra = h; };
	void SetP_H_Extra(float p) { p_h_extra = p; };
	int GetNum_Func(void) const { return num_func; };
	string GetSetor(void) const { return setor; };
	float GetOrd_Base(void) const { return ord_base; };
	int GetH_Extra(void) const { return h_extra; };
	float GetP_H_Extra(void) const { return p_h_extra; };
	void ShowFunc(void);
	virtual void Ask2Set(void);
	bool CompareDates(Funcionario& f);
	virtual void SaveFile(ofstream& file);
	virtual void ReadFile(ifstream& file);
	friend void Switch(Funcionario* f1, Funcionario* f2);
	friend istream& operator>>(istream& is, Funcionario& p);
};