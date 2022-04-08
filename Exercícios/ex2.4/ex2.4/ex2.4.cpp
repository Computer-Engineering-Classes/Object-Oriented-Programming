// ex2.4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string str;
    ifstream file;
    file.open("alunos.txt");
    if (!file) {
        cout << "Erro: não é possível abrir o ficheiro alunos.txt" << endl;
    }
    else {
        while(file) {
            getline(file, str, ';');
            cout << str << endl;
        }
    }
    file.close();
}
