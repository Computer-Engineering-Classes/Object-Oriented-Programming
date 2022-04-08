// ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Data.h"
#include "Pessoa.h"
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    /*Data d1, d2(2, 3, 2020);
    d1.Show();
    d2.Show();
    int d, m, a;
    cout << "Dia: " << endl;
    cin >> d;
    cout << "Mes: " << endl;
    cin >> m;
    cout << "Ano: " << endl;
    cin >> a;
    d1.Update(d, m, a);
    cout << (d1 == d2) << endl;
    Data d3;
    cin >> d3;
    cout << d1 << d2 << d3;
}