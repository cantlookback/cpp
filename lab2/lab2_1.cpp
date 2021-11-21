#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Time{
public:
    Time(){}

    Time(int m_H, int m_M, int m_S, int m_MS){
        if (m_MS >= 0){
        m_S += m_MS / 1000;
        MS = m_MS % 1000;           
        } else {
            m_S--;
            MS = 1000 + m_MS;
        }
        if (m_S >= 0){
        m_M += m_S / 60;
        S = m_S % 60;
        } else {
            m_M--;
            S = 60 + m_S;
        }
        if (m_M >= 0){
        m_H += m_M / 60;
        M = m_M % 60;
        } else {
            m_H--;
            M = 60 + m_M;
        }
        if (m_H >= 0){
        H = m_H % 24;
        } else {
            H = 24 + m_H;
        }
    }

    void setTime(int m_H, int m_M, int m_S, int m_MS){
        H = m_H;
        M = m_M;
        S = m_S;
        MS = m_MS;
    }

    void printTime(){
        cout << "Current time is " << H << ":" << M << ":" << S << ":" << MS << endl;
    }

    void addTime(int m_H, int m_M, int m_S, int m_MS){
        MS += m_MS;
        S += MS / 60;
        MS %= 1000;

        S += m_S;
        M += S / 60;
        S %= 60;

        M += m_M;
        H += M / 60;
        M %= 60;

        H += m_H;
        H = H % 24;
    }

    Time operator+(const Time &time){
        //TODO: доделать, избавиться от переполнения
        //!DONE Changed constructor: now it will corrects time when initialized
        return {H + time.H, M + time.M, S + time.S, MS + time.MS};
    }

    Time operator-(const Time &time){
        return {H - time.H, M - time.M, S - time.S, MS - time.MS};
    }

    vector<int> getTime(){
        return {H, M, S, MS};
    }

    friend ostream& operator<<(ostream& out, const Time& time);
    friend istream& operator>>(istream& in, Time& time);

    friend ofstream& operator<<(ofstream &out, const Time &time);
    friend ifstream& operator>>(ifstream &in, Time &time);

    friend stringstream& operator<<(stringstream &out, const Time &time);
    friend stringstream& operator>>(stringstream &out, Time &time);

private:
    int H, M, S, MS;
};

ostream& operator<<(ostream& out, const Time& time){
    out << time.H << ':' << time.M << ':' << time.S << ':' << time.MS;
    return out;
}

istream& operator>>(istream& in, Time& time){
    in >> time.H >> time.M >> time.S >> time.MS;
    return in;
}

ofstream& operator<<(ofstream &out, const Time &time){
    out << time.H << ':' << time.M << ':' << time.S << ':' << time.MS;
    return out;
}

ifstream& operator>>(ifstream &in, Time &time){
    string n, d = "";
    vector<int> v;
    in >> n;
    for (int i = 0; i < n.length(); i++){
        if (n[i] ==':'){
            v.push_back(stoi(d));
            d.clear();
            continue;
        }
        d += n[i];
    }
    v.push_back(stoi(d));
    d.clear();
    time.H = v[0];
    time.M = v[1];
    time.S = v[2];
    time.MS = v[3];
    return in;
}

stringstream& operator<<(stringstream &out, const Time &time){
    out << time.H << ':' << time.M << ':' << time.S << ':' << time.MS;
    return out;
}

stringstream& operator>>(stringstream &in, Time &time){
    string n, d = "";
    vector<int> v;
    in >> n;
    for (int i = 0; i < n.length(); i++){
        if (n[i] ==':'){
            v.push_back(stoi(d));
            d.clear();
            continue;
        }
        d += n[i];
    }
    v.push_back(stoi(d));
    d.clear();
    time.H = v[0];
    time.M = v[1];
    time.S = v[2];
    time.MS = v[3];

    return in;
}

int main(){
    ofstream out;
    ifstream in;
    Time time(22, 55, 50, 221);
    Time time2(2, 5, 5, 21);
    
    Time time3;

    stringstream str;
    
    str << time;
    str >> time3;
    cout << time3;

    return 0;
}

/**
*TODO: СТРОКИ, ФАЙЛ, КОНСОЛЬ на 3 потока
*!DONE
*TODO: cin cout time + - перегрузить
*!DONE
*TODO: Сложение/вычитание времени
*!DONE
*TODO: Конструкторы
*!DONE but idk what that mean
**/