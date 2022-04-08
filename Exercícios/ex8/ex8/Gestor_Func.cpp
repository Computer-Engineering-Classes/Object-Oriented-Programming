#include "Gestor_Func.h"

Gestor_Func::Gestor_Func()
{
}

Gestor_Func::~Gestor_Func()
{
	lista_func.clear();
}

void Gestor_Func::ShowFunc(void)
{
	Funcionario* aux = nullptr;
	list<Funcionario*>::iterator i = lista_func.begin();
	while (i != lista_func.end())
	{
		aux = *i;
		aux->ShowFunc();
		i++;
		cout << endl;
	}
}

void Gestor_Func::AddFunc(void)
{
	Funcionario* aux = nullptr;
	int option;
	cout << endl << "Tipo de funcionário:" << endl;
	cout << endl << "\t1 -> Operário" << endl;
	cout << endl << "\t2 -> Administrativo" << endl;
	cout << endl << "\tOpção: ";
	cin >> option;
	switch (option)
	{
	case 1:
		aux = new Operario;
		break;
	case 2:
		aux = new Administrativo;
		break;
	default:
		cout << endl << "Opção inválida." << endl;
	}
	aux->Ask2Set();
	lista_func.push_back(aux);
}

void Gestor_Func::AddFunc(string nome, Data d, string morada, int num, string setor, float ord, int h)
{
	Funcionario* func = new Administrativo(nome, d, morada, num, setor, ord, h);
	lista_func.push_back(func);
}

void Gestor_Func::AddFunc(string nome, Data d, string morada, int num, string setor, float ord, int h, string turno)
{
	Funcionario* func;
	bool flag = false;
	if (turno == "sim")
		flag = true;
	func = new Operario(nome, d, morada, num, setor, ord, h, flag);
	lista_func.push_back(func);
}

void Gestor_Func::RemoveFunc(void)
{
	int num;
	Funcionario* aux;
	list<Funcionario*>::iterator ptr = lista_func.begin();
	cout << "Introduza o número do funcionário que deseja remover: ";
	cin >> num;
	while (ptr != lista_func.end())
	{
		aux = *ptr;
		if (aux->GetNum_Func() == num)
		{
			lista_func.erase(ptr);
			break;
		}
		ptr++;
	}
}

void Gestor_Func::ReadFile(ifstream& file)
{
	char c;
	Funcionario* aux = nullptr;
	int i = 0;
	while (!file.eof())
	{
		file >> c;
		if (c == 'A')
			aux = new Administrativo;
		else if (c == 'O')
			aux = new Operario;
		file >> c;
		aux->ReadFile(file);
		lista_func.push_back(aux);
	}
}

void Gestor_Func::SaveFile(ofstream& file)
{
	Operario* O;
	list<Funcionario*>::iterator ptr = lista_func.begin();
	Funcionario* aux;
	while (ptr != lista_func.end())
	{
		aux = *ptr;
		if (O = dynamic_cast <Operario*> (aux))
			file << "O: ";
		else
			file << "A: ";
		aux->SaveFile(file);
		ptr++;
		if(ptr!=lista_func.end())
			file << endl;
	}
}

void operator<<(ostream& os, Gestor_Func& gestor)
{
	gestor.ShowFunc();
}

void operator>>(istream& is, Gestor_Func& gestor)
{
	gestor.AddFunc();
}
