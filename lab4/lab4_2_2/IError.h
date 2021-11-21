#ifndef IERROR_H
#define IERROR_H
#include <iostream>
#include <vector>
using namespace std;

class IError{
public:
    IError(string m_errorType);
    
    virtual void print() = 0;

    void printErrorList();

protected:
    string errorType;
    vector<string> errorList;
};

class MathError : IError{
public:
    MathError();

    void print();
};

class LogicError : IError{
public:
    LogicError();

    void print();
};


#endif