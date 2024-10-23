/*      PROBLEM STATEMENT
 Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file. */

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char Give_Info[200];
    ofstream o_file;                          // provides output operations
    o_file.open("Information.bat", ios::out); // open for output operations
    cout << "\nEnter information to store it in file.(Not more than 200 characters)\n";
    fgets(Give_Info, 200, stdin);
    o_file << Give_Info << endl;
    o_file.close();

    char Get_Info[200];
    ifstream i_file;                         // provides input operations
    i_file.open("Information.bat", ios::in); // open for input operations
    i_file.getline(Get_Info, 200);           // read next string from file
    cout << "\nGiven Information is :\n";
    cout << Get_Info << endl;
    i_file.close();

    return 0;

    /*A batch file is a script file.
    It consists of a series of commands to be executed by the command-line interpreter,
    stored in a plain text file.*/
}