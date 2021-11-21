#include <iostream>
#include <vector>

using namespace std;

class RSA {

public:

    RSA(int m_q, int m_p, string msg) {
        message = msg;
        q = m_q;
        p = m_p;
        euler = (q - 1) * (p - 1);
        N = p * q;
    }

    unsigned __int64 calculateD(unsigned __int64 e, unsigned __int64 euler) {

        unsigned __int64 d;
        unsigned __int64 k = 1;

        while (true) {
            k = k + euler;

            if (k % e == 0) {
                d = (k / e);
                return d;
            }
        }

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
            swap(a, b);
        }
        while (a % b != 0) {
            a = a % b;
            swap(a, b);
        }
        return b;
    }

    void generateKeys() {
        for (e = rand() % euler; NOD(e, euler) != 1; e = rand() % euler);
        d = calculateD(e, euler);

        public_key = { e, N };
        private_key = { d, N };
    }

    void printKeys() {
        cout << "Public key: " << public_key.first << "   " << public_key.second << endl;
        cout << "Private key: " << private_key.first << "   " << private_key.second << endl;
    }

    void encodeMessage() {
       //convert char -> unsigned
        for (unsigned char x : message) {
            intMessage.push_back(x);
        }
        for (unsigned x : intMessage) {
            encodedMessage.push_back(modPow(x, public_key.first, public_key.second));
        }
        message.clear();
    }

    void decodeMessage() {
        for (unsigned x : encodedMessage) {
            decodedMessage.push_back(modPow(x, private_key.first, private_key.second)); 
        }
        //convert unsigned -> char
        for (unsigned x : decodedMessage) {
            message += (static_cast<unsigned char>(x));
        }
    }

    vector<unsigned> getEncodedMessage() {
        return encodedMessage;
    }

    void printDecodedMessage(){
        cout << "Encoded message: ";
        for (auto x : encodedMessage){
            cout << x << "  ";
        }
        cout << endl << "Decoded message:";
        cout << message << endl;
    }

private:
    unsigned __int64 N;
    unsigned __int64 q, p;
    unsigned __int64 e, d;
    unsigned __int64 euler;

    string message;

    vector<unsigned> intMessage, decodedMessage, encodedMessage;
    pair<unsigned, unsigned> public_key, private_key; //{e, N} //{d, N}
};