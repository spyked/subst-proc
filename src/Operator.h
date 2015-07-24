#ifndef __OPERATOR_H__
#define __OPERATOR_H__

#include "Builtins.h"
#include "Operand.h"

class Operator : public Word {
	protected:
		virtual void read(Machine &m) = 0;

	private:
		virtual std::ostream &print(std::ostream &strm) const;
		friend std::ostream& operator<<(std::ostream&, const Word&);
};

class AdditionOperator : public Operator {
	protected:
		virtual void read(Machine &m);

	private:
		virtual std::ostream &print(std::ostream &strm) const;
		friend std::ostream& operator<<(std::ostream&, const Word&);
};

#endif
