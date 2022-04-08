#include "Gestor_Func.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	Gestor_Func gestor;
	ifstream read;
	ofstream save;
	read.open("funcionarios.txt");
	gestor.ReadFile(read);
	cout << gestor;
	system("pause");
	system("CLS");
	gestor.AddFunc("Zeca Estacionancio", Data(1, 1, 1985), "Rua A n9", 25050, "Pintura", 1100, 15, "nao");
	gestor.AddFunc("Adrusila Lopes", Data(6, 6, 1996), "Rua E n6", 25051, "RecHumanos", 900, 0);
	cout << gestor;
	gestor.RemoveFunc();
	save.open("funcionarios.txt");
	gestor.SaveFile(save);
	read.close();
	save.close();
	return(0);
}

class Registo
{
private:
	int anoR;
	int mesR;
public:
	void SaveFile(ofstream& file) {};
	int GetAnoR(void) const { return anoR; }
	int GetMesR(void) const { return mesR; }
};

class Veiculo
{
private:
	string modelo;
	Registo fabrico;
	Registo venda;
public:
	Veiculo();
	Veiculo(string modelo, Registo fabrico, Registo venda);
	Registo GetFabrico(void) const { return fabrico; };
	void SaveFile(ofstream& file);
	void Show() {};
	virtual int Calcula(void) = 0;
	virtual void ReadK(void) {}
};

Veiculo::Veiculo()
{
}

Veiculo::Veiculo(string modelo, Registo fabrico, Registo venda)
	:modelo(modelo), fabrico(fabrico), venda(venda)
{
}

void Veiculo::SaveFile(ofstream& file)
{
	file << modelo << ';';
	fabrico.SaveFile(file);
	venda.SaveFile(file);
}

class Eletrico : public Veiculo
{
private:
	string tecnologia;
public:
	Eletrico();
	Eletrico(string tecnologia, string modelo, Registo fabrico, Registo venda);
	int Calcula(void);
	void ReadK();
};

Eletrico::Eletrico()
{
}

Eletrico::Eletrico(string tecnologia, string modelo, Registo fabrico, Registo venda)
	:Veiculo(modelo, fabrico, venda), tecnologia(tecnologia)
{
}

int Eletrico::Calcula(void)
{
	int desconto = 0;
	if ((GetFabrico().GetAnoR() == 2006 && GetFabrico().GetMesR() > 6) || GetFabrico().GetAnoR() > 2006)
		desconto = 100;
	return(desconto);
}

void Eletrico::ReadK()
{
	cout << "Tecnologia: ";
	getline(cin, tecnologia);
	Veiculo::ReadK();
}

class Hibrido : public Veiculo
{
private:
	int potencia;
	float consumo;
public:
	Hibrido() {}
	void ReadK();
	int Calcula(void);
	void Show();
};
int main()
{
	ofstream file;
	file.open("dados.txt");
	Eletrico* E;
	list<Veiculo*> Gestor;
	list<Veiculo*>::iterator p = Gestor.begin();
	while (p != Gestor.end())
	{
		if (E = dynamic_cast<Eletrico*> (*p))
			E->SaveFile(file);
		p++;
	}
	/*Hibrido* H;
	Veiculo* va[10];
	for (int i = 0; i < 10; i++)
	{
		if (H = dynamic_cast<Hibrido*> (va[i]))
		{
			if (H->Calcula() == 100)
				va[i]->Show();
		}
	}
	string aux;
	Veiculo* va[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Tipo de veiculo: ";
		cin >> aux;
		if (aux == "Eletrico")
			va[i] = new Eletrico;
		if (aux == "Hibrido")
			va[i] = new Hibrido;
		va[i]->ReadK();
	}*/
}

void Hibrido::ReadK()
{
	cout << "Potencia: ";
	cin >> potencia;
	cout << "Consumo: ";
	cin >> consumo;
	Veiculo::ReadK();
}

int Hibrido::Calcula(void)
{
	int desconto = 0;
	if ((GetFabrico().GetAnoR() == 2008 && GetFabrico().GetMesR() > 7) || GetFabrico().GetAnoR() > 2008)
		desconto = 60;
	return(desconto);
}

void Hibrido::Show()
{
	Veiculo::Show();
	cout << "Potencia: " << potencia << endl;
	cout << "Consumo: " << consumo << endl;
}