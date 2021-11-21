#include <iostream>
#include <climits>
#include <vector>
#include <ctime>

using namespace std;



class SHAMIR {

public:
	SHAMIR(string msg, int m_p) {
        message = msg;
		p = m_p;
	}

    void doThings(){
        srand(time(0));
        for (Ca = rand() % INT_MAX; NOD(Ca, p - 1) != 1; Ca = rand() % INT_MAX);
        for (Da = rand() % INT_MAX; modPow(Ca, 1, p - 1, Da) != 1; Da = rand() % INT_MAX);

        for (Cb = rand() % INT_MAX; NOD(Cb, p - 1) != 1; Cb = rand() % INT_MAX);
        for (Db = rand() % INT_MAX; modPow(Cb, 1, p - 1, Db) != 1; Db = rand() % INT_MAX);

        cout << Ca << " " << Da << "    " << Cb << " " << Db << endl;
        
        //char -> unsigned
        for (unsigned char x : message){
            intMessage.push_back(x); 
        }

        for (unsigned x : intMessage){
            M1.push_back(modPow(x, Ca, p));
        }

        for (unsigned x : M1){
            M2.push_back(modPow(x, Cb, p));
        }

        for (unsigned x : M2){
            M3.push_back(modPow(x, Da, p));
        }

        for (unsigned x : M3){
            M4.push_back(modPow(x, Db, p));
        }

        message.clear();

        for (auto x : M4){
            message += static_cast<unsigned char>(x);
        }
    }


    void printMessages(){
        cout << "intMessage: ";
        for (auto x : intMessage){
            cout << x << " ";
        }
        cout << endl << "M1: ";
        for (auto x : M1){
            cout << x << " ";
        }
        cout << endl << "M2: ";
        for (auto x : M2){
            cout << x << " ";
        }
        cout << endl << "M3: ";
        for (auto x : M3){
            cout << x << " ";
        }
        cout << endl << "M4: ";
        for (auto x : M4){
            cout << x << " ";
        }
        cout << endl << "Decoded message: " << message << endl;
    }

    unsigned NOD(unsigned a, unsigned b) {
        if (a < b) {
            std::swap(a, b);
        }
        while (a % b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return b;
    }

    unsigned __int64 modPow(unsigned __int64 num, unsigned __int64 pow, unsigned __int64 p,  unsigned __int64 b = 1) {
        unsigned __int64 res = b;

        for (int i = 1; i <= pow; ++i) {
            res = res * num;
            res = res % p;
        }
        return res;
    }
    
    

private:
	int p, Ca, Da, Cb, Db;
    string message;
    vector<unsigned> intMessage, M1, M2, M3, M4;

};