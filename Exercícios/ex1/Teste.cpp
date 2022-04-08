#include <iostream>
#define N 20

using namespace std;

int main()
{
	int i;
	float f;
	char c, s[N];
	
	setlocale(LC_ALL, "");
	
	cout << "Insira um valor inteiro:" << endl;
	cin >> i;
	cout << "Insira um valor decimal:" << endl;
	cin >> f;
	cout << "Insira um caractere:" << endl;
	cin >> c;
	cout << "Insira uma palavra/expressão:" << endl;
	cin >> s;
	cout << "Inteiro: " << i << " Decimal: " << f << " Caractere: " << c << " Expressão: " << s << endl;
	
	system("pause");
	return (0);
}