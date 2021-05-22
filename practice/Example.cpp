
class Example {
    private:
    int     a = 2;
    double  b = 2.0;
    int     c = 3;

    public:
    void aShow();
    void bShow();
    void cShow();
    void dShow();
    int getC();
}

void Example::aShow() {
    ExampleA a();
    a.showExA(this->a);
}

void Example::bShow() {
    ExampleB b();
    b.showExB(this->b);
}

void Example::cShow() {
    Example c();
    c.showExC(*this);
}

void Example::dShow() {
    ExampleD d();
    int a = d.showExD(this->a);
}

int Example::getC() {
    return c;
}