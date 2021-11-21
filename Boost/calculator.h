#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

class Calculator {
public:
	
	Calculator(int m_value) : Value(m_value) {}

private:

	void Divide(int value) {
		if (value == 0) {
			throw std::invalid_argument("Деление на ноль!");
		}
		Value /= value;
	}

	void Multiply(int value) {
		Value *= value;
	}

	int Result() const {
		return Value;
	}

	int Value;
};
#endif