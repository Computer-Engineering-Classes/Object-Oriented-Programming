// ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct aluno {
    string nome;
    int idade;
    int num;
}Aluno;

int main()
{
    ofstream file;
    Aluno a1[3];
    file.open("alunos.txt");
    if (!file) {
        cout << "Erro: não é possível abrir o ficheiro alunos.txt" << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << "Nome: " << endl;
        cin.ignore();
        getline(cin, a1[i].nome);
        cout << "Idade: " << endl;
        cin >> a1[i].idade;
        cout << "Número: " << endl;
        cin >> a1[i].num;
        file << a1[i].nome << ' ' << a1[i].idade << ' ' << a1[i].num << ';' << endl;
    }
    file.close();
}

