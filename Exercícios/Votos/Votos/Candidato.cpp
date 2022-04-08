#include "Candidato.h"

Candidato::Candidato(string novo_nome)
	:numero_votos(0)
{
	if (!novo_nome.empty())
		nome = novo_nome;
}

Candidato::~Candidato()
{
}

void Candidato::AdicionarVoto(void)
{
	++numero_votos;
}
