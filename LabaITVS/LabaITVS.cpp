/**************
Zaimplementuj klasę reprezentującą liczbę zespoloną zawierającą:
- Konstruktor domyślny, kopiujący i parametryczny
- Destruktor
- Przeładowane operatory: +, -, *, /, =
**************/

#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
    float Real, Imaginary;


public:
    ComplexNumber() // konstruktor domyslny
    {
        Real = 1.0f;
        Imaginary = 1.0f;
    };    
    ComplexNumber(float re, float im)     //konstruktor parametryczny
    {
        Real = re;
        Imaginary = im;
    };

    ComplexNumber(const ComplexNumber& other)    //konstruktor kopiujacy
    {
        Real = other.Real;
        Imaginary = other.Imaginary;
    };

    ~ComplexNumber() 
    {
        //cout << "papa" << endl;
    };

    float getReal()
    {
        return Real;
    };

    float getImaginary()
    {
        return Imaginary;
    };


    ComplexNumber operator +(const ComplexNumber& other) const
    {
        return ComplexNumber(Real + other.Real, Imaginary + other.Imaginary);
    };

    ComplexNumber operator -(const ComplexNumber& other) const
    {
        return ComplexNumber(Real - other.Real, Imaginary - other.Imaginary);
    };

    ComplexNumber operator =(const ComplexNumber& other)
    {
        Real = other.Real;
        Imaginary = other.Imaginary;
        return *this;

    };

    ComplexNumber operator *(const ComplexNumber& other) const
    {
        return ComplexNumber((Real * other.Real) - (Imaginary * other.Imaginary), (Real * other.Imaginary) + (Imaginary * other.Real));
    };

    ComplexNumber operator /(const ComplexNumber& other) const
    {
        float tempR = (Real * other.Real + Imaginary * other.Imaginary) / ((other.Real * other.Real) + (other.Imaginary * other.Imaginary));
        float tempI = (Imaginary * other.Real - Real * other.Imaginary) / ((other.Real * other.Real) + (other.Imaginary * other.Imaginary));

        return ComplexNumber(tempR, tempI);
    };


};

int main()
{
    ComplexNumber z1;
    ComplexNumber z2(4.5, 6);
    ComplexNumber z3(z2);
    ComplexNumber z4;   //pomocnicza zmienna do robienia obliczen

    cout << "Liczba 1: " << z1.getReal() << " + " << z1.getImaginary() << "i" << endl;
    cout << "Liczba 2: " << z2.getReal() << " + " << z2.getImaginary() << "i" << endl;
    cout << "Liczba 3: " << z3.getReal() << " + " << z3.getImaginary() << "i" << endl << endl;

    z4 = z1 + z2;
    cout << "Suma L1 i L2: " << z4.getReal() << " + " << z4.getImaginary() << "i" << endl;
    
    z4 = z3 * z2;
    cout << "Iloczyn L3 i L2: " << z4.getReal() << " + " << z4.getImaginary() << "i" << endl;
    
    z4 = z4 - z2;
    cout << "Od poprzedniego iloczynu odejmiemy L2: " << z4.getReal() << " + " << z4.getImaginary() << "i" << endl;

    z4 = z4 / z2;
    cout << "A teraz wynik podzielimy przez L2: " << z4.getReal() << " + " << z4.getImaginary() << "i" << endl;

    z1 = z2;
    cout << "Teraz L1 jest L2: " << z1.getReal() << " + " << z1.getImaginary() << "i" << endl;

}