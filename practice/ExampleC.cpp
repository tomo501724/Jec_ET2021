#include <iostream>

class Example;

class ExampleA;
class ExmapleB;

class ExampleC
{
	private:
		Example ex;

	public:
        ExampleC(Example ex);
		void showExC();
};

ExampleC::ExampleC(Example ex){
    this->ex=ex;
}
void ExampleC::showExC()
{
	std::cout << this->ex.getC() << std::endl;
}
