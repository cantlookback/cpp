#include <iostream>
#include <vector>

using namespace std;

struct Axis{
    double x, z, t;
};

struct Parametrs{
    double a, b, c;
};

class Term {
    public:
    Term(char m_op, double m_number){
        op = m_op;
        number = m_number;
    }

    double Done(double num){
        if (op == '+'){
            num += number;
        }
        if (op == '-'){
            num -= number;
        }
        return num;
    }



private:
    char op;
    double number;
};

class NumberOfTerms {
public:    
    void addTerm(char op, double n){
        terms.push_back({op, n});
    }

    double Execute(double num){
        int num1 = -num;
        for (Term term : terms){
            num1 += term.Done(num);
        }
        return num1;
    }

private:
    vector<Term> terms;
};

NumberOfTerms makeY(Axis ax, Parametrs p){
    NumberOfTerms function;
    function.addTerm('-', ax.z*p.a + p.b);
    function.addTerm('+', p.c*ax.t);
    return function;
}

double EvaluateY(Axis ax, Parametrs p){
    NumberOfTerms y;
    y = makeY(ax, p);
    return y.Execute(ax.x);
}

// double EvaluateY(Axis ax, Parametrs p){
//     double y;
//     y = ax.x - ax.z*p.a - p.b + p.c*ax.t;
//     return y;

// }


int main(){
//TODO: Класс, который будет содержать в себе части, и класс, в котором они в совокупности. В одном хранятся и вычисляются, в другом содержатся слагаемые
//y = F(x, z, t) = x - a*z - b + t*c
    Axis A = {1,3,5}; //x z t
    Parametrs P = {2,2,1};  //a b c  1 - 6 - 2 + 5

    cout << EvaluateY(A, P);


    return 0;
}