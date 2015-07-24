#ifndef __OPERAND_H__
#define __OPERAND_H__

#include "Builtins.h"

class Operand : public Word {
	protected:
		virtual void read(Machine &m) = 0;
	
	private:
		virtual std::ostream &print(std::ostream &strm) const;
		friend std::ostream& operator<<(std::ostream&, const Word&);
};

class IntOperand : public Operand {

	public:
		IntOperand() : value(0) {};
		IntOperand(int v) : value(v) {};

		int getValue();

	private:
		int value;

		virtual std::ostream &print(std::ostream &strm) const;
		friend std::ostream& operator<<(std::ostream&, const Word&);

	protected:
		virtual void read(Machine &m);
};

#endif
