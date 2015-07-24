#include <list>
#include <iostream>

#include "Builtins.h"
#include "Operand.h"
#include "Operator.h"

int main(void)
{
	Machine m;

	IntOperand *i1 = new IntOperand(2);
	IntOperand *i2 = new IntOperand(3);
	IntOperand *i3 = new IntOperand(4);
	AdditionOperator *a1 = new AdditionOperator;

	// Just a small test
	std::list<Word *> inputs;
	inputs.push_back(i1);
	inputs.push_back(i2);
	inputs.push_back(i3);
	inputs.push_back(a1);

	m.eval(inputs);
	std::cout << m;

	return 0;
}
