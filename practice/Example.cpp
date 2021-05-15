
class Example {
    private:
    int     a = 2;
    double  b = 2.0;
    int     c = 3;

    public:
    void aShow();
    void bShow();
    void cShow();
    int getC();
}

void Example::aShow() {
    ExampleA a();
    
}

void Example::bShow() {
    ExampleB b();
}

void Example::cShow() {
    Example c();
}

int Example::getC() {
    return c;
}