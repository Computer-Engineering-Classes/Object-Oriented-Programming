#include "Frequencia2.h"

int main()
{
    int peso;
    string s;
    Marca aux;
    vector <Marca> lista;
    ifstream file;
    file.open("marcas.txt");
    if (!file.is_open())
        cout << "Erro ao abrir o ficheiro\n";
    else
    {
        while (!file.eof())
        {
            aux.ReadFile(file);
            lista.push_back(aux);
            getline(file, s);
        }
    }
    for (int i = 0; i <= 1; i++)
    {
        peso = 10 + lista[i].Get_escolhido()->PesoStatus();
        cout << "Marca " << lista[i].Get_designacao() << ": " << peso << endl;
    }
    string m, n;
    cout << "Marca: ";
    getline(cin, m);
    cout << "Nome do piloto: ";
    getline(cin, n);
    for (int i = 0; i <= 1; i++)
    {
        if (lista[i].Get_designacao() == m)
            lista[i].MudarPiloto(n);
    }
    file.close();
    return 0;
}