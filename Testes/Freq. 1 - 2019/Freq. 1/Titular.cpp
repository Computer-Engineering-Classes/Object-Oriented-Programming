#include "Titular.h"


Titular::Titular()
{
}

Titular::Titular(string nome, string morada, int numero_CC)
	:nome(nome), morada(morada), numero_CC(numero_CC)
{
}

Titular::~Titular()
{
}

void Titular::Show()
{
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
}

bool Titular::operator==(Titular T)
{
	return (nome == T.nome && morada == T.morada && numero_CC == T.numero_CC);
}
