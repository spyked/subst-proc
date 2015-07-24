CXXFLAGS = -std=c++14

all: subst-proc

subst-proc: SubstProc.o Builtins.o Operand.o Operator.o
	$(CXX) $(CXXFLAGS) -o $@ $^

SubstProc.o: src/SubstProc.cxx
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Builtins.o: src/Builtins.cxx
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Operand.o: src/Operand.cxx
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Operator.o: src/Operator.cxx
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf subst-proc *.o
