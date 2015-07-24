#include "Operand.h"

std::ostream& Operand::print(std::ostream &strm) const
{
	return strm << "Operand";
}

void IntOperand::read(Machine &m)
{
	m.anonPush(*this);
}

int IntOperand::getValue()
{
	return value;
}

std::ostream& IntOperand::print(std::ostream &strm) const
{
	return strm << "Int(" << value << ")";
}
