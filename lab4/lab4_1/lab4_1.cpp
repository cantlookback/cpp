#include <iostream>
#include <vector>
#include "Complex.cpp"
#include "Logger.cpp"
using namespace std;


int main(){

    bool mhem;
    int choice, num;
    vector<Complex> complexNumbers;
    
    while (true){
        cout << "Программа для работы с комплексными числами.\n1 - Ввести новое число \n2 - Вывести список чисел\n";
        cout << "3 - Меню выбора операции\n0 - Выход из программы\n";
        cin >> choice;
        system("cls");
        switch (choice){
            case 1:
                cout << "Введите действительную и мнимую часть>>";
                double real, imaginary;
                cin >> real >> imaginary;
                complexNumbers.push_back(Complex{real, imaginary});
                system("cls");
            break;
            case 2:
                for (Complex num : complexNumbers){
                    cout << num << endl;
                }
                system("pause");
                system("cls");
            break;
            case 3:
                mhem = true;
                while (mhem){
                    cout << "Меню выбора операций с комплексными числами\n";
                    cout << "1 - Сумма\n2 - Разность\n3 - Произведение\n4 - Частное\n5 - Степень\n6 - Корень\n" <<
                            "7 - Вывод тригонометрической формы\n8 - Вывод показательной формы\n0 - Вернуться в главное меню\n";
                    int r, n, n1, n2, c2, p;
                    cin >> c2;
                    switch (c2){
                        case 1:
                            cout << "Выберите 2 числа>>";
                            cin >> n1 >> n2;
                            cout << "Сумма = " << complexNumbers[n1-1] + complexNumbers[n2-1];
                            system("pause");
                            system("cls");
                        break;
                        case 2:
                            cout << "Выберите 2 числа>>";
                            cin >> n1 >> n2;
                            cout << "Разность = " << complexNumbers[n1-1] - complexNumbers[n2-1];
                            system("pause");
                            system("cls");
                        break;
                        case 3:
                            cout << "Выберите 2 числа>>";
                            cin >> n1 >> n2;
                            cout << "Произведение = " << complexNumbers[n1-1] * complexNumbers[n2-1];
                            system("pause");
                            system("cls");
                        break;
                        case 4:
                            cout << "Выберите 2 числа>>";
                            cin >> n1 >> n2;
                            cout << "Частное = " << complexNumbers[n1-1] / complexNumbers[n2-1];
                            system("pause");
                            system("cls");
                        break;
                        case 5:
                            cout << "Выберите число>>";
                            cin >> n;
                            cout << "Выберите степень>>";
                            cin >> p;
                            cout << p << " степень этого числа равна ";
                            complexNumbers[n-1].toPower(p);
                            system("pause");
                            system("cls");
                        break;
                        case 6:
                            cout << "Выберите число>>";
                            cin >> n;
                            cout << "Выберите корень>>";
                            cin >> r;
                            cout << "Корень " << r << " степени этого числа равен ";
                            complexNumbers[n-1].complexSquare(r);
                            system("pause");
                            system("cls");
                        break;
                        case 7:
                            cout << "Выберите число>>";
                            cin >> n;
                            cout << "Тригонометрическая форма>> ";
                            complexNumbers[n-1].printTrigNumber();
                            system("pause");
                            system("cls");
                        break;
                        case 8:
                            cout << "Выберите число>>";
                            cin >> n;
                            cout << "Показательная форма>> ";
                            complexNumbers[n-1].printExpNumber();
                            system("pause");
                            system("cls");
                        break;
                        case 0:
                            system("cls");
                            mhem = false;
                        break;
                    }
                }
            break;
            case 0:
                return 0;
            break;
        }
    }

    return 0;
}