#include <iostream>
#include <string>
using namespace std;

class Candidato
{
private:
	string nome;
	int numero_votos;
public:
	Candidato(string novo_nome);
	~Candidato();
	const string Get_nome(void) const { return nome; }
	const int Get_votos(void) const { return numero_votos; }
	void AdicionarVoto(void);
};

