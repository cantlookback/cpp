#include <iostream>
#include <vector>
using namespace std;



class EL_GAMAL {

public:
    EL_GAMAL(int m_p, int m_g, string msg){
        p = m_p;
        //g^fi mod p = 1
        g = m_g;   //TODO : g generation
        message = msg;
        x = rand() % (p - 1);
        y = modPow(g, x, p);
        public_key = {y, g, p};
    }

    unsigned __int64 modPow(unsigned __int64 num, unsigned __int64 pow, unsigned __int64 p,  unsigned __int64 b = 1) {
        unsigned __int64 res = b;

        for (int i = 1; i <= pow; ++i) {
            res = res * num;
            res = res % p;
        }
        return res;
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
    
    void encodeMessage(){
        for (k = rand() % (p - 1); NOD(k, p - 1) != 1; k = rand() % (p - 1));

        //convert char -> unsigned
        for (unsigned char z : message) {
            intMessage.push_back(z);
        }
        
        a = modPow(g, k, p);

        for (unsigned z : intMessage){
            encodedMessage.push_back(modPow(y, k, p, z)); 
        }

        message.clear();
        
        cout << endl << "Encoded message: ";
        for (unsigned z : encodedMessage){
            cout << z << " ";
        }
    }

    void decodeMessage(){
        for (unsigned z : encodedMessage){
            decodedMessage.push_back(modPow(a, p - 1 - x, p, z));
        }
        for (unsigned z : decodedMessage) {
            message += (static_cast<unsigned char>(z));
        }
    }

    void printMessage(){
        cout << endl << "Decoded message: " << message << endl;
    }

    vector<unsigned> getEncodedMessage(){
        return encodedMessage;
    }


private:
    int p, g, x, y, a, k;
    string message;
    vector<int> public_key;
    vector<unsigned> encodedMessage, decodedMessage, intMessage;
};