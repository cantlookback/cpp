#include "IError.h"
//! IError
IError::IError(string m_errorType) : errorType(m_errorType){}

void IError::printErrorList(){
    for (auto error : errorList){
        cout << error << endl;
    }
}

//! MathError
MathError::MathError() : IError("Math"){}

void MathError::print(){
    cout << errorType << " error!" << endl;
    errorList.push_back(errorType);
}

//! LogicError
LogicError::LogicError() : IError("Logic"){}

void LogicError::print(){
    cout << errorType << " error!" << endl;
    errorList.push_back(errorType);
}