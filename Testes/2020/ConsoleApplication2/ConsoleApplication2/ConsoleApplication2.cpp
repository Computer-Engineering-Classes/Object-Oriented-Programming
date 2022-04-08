#include <iostream>
#include "Data.h"
#include <string>
#include <fstream>

using namespace std;
class Aula
{
    string discip;
    string tipologia;
    Data data_ini;
public:
    Aula() {};
    Aula(string discip, string tipo, Data data_in);
    void ReadFile(ifstream& is) {};
    Data GetHora() { return data_ini; };
    virtual float Calcula(void) = 0;
    virtual bool Antes12h() = 0;
    virtual void Show() {};
};
class Presencial: public Aula
{
private:
    string sala;
    Data data_fim;
public:
    Presencial();
    Presencial(string discip, string tipo, Data data_ini, string nova_sala, Data n_data_fim);
    ~Presencial();
    void ReadFile(ifstream& is);
    float Calcula(void);
    bool Antes12h(void);
};
class Online : public Aula
{
    Data duracao;
public:
    float Calcula(void) {};
    bool Antes12h(void);
};
Presencial::Presencial()
{
}

Presencial::Presencial(string discip, string tipo, Data data_ini, string nova_sala, Data n_data_fim)
    :Aula(discip, tipo, data_ini)
{
    sala = nova_sala;
    data_fim = n_data_fim;
}

Presencial::~Presencial()
{
}

void Presencial::ReadFile(ifstream& is)
{
    Aula::ReadFile(is);
    getline(is, sala, ';');
    data_fim.ReadFile(is);
}

float Presencial::Calcula(void)
{
    float preco = 20;
    int hora_inicio = GetHora().GetHora();
    if (hora_inicio >= 9 && hora_inicio <= 17)
        preco = 15;
    return preco;
}
#include <vector>

bool Presencial::Antes12h(void)

{

    bool flag = false;

    if (data_fim.GetHora() <= 12)

        flag = true;

    return flag;

}

bool Online::Antes12h(void)

{

    bool flag = false;

    int final;

    final = duracao.GetHora() + GetHora().GetHora();

    if (final <= 12)

        flag = true;

    return flag;

}

int main()

{

    Aula* va[10];

    for (int i = 0; i < 10; i++)

    {

        if (va[i]->Antes12h())

            va[i]->Show();

    }

}

Aula::Aula(string discip, string tipo, Data data_in)
{
    this->discip = discip;
    tipologia = tipo;
    data_ini = data_in;
}
