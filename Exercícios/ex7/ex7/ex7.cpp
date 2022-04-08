#include "Gestor_Num.h"

#define N 5

int main()
{
	Gestor_Num lista;
	for (int i = 0; i < N; i++)
		lista.Adicionar_Num();
	lista.Remover_Num();
	lista.Mostrar_Lista();
	lista.Ordenar_Lista();
	lista.Mostrar_Lista();
	cout << lista.Obter_Posicao();
	return 0;
}