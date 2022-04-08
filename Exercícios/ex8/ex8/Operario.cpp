#include "Operario.h"

Operario::Operario()
	:f_turno(false)
{
	SetP_H_Extra(8);
}

Operario::Operario(string nome, Data datan, string morada, int num_func, string setor, float ord_base, int h_extra, bool f_turno)
	:Funcionario(nome, datan, morada, num_func, setor, ord_base, h_extra)
{
	SetP_H_Extra(8);
	this->f_turno = f_turno;
}

Operario::~Operario()
{
}

float Operario::Calcula_ordenado(void)
{
	float ord;
	ord = GetOrd_Base() + GetH_Extra() * GetP_H_Extra();
	if (f_turno)
		ord += GetOrd_Base() * (1 / 4);
	return ord;
}

void Operario::Ask2Set(void)
{
	int option;
	Funcionario::Ask2Set();
	cout << endl << "Turnos:" << endl;
	cout << endl << "1 -> Sim" << endl;
	cout << endl << "2 -> Não" << endl;
	cout << endl << "Opção: ";
	cin >> option;
	switch (option)
	{
	case 1:
		SetF_Turno(true);
		break;
	case 2:
		SetF_Turno(false);
		break;
	}
}

void Operario::ReadFile(ifstream& file)
{
	char c;
	string str;
	Funcionario::ReadFile(file);
	file >> c;
	getline(file, str);
	if (str == "sim;")
		f_turno = true;
	else if(str == "nao;")
		f_turno = false;
}

void Operario::SaveFile(ofstream& file)
{
	Funcionario::SaveFile(file);
	if (GetF_Turno())
		file << "sim;";
	else
		file << "nao;";
}
