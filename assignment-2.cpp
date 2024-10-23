/*Experiment No : 2

Develop an object oriented program in C++ to create a database of student information system containing the following information: Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete. */

#include <iostream>
using namespace std;
class data
{
private:
    string name;
    char bg;
    string address;
    string dob;
    string cldiv;
    string lic;
    static int c;
    int roll;
    long int phone;

public:
    data();
    static int getcount();
    void getdata();
    void show();
    data(data *obj);
    data(int roll, long int phone, string name, string address, string dob, string cldiv, string lic);
    ~data();
};

int data::c = 0;
data::data(data *obj)
{
    cout << "\nCopy constructor implemented" << endl;
}
data::~data()
{
    cout << "Destructor called \n";
}
void data::getdata()
{
    cout << "Enter roll number : ";
    cin >> roll;
    cout << "Enter telephone number : ";
    cin >> phone;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter address : ";
    cin >> address;
    cout << "Enter D.O.B : ";
    cin >> dob;
    cout << "Enter Class and Division : ";
    cin >> cldiv;
    cout << "Enter license number : ";
    cin >> lic;
}

void data::show()
{
    cout << "Name :" << name << endl;
    cout << "Roll Number :" << roll << endl;
    cout << "Telephone Number :" << phone << endl;
    cout << "Address :" << address << endl;
    cout << "Date of birth :" << dob << endl;
    cout << "Class and division: " << cldiv << endl;
    cout << "License number :" << lic << endl;
}

data::data(int roll, long int phone, string name, string address, string dob, string cldiv, string lic)
{
    cout << "\nParameterized Constructor" << endl;
    c++;
    this->roll = roll;
    this->phone = phone;
    this->name = name;
    this->address = address;
    this->dob = dob;
    this->cldiv = cldiv;
    this->lic = lic;
}

data::data()
{
    roll = 0;
    phone = 0;
    name = "N.A.";
    address = "N.A.";
    dob = "N.A.";
    cldiv = "N.A.";
    lic = "N.A.";
    cout << "Default Constructor" << endl;
    c++;
}

int data::getcount()
{
    return c;
}

int main()
{
    int num;
    data *d1 = new data();
    d1->show();
    delete d1;
    data *d2 = new data(73, 9823694961, "Vijay", "Ravet", "26.11.85", "SE A", "MSIN85U");
    d2->show();
    data *d3 = new data(d2);
    d3->show();
    delete d2;
    cout << "\nEnter size of database : ";
    cin >> num;
    data dx[num];
    for (int i = 0; i < num; i++)
    {
        dx[i].getdata();
    }
    for (int i = 0; i < num; i++)
    {
        dx[i].show();
    }
    cout << "Number of constructor calls and total number of objects:" << data::getcount() << endl;
    return 0;
}