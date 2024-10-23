/* PROBLEM STATEMENT
Design an E-mail Verifier which accepts the email address from the user.
Depending upon the input given by user display appropriate results.
Use the following concepts in the Project Constructor, Destructor, new, delete, exceptional
handling, string handling functions, etc.
*/
#include <iostream>
#include <string.h>
using namespace std;
class Email
{
    char id[100];
    char *Email_Id;
    int size;

public:
    Email()
    {
        cout << "Enter Email Id : ";
        cin >> id;
        Email_Id = new char[sizeof(id) + 1];
        strcpy(Email_Id, id);
        size = strlen(Email_Id);
        cout << "-- -- -- -- --\n"
             << Email_Id << endl;
    }
    ~Email()
    {
        delete[] Email_Id;
    }
    bool HasSpecialSymbols()
    {
        int k = 0, temp;
        for (int i = size - 1; i >= 0; i--)
        {
            if (!isalpha(Email_Id[i]))
            {
                if (Email_Id[i] != '.') // If tere is some special character after last '.'(dot) Email id is invalid....
                    return 0;
            }

            k++; // k -- to check how many character are ther after last '.'(dot)..
            if (Email_Id[i] == '.')
            {
                k--;                // last character was dot
                if (k > 3 || k < 2) // NO email id contain more than 3 or less than 2 character after last  dot.
                    return 0;
                temp = i + 1;
                for (; i >= 0; i--)
                {
                    if (Email_Id[i] == '@') // One '@' symbol should be present in Email id, and it should be before last dot.
                    {
                        if (temp == i) // '@' can not be placed imediately befor dot. i.e temp was geven value immediately before dot
                            return 0;  // and if '@' is found at place of temp... Email id is invalid..
                        else
                            return 1;
                    }
                }
            }
        }
        return 0; // If some of the condition missed... Email id is invalid...
    }
    bool First_char() // First character of id should be alphabet.
    {
        if (isalpha(Email_Id[0]))
            return 1;
        return 0;
    }
    void check_id(void)
    {
        if (First_char() && HasSpecialSymbols())
        {
        }
        else
            throw 0;
    }
};

int main()
{
    Email E;
    try
    {
        E.check_id();
        cout << "\nEntered Email id is valid.";
    }
    catch (int)
    {
        cout << "\nEntered Email id is invalid.";
    }
    cout << endl
         << endl;
    return 0;
}