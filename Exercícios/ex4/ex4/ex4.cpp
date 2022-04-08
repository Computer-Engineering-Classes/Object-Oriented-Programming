
#include <iostream>
#include <fstream>
#include "Pessoa.h"
#include <vector>
#include <string>

int main()
{
    /*Pessoa p1("Jonas Culatra", Data(20, 9, 1987), "Rua da direita n.o 2");
    Pessoa p2("Joni Rato", Data(4, 2, 1990), "Rua da esquerda n.o 3");
    p2.Show();
    string morada;
    Data datan;
    cout << endl << "Nova morada: ";
    getline(cin, morada);
    p2.SetMorada(morada);
    cout << "Nova data de nascimento: ";
    cin >> datan;
    p2.SetDatan(datan);
    p2.Show();
    Pessoa p3;
    p3.ReadK();
    p3.Show();
    Pessoa p4;
    cin >> p4;
    cout << p4;
    cout << (p3 == p4) << endl;
    p3.MaisNovo(p4);
    p4.SaveFile();
    p4.ReadFile();
    cout << p4;*/
    vector <Pessoa> lista;
    string nome, morada;
    char c;
    Data datan;
    int n = 0;
    ifstream file;
    file.open("info.txt");
    if (!file)
    {
        cout << "Erro.";
        exit(0);
    }
    while (!file.eof())
    {
        getline(file, nome);
        file >> datan >> c;
        getline(file, morada);
        morada = c + morada;
        lista.push_back(Pessoa(nome,datan,morada));
        n++;
    }
    for (int i = 0; i < n; i++)
        cout << lista[i];
}