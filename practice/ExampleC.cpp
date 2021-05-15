#include <iostream>

class Example;

class ExampleA;
class ExmapleB;


class ExampleC{
	private:
		Example ex;
	public:
		void showExC(Example ex);
};

void ExampleC::showExC(Example ex){
	std::cout << ex.getC() << std::endl;
}
