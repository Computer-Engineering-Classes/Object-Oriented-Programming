#include <iostream>

class A {

private: int x;

public:

    A() { };

    A(int _x) { x = _x; };

    ~A() { };

    int get_x() { return x; };

    void set_x(int _x) { x = _x; };

    void swap(A& Y );

};

void A::swap(A &Y)

{
    A temp;

    temp.x = x;

    x = Y.x;

    Y.x = temp.x;

}

using namespace std;

int main()

{
    A X(5), Y(10);

    cout << "Antes da troca: X= " << X.get_x() << " Y= " << Y.get_x() << endl;

    X.swap(Y);

    cout << "Depois da troca:X= " << X.get_x() << " Y= " << Y.get_x() << endl;

    return 0;
}

