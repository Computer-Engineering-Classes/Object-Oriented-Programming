#include "Frequencia2.h"

Marca::Marca()
{
	escolhido = nullptr;
}

Marca::Marca(string p1, int n1, string p2, int n2, string p3, int n3, int peso)
	:junior(p1, n1), rookie(p2, n2)
{
	if (peso == 0)
		escolhido = new Rookie(p3,n3);
	if (peso == 10)
		escolhido = new Junior(p3, n3);
	if (peso == 20)
		escolhido = new Senior(p3, n3);
}

Marca::~Marca()
{
}

void Marca::MudarPiloto(string nome)
{
	if (junior.GetNome() == nome)
		junior.SetPiloto();
	if (rookie.GetNome() == nome)
		rookie.SetPiloto();
	if (escolhido->GetNome() == nome)
		escolhido->SetPiloto();
}

void Marca::ReadFile(ifstream& file)
{
	char c, t;
	int i=0, f1 = 0, f2 = 0;
	getline(file, designacao, ';');
	while (i < 3)
	{
		file >> c >> t;
		if (c == 'S')
		{
			escolhido = new Senior;
			escolhido->ReadFile(file);
		}
		if (c == 'J')
		{
			if (f1 == 0)
				junior.ReadFile(file);
			else
			{
				escolhido = new Junior;
				escolhido->ReadFile(file);
			}
			f1 = 1;
		}
		if (c == 'R')
		{
			if (f2 == 0)
				rookie.ReadFile(file);
			else
			{
				escolhido = new Rookie;
				escolhido->ReadFile(file);
			}
			f2 = 1;
		
		}
		i++;
	}
}
Senior::Senior()
{
}

Senior::Senior(string nome, int num)
	:Piloto(nome, num)
{
}
Senior::~Senior()
{}
int Senior::PesoStatus()
{
	return 20;
}
bool Senior::DRSStatus()
{
	return true;
}
void Senior::ReadFile(ifstream& file)
{
	string s;
	char c;
	int peso;
	Piloto::ReadFile(file);
	file >> peso >> c;
	getline(file, s, ';');
}
Junior::Junior()
{
}
Junior::Junior(string s, int num)
	:Piloto(s, num)
{}
Junior::~Junior()
{}
int Junior::PesoStatus()
{
	return 10;
}
bool Junior::DRSStatus()
{
	return false;
}
void Junior::ReadFile(ifstream& file)
{
	string s;
	char c;
	int peso;
	Piloto::ReadFile(file);
	file >> peso >> c;
	getline(file, s, ';');
}
Rookie::Rookie()
{
}
Rookie::Rookie(string s, int num)
	:Piloto(s, num)
{}
Rookie::~Rookie()
{}
int Rookie::PesoStatus()
{
	return 0;
}
bool Rookie::DRSStatus()
{
	return false;
}
void Rookie::ReadFile(ifstream& file)
{
	string s;
	char c;
	int peso;
	Piloto::ReadFile(file);
	file >> c;
	getline(file, s, ';');
}
Piloto::Piloto()
{
}
Piloto::Piloto(string nome, int num)
	:nome(nome), numero_inscricao(num), pontos(0)
{}
Piloto::~Piloto()
{}
void Piloto::SetPiloto()
{
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Numero de inscricao: ";
	cin >> numero_inscricao;
	pontos = 0;
}
void Piloto::ReadFile(ifstream& file)
{
	char c;
	getline(file, nome, ';');
	file >> numero_inscricao >> c >> pontos >> c;
}
