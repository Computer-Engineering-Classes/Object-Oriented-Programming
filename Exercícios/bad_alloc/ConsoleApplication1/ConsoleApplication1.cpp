#include <iostream>
#include <vector>

using namespace std;

struct S
{
	int indicador[5000];
	double valor[5000];
};

int main()
{
	vector <S> v;
	try
	{
		long int i = 0;
		for (;;)
		{
			S* ptr = new S();
			v.push_back(*ptr);
			cout << endl << "v[" << i << "] alocada" << endl;
			i++;
		}
	}
	catch (bad_alloc erro)
	{
		cout << endl << "Exceção " << erro.what() << endl;
	}
}