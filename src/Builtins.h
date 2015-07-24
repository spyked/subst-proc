#ifndef __BUILTINS_H__
#define __BUILTINS_H__

#include <iostream>
#include <list>
#include <deque>
#include <memory>

class Machine;
class Word;

// Base classes

class Machine {
	public:
		void eval(Word &w);
		void eval(std::list<Word *> &l);
		void anonPush(Word &w);
		std::unique_ptr<Word> anonPop();

	private:
		std::deque<std::unique_ptr<Word>> anon_stack;
		friend std::ostream& operator<<(std::ostream&, const Machine&);
};

class Word {
	protected:
		virtual void read(Machine &m) = 0;
		friend void Machine::eval(Word &w);

		virtual std::ostream &print(std::ostream &strm) const;
		friend std::ostream& operator<<(std::ostream&, const Word&);
};

#endif
