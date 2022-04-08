#include "Candidato.h"

int main()
{
	string nome;
	Candidato C("Maria Jose Costa");
	for (int i = 1; i <= 10; i++)
	{
		cout << endl << "Nome do candidato em que pretende votar: ";
		getline(cin, nome);
		if (nome == C.Get_nome())
			C.AdicionarVoto();
	}
	cout << "\nNome do candidato: " << C.Get_nome() << endl;
	cout << "\nNumero de votos: " << C.Get_votos();
}