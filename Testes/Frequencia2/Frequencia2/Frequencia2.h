#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Piloto
{
private:
    string nome;
    int numero_inscricao;
    int pontos;
public:
    Piloto();
    Piloto(string nome, int num);
    virtual ~Piloto();
    virtual int PesoStatus() = 0;
    virtual bool DRSStatus() = 0;
    string GetNome() const { return nome; };
    void SetPiloto();
    virtual void ReadFile(ifstream& file);
};
class Senior : public Piloto
{
public:
    Senior();
    Senior(string nome, int num);
    ~Senior();
    int PesoStatus();
    bool DRSStatus();
    void ReadFile(ifstream& file);
};
class Junior : public Piloto
{
public:
    Junior();
    Junior(string nome, int num);
    ~Junior();
    int PesoStatus();
    bool DRSStatus();
    void ReadFile(ifstream& file);
};

class Rookie : public Piloto
{
public:
    Rookie();
    Rookie(string n, int num);
    ~Rookie();
    int PesoStatus();
    bool DRSStatus();
    void ReadFile(ifstream& file);
};
class Marca
{
private:
    string designacao;
    Junior junior;
    Rookie rookie;
    Piloto* escolhido;
public:
    Marca();
    Marca(string p1, int n1, string p2, int n2, string p3, int n3, int peso);
    ~Marca();
    void MudarPiloto(string nome);
    Piloto* Get_escolhido() { return escolhido; }
    string Get_designacao() { return designacao; }
    void ReadFile(ifstream& file);
};