#include <iostream>

class Example;

class ExampleA;
class ExmapleB;

class ExampleC
{
  private:
    Example* ex;

  public:
    ExampleC();
    ~ExampleC();

    void showExC();
};

ExampleC::ExampleC(){
  this->ex=new Example();
}
ExampleC::~ExampleC(){
  delete this->ex;
}
void ExampleC::showExC()
{
  std::cout << this->ex->getC() << std::endl;
}
