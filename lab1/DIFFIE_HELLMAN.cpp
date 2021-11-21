#include <iostream>
#include <random>
#include <climits>

using namespace std;



class DIFFIE_HELLMAN {

public:
    DIFFIE_HELLMAN(int m_p, int m_g){
        p = m_p;
        g = m_g;
        a = rand() % INT_MAX;
        b = rand() % INT_MAX;
    }

    unsigned __int64 modPow(unsigned __int64 num, unsigned __int64 pow, unsigned __int64 p,  unsigned __int64 b = 1) {
        unsigned __int64 res = b;

        for (int i = 1; i <= pow; ++i) {
            res = res * num;
            res = res % p;
        }
        return res;
    }



    void generateK(){
        Xa = modPow(g, a, p);
        Xb = modPow(g, b, p);
        Ka = modPow(Xb, a, p);
        Kb = modPow(Xa, b, p);
    }

    void printK(){


        cout << Ka << " " << Kb << endl;
    }

private:
    int p, g, a, b, Xa, Xb, Ka, Kb;

};