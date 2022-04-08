#include "Administrativo.h"
#include "Operario.h"
#include <list>

class Gestor_Func
{
private:
	list <Funcionario*> lista_func;
public:
	Gestor_Func();
	virtual ~Gestor_Func();
	void Set_lista_func(list<Funcionario*> list) { lista_func = list; };
	list<Funcionario*> Get_lista_func(void) const { return lista_func; };
	void ShowFunc(void);
	void AddFunc(void);
	void AddFunc(string nome, Data d, string morada, int num, string setor, float ord, int h);
	void AddFunc(string nome, Data d, string morada, int num, string setor, float ord, int h, string turno);
	void RemoveFunc(void);
	void ReadFile(ifstream& file);
	void SaveFile(ofstream& file);
	friend void operator<<(ostream& os, Gestor_Func& gestor);
	friend void operator>>(istream& is, Gestor_Func& gestor);
};

