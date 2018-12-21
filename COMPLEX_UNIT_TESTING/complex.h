#ifndef COMPLEX_H
#define COMPLEX_H
#include<ostream>
#include<cstdlib>

namespace csis3700{

class complex
{
    public:
        complex();
        complex(double r, double i=0);
        double get_real() const;
        double get_imaginary() const;
        double magnitude() const;
        double norm() const;
        complex conjugate() const;
        complex negate() const;
        complex reciprocal() const;


    private:
        double real, imaginary;
};
    std::ostream& operator<<(std::ostream& outs,const complex& c);
    bool operator == (const complex& c, const complex& d);
    bool operator != (const complex&c, const complex& d);
    complex operator + (const complex&c, const complex& d);
    complex operator - (const complex&c, const complex& d);
    complex operator * (const complex&c, const complex& d);
    void demo();
    complex operator / (const complex&c, const complex& d);
}

#endif // COMPLEX_H
