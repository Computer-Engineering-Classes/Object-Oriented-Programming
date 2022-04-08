#include <vector>
#include "Operario.h"
#include "Administrativo.h"

void Menu(int& opcao);

int main()
{
    int n, opcao, i = 0, num, option;
    float ord;
    bool flag = false;
    ifstream f1;
    ofstream op, admin;
    Operario* O;
    Administrativo* A;
    vector<Funcionario*> Func;
    char c;
    setlocale(LC_ALL, "");
    while (true)
    {
        system("cls");
        Menu(opcao);
        switch (opcao)
        {
        case 1:
            f1.open("Funcionario.txt");
            if (!f1)
                cout << "Erro ao abrir o ficheiro.";
            else
            {
                while (!f1.eof())
                {
                    f1 >> c;
                    if (c == 'O')
                        Func.push_back(new Operario);
                    else if (c == 'A')
                        Func.push_back(new Administrativo);
                    f1 >> c;
                    Func[i]->ReadFile(f1);
                    i++;
                }
                n = i;
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
              cout << endl << "Ordenado do funcion�rio " << i << ": " << Func[i]->Calcula_ordenado() << endl;
            break;
        case 3:
            cout << endl << "N�mero do funcion�rio: ";
            cin >> num;
            for (int i = 0; i < n; i++)
            {
                if (num == Func[i]->GetNum_Func())
                {
                    Func[i]->ShowFunc();
                    flag = true;
                }
            }
            if (!flag)
                cout << endl << "O n�mero n�o est� atribu�do." << endl;
            break;
        case 4:
            cout << endl << "N�mero do funcion�rio: ";
            cin >> num;
            for (int i = 0; i < n; i++)
            {
                if (num == Func[i]->GetNum_Func())
                {
                    cout << endl << "Novo ordenado base: ";
                    cin >> ord;
                    Func[i]->SetOrd_Base(ord);
                    flag = true;
                }
            }
            if (!flag)
                cout << endl << "O n�mero n�o est� atribu�do." << endl;
            break;
        case 5:
            cout << endl << "Tipo de funcion�rio:" << endl;
            cout << endl << "1 -> Oper�rio" << endl;
            cout << endl << "2 -> Administrativo" << endl;
            cout << endl << "Op��o: ";
            cin >> option;
            switch (option)
            {
            case 1:
                Func.push_back(new Operario);
                break;
            case 2:
                Func.push_back(new Administrativo);
                break;
            default:
                cout << endl << "Op��o inv�lida." << endl;
                flag = true;
            }
            if (!flag)
            {
                Func[n]->Ask2Set();
                n++;
            }
            break;
        case 6:
            for (int i = 0; i < n; i++)
            {
                if (O = dynamic_cast<Operario*> (Func[i]))
                    if (O->GetF_Turno())
                        O->ShowFunc();
            }
            break;
        case 7:
            cout << endl << "N�mero do funcion�rio: ";
            cin >> num;
            for (int i = 0; i < n; i++)
            {
                if (num == Func[i]->GetNum_Func())
                {
                    Func.erase(Func.begin() + i);
                    n--;
                }
            }
            break;
        case 8:
            admin.open("Administrativo.txt");
            if (!admin)
                cout << endl << "Erro ao abrir o ficheiro." << endl;
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (A = dynamic_cast<Administrativo*> (Func[i]))
                    {
                        Func[i]->SaveFile(admin);
                        admin << endl;
                    }

                }
            }
            admin.close();
            break;
        case 9:
            op.open("Operario.txt");
            if (!op)
                cout << endl << "Erro ao abrir o ficheiro." << endl;
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (O = dynamic_cast<Operario*> (Func[i]))
                    {
                        Func[i]->SaveFile(op);
                        op << endl;
                    }

                }
            }
            op.close();
            break;
        case 10:
            exit(0);
        default:
            cout << endl << "\tOp��o inv�lida.";
            break;
        }
        system("pause");
    }
    return(0);
}

void Menu(int& opcao)
{
    cout << endl << "\tMenu:" << endl;
    cout << endl << "\t1 -> Ler o ficheiro" << endl;
    cout << endl << "\t2 -> Calcular e apresentar o ordenado de todos os funcion�rios" << endl;
    cout << endl << "\t3 -> Pesquisar um funcion�rio" << endl;
    cout << endl << "\t4 -> Alterar o ordenado base de um funcion�rio" << endl;
    cout << endl << "\t5 -> Adicionar um Oper�rio ou Administrativo" << endl;
    cout << endl << "\t6 -> Apresentar o nome dos oper�rios que trabalham por turnos" << endl;
    cout << endl << "\t7 -> Eliminar um funcion�rio" << endl;
    cout << endl << "\t8 -> Guardar, num ficheiro �Administrativos.txt�, os dados dos Administrativos" << endl;
    cout << endl << "\t9 -> Guardar, num ficheiro �Operarios.txt�, os dados dos Oper�rios" << endl;
    cout << endl << "\t10 -> Sair" << endl;
    cout << endl << "\tOp��o: ";
    cin >> opcao;
}