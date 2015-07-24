#include "Builtins.h"

void Machine::eval(Word &w) {
	w.read(*this);
}

void Machine::eval(std::list<Word *> &l) {
	for (auto it = l.begin(); it != l.end(); ++it)
		eval(**it);
}

void Machine::anonPush(Word &w)
{
	anon_stack.push_back(std::unique_ptr<Word>(&w));
}


std::unique_ptr<Word> Machine::anonPop()
{
	if (anon_stack.empty())
		return NULL;

	auto w = std::move(anon_stack.back());
	anon_stack.pop_back();

	return w;
}

std::ostream& Word::print(std::ostream &strm) const
{
	return strm << "Word";
}

std::ostream& operator<< (std::ostream &strm, const Machine &m)
{
	strm << "Machine: " << &m << std::endl;
	strm << "AnonStack: ";
	for (auto it = m.anon_stack.begin(); it != m.anon_stack.end(); ++it)
		strm << **it << " ";

	return strm << std::endl;
}

std::ostream& operator<<(std::ostream& strm, const Word& w)
{
	return w.print(strm);
}
