#include <iostream>
#include <vector>
#include "RSA.cpp"
#include "SHAMIR.cpp"
#include "DIFFIE_HELLMAN.cpp"
#include "EL_GAMAL.cpp"
#include <Windows.h>

using namespace std;

void Rsa(){
    cout << "Введите простые q и p>>";
    int q, p;
    cin >> q >> p;
    
    cout << "Введите сообщение: ";
    string message;
    cin >> message;

    RSA rsa(q, p, message);

    rsa.generateKeys();
    rsa.printKeys();    

    rsa.encodeMessage();
    rsa.decodeMessage();

    rsa.printDecodedMessage();

}

void Shamir(){
    cout << "Введите большое p>>";
    int p;
    cin >> p;

    cout << "Введите сообщение>>";
    string message;
    cin >> message;

    SHAMIR shamir(message, p);

    shamir.doThings();
    shamir.printMessages();

}

void Diffie_hellman(){
    cout << "Введите p и g>>";
    int p, g;
    cin >> p >> g;

    DIFFIE_HELLMAN dh(p, g);

    dh.generateK();
    cout << "Общий ключ: ";
    dh.printK();
}

void El_gamal(){
    cout << "Введите p и g>>";      //401 3 as an example
    int p, g;
    cin >> p >> g;
    
    string message;
    cout << "Введите сообщение: ";
    cin >> message;

    EL_GAMAL eg(p, g, message);

    eg.encodeMessage();
    eg.decodeMessage();

    eg.printMessage();
}

/*int main() {
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    
    int choice;

    while (true){
        
        cout << "Выберите шифр:\n1 - Диффи-Хеллман\n2 - Эль-Гамаль\n3 - RSA\n4 - Шамир\n0 - Выход\n";
        cin >> choice;

        switch (choice){
            case 1:
                Diffie_hellman();
            break;
            case 2:
                El_gamal();
            break;
            case 3:
                Rsa();
            break;
            case 4:
                Shamir();
            break;
            case 0:
                return 0;
            break;

            default:
                cout << "Ошибка, пожалуйста, введите другое число." << endl;
            break;
        }
    }
    
    return 0;
}*/
