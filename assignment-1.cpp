/*Experiment No: 01
ImplementaclassComplexwhichrepresentstheComplexNumberdatatype.
Implement
The following operations:
1. Constructor (including a default constructor which creates the
complex number 0+0i).
2. Overloaded operator + to add two complex numbers.
3. Overloaded operator * to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers. */

#include <iostream>
using namespace std;
class complex
{
    float x;
    float y;

public:
    complex() // Default constructor
    {
        x = 0;
        y = 0;
    }
    complex operator+(complex); // this is declaration of function to overload + Operator
    complex operator*(complex); // function to overload * Operator

    friend istream &operator>>(istream &input, complex &t)
    {
        cout << "Enter the real part : ";
        input >> t.x;
        cout << "Enterthe imaginary part : ";
        input >> t.y;
    }

    friend ostream &operator<<(ostream &output, complex &t)
    {
        output << t.x << " + " << t.y << "i\n";
    }
};

complex complex::operator+(complex c)
{
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

complex complex::operator*(complex c)
{
    complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (y * c.x) + (x * c.y);
    return temp2;
}

int main()
{
    complex c1, c2, c3, c4; // object of class
    cout << "Default constructor value = ";
    cout << c1;
    cout << "\nEnter the 1st number : ";
    cin >> c1;
    cout << "\nEnter the 2nd number : ";
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "\nThe firstnumber is : ";
    cout << c1;
    cout << "\nThe secondnumber is : ";
    cout << c2;
    cout << "\nThe addition is : ";
    cout << c3;
    cout << "\nThe multiplication is : ";
    cout << c4;
    return 0;
}