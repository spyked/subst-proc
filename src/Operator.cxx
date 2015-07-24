#include "Operator.h"

void AdditionOperator::read(Machine &m)
{
	std::unique_ptr<IntOperand> i1 (static_cast<IntOperand *>(m.anonPop().release()));
	std::unique_ptr<IntOperand> i2 (static_cast<IntOperand *>(m.anonPop().release()));
	IntOperand *res = new IntOperand(i1->getValue() + i2->getValue());

	m.anonPush(*res);
}

std::ostream& Operator::print(std::ostream &strm) const
{
	return strm << "Op";
}

std::ostream& AdditionOperator::print(std::ostream &strm) const
{
	return strm << "+";
}
