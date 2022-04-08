#pragma once
#include <iostream>
#include <string>

using namespace std;

class Titular
{
private:
	string nome;
	string morada;
	int numero_CC;
public:
	Titular();
	Titular(string nome, string morada, int numero_cc);
	~Titular();
	int Get_numero_CC(void) const { return numero_CC; };
	void Show(void);
	bool operator==(Titular T);
};