#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*******************************************************************************
* Toufic Hamadeh
* Group Assignment #1 - Vectors
* Due Date: February 16, 2012
* Class: CIS-277-601
* 
* Assignment: Create a program where the user enters a vector and then is given 
*             a list of different operations he/she can choose to select. When the 
*             operation is carried out the data is printed directly to an output file.
*******************************************************************************/

struct vector // vector structure
{
       double x;
       double y;
};

void getVector(string &, vector &); // function prototype - asks user to input two vectors

bool openFile(fstream &); // function prototype - opens outfile.txt

void closeFile(fstream &); // function prototype - closes outfile.txt

void printVector(fstream &, string, vector); // function prototype - prints both vector struct to outfile.txt

void printVector(fstream &, string, double);

void addVectors(vector, vector, vector &); // function prototype - vector addition

void subVectors(vector, vector, vector &); // function prototype - vector subtraction

void scalarMultiply(vector, double, vector &); // function prototype - vector multiplication

double dotProduct(vector, vector); // function prototype - vector dot product

double magnitude(vector); // function prototype - magnitude of vector

int main(int argc, char *argv[]) // start main
{
    // declare variables
    fstream outfile;
    
    vector vec1;
    vector vec2;
    vector sum;
    vector diff;
    vector scalarMulti;    
    
    string name1;
    string name2;
    
    int choice;
    
    if(!openFile(outfile)) // if - check if openfile failed else continue
    {
         cout << "could not open file!!\n";     
    }    
    else
    {   
        getVector(name1, vec1);
        getVector(name2, vec2);
        printVector(outfile, name1, vec1);
        printVector(outfile, name2, vec2);
        do // do while for switch menu
        { 
            cout << "Make your choice!!\n"
                 << "1) Add Vectors\n"
                 << "2) Subtract Vectors\n"
                 << "3) Scalar Multiplication\n"
                 << "4) Dot Product\n"
                 << "5) Magnitude\n"
                 << "6) Quit\n"
                 << ">>";
            cin >> choice;
        
            switch (choice) // switch start - select function prototype(s) - options 1-6
            {                
                case 1: // adds vectors and prints to outfile
                   addVectors(vec1, vec2, sum);
                   printVector(outfile, "Sum", sum);
                break;
                
                case 2: // subtract vectors and print to outfile
                   subVectors(vec1, vec2, diff);
                   printVector(outfile, "Difference", diff);
                break;
                
                case 3: // multiply vectors and print to outfile
                   scalarMultiply(vec1, 10, scalarMulti);
                   printVector(outfile, "Scalar Multiple", scalarMulti);
                break;
                
                case 4: // dot product on vectors and print to outfile
                   printVector(outfile, "Dot Product", dotProduct(vec1, vec2));
                break;
                
                case 5: // magnitude of vectors and print to outfile
                   printVector(outfile, "Magnitude", magnitude(vec1));
                break;
                
                case 6: // exit switch
                   cout << "thank you, bye\n";
                break;
                
                default: // default option
                   cout << "Invalid selection!!\n";
                break;
            } // close switch
        } while (choice != 6); // close do-while
        closeFile(outfile);
    }// close if/else            
        
    system("PAUSE");
    return EXIT_SUCCESS;
} // main end

// function - input vector start
void getVector(string &name, vector &v)
{
     cout << "Name: ";
     cin >> name;
     cout << "Vector\nx: ";
     cin >> v.x;
     cout << "y: ";
     cin >> v.y;
}

// function - open file for output start
bool openFile(fstream &o) 
{
     o.open("output.txt", ios::out);
     if(o.fail())
         return false;
     return true;
}

// function - close file start
void closeFile(fstream &outfile) 
{
     outfile.close();
}

// function - print vectors outfile.txt start
void printVector(fstream &outfile, string name, vector v)
{
     outfile << name << " = <" << v.x << ", " << v.y << ">\n";
}

void printVector(fstream &outfile, string name, double d)
{
     outfile << name << " = " << d << endl;
}

// function - vector addition start
void addVectors(vector v1, vector v2, vector &sum) 
{
     sum.x = v1.x + v2.x;
     sum.y = v1.y + v2.y;
}

// function - vector subtraction start
void subVectors(vector v1, vector v2, vector &diff)
{
     diff.x = v1.x - v2.x;
     diff.y = v1.y - v2.y;
}

// function - vector multiplication start
void scalarMultiply(vector v, double multiplier, vector &scal)
{
     scal.x = v.x * multiplier;
     scal.y = v.y * multiplier;
}

// function - vector dot product start
double dotProduct(vector v1, vector v2)
{
       double prod = (v1.x * v2.x) + (v1.y * v2.y);
       return prod;
}

// function - magnitude of vector start
double magnitude(vector v)
{
       double mag = sqrt((v.x * v.x) + (v.y * v.y));
       return mag;
}
