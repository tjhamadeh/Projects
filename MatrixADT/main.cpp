#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

/*******************************************************************************
* Toufic Hamadeh
* Programming Assignment - Matrix
* Due Date: March 1, 2012
* Class: CIS-277-601
* 
* Assignment: Create a program where the user enters a set of matrixs and then is given 
*             a list of different operations he/she can choose to select. When the 
*             operation is carried out the data is printed directly to an output file.
*******************************************************************************/

struct matrix // matrix structure
{
    string name;
    double a;
    double b;
    double c;
    double d;
};

bool openFile(fstream &); // function prototype - opens output.txt
void get_matrix(fstream &, matrix &); // function prototype - asks user to input matrix
void calc_sum(fstream &, matrix &, matrix &, matrix &); // function prototype - calculates sum
void calc_diff(fstream &, matrix &, matrix &, matrix &); // function prototype - calculates difference
void calc_scal(fstream &, matrix &, matrix &, double &); // function prototype - calculates scalar product
void calc_prod(fstream &, matrix &, matrix &, matrix &); // function prototype - calculates multiplcation
void calc_inverse(fstream &, matrix &, matrix &, matrix &); // function prototype - calculates inverse
void print_matrix(fstream &, matrix &); // function prototype - 
void closeFile(fstream &); // function prototype - closes output.txt

int main () { // start main
    // declare variables
    int choice;
    double k;
    fstream outfile;
    
    matrix m1;
    matrix m2;
    
    matrix add;
    matrix diff;
    matrix sca1;
    matrix sca2;
    matrix prod;
    matrix inv;
    
    if(!openFile(outfile)) { // if - check if openfile failed
         cout << "Could not open file.\n";     
    }
    get_matrix(outfile, m1);
    print_matrix(outfile, m1);
    cin.ignore();
    get_matrix(outfile, m2);
    print_matrix(outfile, m2);
    do { // do while for switch menu
        system("CLS");
        cout << "Select one:\n"
             << "1) Matrix Addition\n"
             << "2) Matrix Subtraction\n"
             << "3) Matrix Scalar Multiplication\n"
             << "4) Matrix Multiplication\n"
             << "5) Matrix Inverse\n"
             << "6) Quit\n"
             << ">> ";
        cin  >> choice;

        switch(choice) { // switch start - select function prototype(s) - options 1-6
            case 1:
                cout << "\nMatrix Addition!\n";
                calc_sum(outfile, m1, m2, add);
                print_matrix(outfile, add);
                
            break;
            
            case 2: // subtracts matrix and prints to outfile
                cout << "\nMatrix Subtraction!\n";
                calc_diff(outfile, m1, m2, diff);
                print_matrix(outfile, diff);
            break;
            
            case 3: // matrix scalar and prints to outfile
                cout << "\nMatrix Scalar Multiplication!\n";
                cout << "Please enter a value for k: ";
                cin  >> k;
                calc_scal(outfile, m1, sca1, k);
                print_matrix(outfile, sca1);
                calc_scal(outfile, m2, sca2, k);
                print_matrix(outfile, sca2);
            break;
            
            case 4: // multiplies matrix and prints to outfile
                cout << "\nMatrix Multiplication!\n";
                calc_prod(outfile, m1, m2, prod);
                print_matrix(outfile, prod);
            break;
            
            case 5: // inverse matrix and prints to outfile
                cout << "\nMatrix Inverse!\n";
                calc_inverse(outfile, m1, m2, inv);
                print_matrix(outfile, inv);
            break;
            
            case 6: // exit switch
                cout << "\nExiting...\n";
            break;
            
            default: // default option
                cout << "\nPlease select a value between 1 - 6.";
            break;
        } // end switch
        system("pause");
    } while (choice != 6); // end do-while
    closeFile(outfile);  // close output.txt
    return 0;
} // end main

void get_matrix(fstream &outfile, matrix &m) {
    char choice;
    system("CLS");
    cout << "Name your Matrix: ";
    getline(cin,m.name);
    do {
        cout << "\nEnter the following numbers: \n";
        cout << "TOP-LEFT:\t";
        cin  >> m.a;
        cout << "TOP-RIGHT:\t";
        cin  >> m.b;
        cout << "BOT-LEFT:\t";
        cin  >> m.c;
        cout << "BOT-RIGHT:\t";
        cin  >> m.d;
        system("CLS");
        cout << endl     << " "     << m.name         << ": \n"
             << "  -"    << setw(7) << " " << setw(7) << " " << "-\n"
             << " |"     << setw(7) << m.a << setw(7) << m.b << "  |\n"
             << " |"     << setw(7) << " " << setw(7) << " " << "  |\n"
             << " |"     << setw(7) << m.c << setw(7) << m.d << "  |\n"
             << "  -"    << setw(7) << " " << setw(7) << " " << "-\n";
        cout << "Would you like to save this matrix? (Y/N): ";
        cin  >> choice;
    } while (!choice == 'N' || choice == 'n');
    
    outfile << "\n " << m.name << endl;
}

// function - open file for output start
bool openFile(fstream &o) {
     o.open("output.txt", ios::out);
     if(o.fail())
         return false;
     return true;
}

// function - calculates matrix sum
void calc_sum(fstream &outfile, matrix &m1, matrix &m2, matrix &add) {
    add.a = m1.a + m2.a;
    add.b = m1.b + m2.b;
    add.c = m1.c + m2.c;
    add.d = m1.d + m2.d;
    
    outfile << "\n Matrix Addition: \n";
}

// function - calculates matrix difference
void calc_diff(fstream &outfile, matrix &m1, matrix &m2, matrix &dif) {             
    dif.a = m1.a - m2.a;
    dif.b = m1.b - m2.b;
    dif.c = m1.c - m2.c;
    dif.d = m1.d - m2.d;
    
    outfile << "\n Matrix Subtraction: \n";
}

// function - calculates scalar product
void calc_scal(fstream &outfile, matrix &m, matrix &scal, double &k) {
    scal.a = k * m.a;
    scal.b = k * m.b;
    scal.c = k * m.c;
    scal.d = k * m.d;
    
    outfile << "\n Scalar Multiplication of " << m.name << " (k = " << k << "): \n";
}

// function - multiplies matrix
void calc_prod(fstream &outfile, matrix &m1, matrix &m2, matrix &prod) {
    prod.a = (m1.a * m2.a) + (m1.b + m2.c);
    prod.b = (m1.a * m2.b) + (m1.b + m2.d);
    prod.c = (m1.c * m2.a) + (m1.d + m2.b);
    prod.d = (m1.c * m2.b) + (m1.d + m2.d);
    
    outfile << "\n Matrix Multiplication of " << m1.name << " and "  << m2.name << endl;
}

// function - inverse matrix
void calc_inverse(fstream &outfile, matrix &m1, matrix &m2, matrix &inv) {
    double detA;
    double detB;
    
    detA = (m1.a * m1.b) - (m1.c * m1.b);
    detB = (m2.a * m2.b) - (m2.c * m2.b);
    
    inv.a = m1.d / detA;
    inv.b = (-1 * m1.b) / detA;
    inv.c = (-1 * m1.c) / detA;
    inv.d = m1.a / detA;
    
    outfile << "\n Matrix Inverse of " << m1.name << endl;
}

// function - print matrix to outfile.txt start
void print_matrix(fstream &outfile, matrix &m) {
    outfile << "  -" << setw(7) << " "   << setw(7)   << " "   << "-\n"
            << " |"  << setw(7) << m.a   << setw(7)   << m.b   << "  |\n"
            << " |"  << setw(7) << " "   << setw(7)   << " "   << "  |\n"
            << " |"  << setw(7) << m.c   << setw(7)   << m.d   << "  |\n"
            << "  -" << setw(7) << " "   << setw(7)   << " "   << "-\n";
}

// function - close file start
void closeFile(fstream &outfile) {
     outfile.close();
}
