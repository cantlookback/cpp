#define BOOST_TEST_MODULE testCalculator
#include "calculator.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(testSuiteCalculator)

struct Fixture
{
	Fixture() : calculator(12) {}

	~Fixture() {}

	Calculator calculator;
};

BOOST_FIXTURE_TEST_CASE(testCalculator, Fixture)
{
	BOOST_CHECK_EQUAL(calculator.Result(), 12);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorDivide, Fixture)
{
	calculator.Divide(3);
	BOOST_CHECK_EQUAL(calculator.Result(), 3);
	calculator.Divide(2);
	BOOST_CHECK_EQUAL(calculator.Result(), 2);
}

BOOST_FIXTURE_TEST_CASE(testCalculatorMultiply, Fixture)
{
	calculator.Multiply(2);
	BOOST_CHECK_EQUAL(calculator.Result(), 24);
	calculator.Multiply(3);
	BOOST_CHECK_EQUAL(calculator.Result(), 72);
}

BOOST_AUTO_TEST_SUITE_END()

