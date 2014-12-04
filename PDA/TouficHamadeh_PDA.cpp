// Toufic Hamadeh
// CS341-451
// Professor Nakayama
// Programming Assignment 1
// Due: October 1, 2013

#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;

// function prototypes
void q1(void);
void q2(void);
void q3(void);

// global variables
char s[SIZE];
bool dfa;
int i;

// q3 of DFA for language L.
// q3 checks to see if s3 consists of {.org}
//
void q3(void) {
    cout << "Checking for q3...\n";
    // If there are two '.' in a row it will set dfa to false and return.
    if (s[i] == '.' && s[i-1] == '.' || s[i] == '.' && s[i+1] == '.') {
        cout << "q3 test fail.\n";
        dfa = false;
        return;
    }
    // If block to check if s3 = {.org}. If incorrect sets dfa = false.
    if (s[i] == 'o') {
        i++;
        if (s[i] == 'r'){
            i++;
            if (s[i] == 'g') {
                i++;
                dfa = true;
                // If statement to make sure nothing follows {.org}
                if (s[i] == '.' || s[i] >= 'a' && s[i] <= 'z') {
                    cout << "q3 test fail.\n";
                    dfa = false;
                    return;
                }
                return;
                }
            }
        }
return;
}

// q2 of DFA for language L.
// q2 checks to see if s2 consists of letters only.
// If there are two '.' in a row it will set dfa to false and return.
void q2(void) {
    cout << "Checking for q2...\n";
    if (s[i] == '.' && s[i-1] == '.' || s[i] == '.' && s[i+1] == '.') {
        cout << "q2 test fail.\n";
        dfa = false;
        return;
    }
    // While loop to increment through the letters
    while (s[i] >= 'a' && s[i] <= 'z') {
        i++;
    }
    // If statement used to push string to q3 for final check
    if (s[i] == '.') {
        i++;
        q3();
    }
return;
}


// q1 of DFA for language L.
// q1 checks to see if s1 = {www.}
// or
// if we should go straight to q2
void q1(void) {
    cout << "Checking for q1...\n";
    // Constant to track w's in string,
    // s1 cannot have more than 3 w's. [ s1 = {www.} ]
    // While loop counts, if more than 3 w's followed by a period.
    // DFA is returned false.
    int c = 0;
    while (s[i] == 'w') {
        c++;
        i++;
    }
    if (c > 3 && s[i] == '.') {
        cout << "q1 test fail.\n";
        dfa = false;
        return;
    }
    else {
        i=0;
    }

    // If block to check that s1 is {www.}. If true, go to q2,
    // anything else is rejected or pushed to next if statement.
    // Global increment is reset to 0 if rejected.
    if (s[i] == 'w') {
        i++;
        if (s[i] == 'w') {
            i++;
            if (s[i] == 'w') {
                i++;
                if (s[i] == '.') {
                    i++;
                    q2();
                }
                else {
                    i=0;
                }
            }
            else {
                i=0;
            }
        }
        else {
            i=0;
        }
    }

    // If statement to make sure that we have letters
    // only before moving to q2
    if (s[i] >= 'a' && s[i] <= 'z') {
        q2();
    }
return;
}

// Begin main function.
// String is input and then sent through the DFA for processing.
int main () {
    char z;

    cout << "Do you want to test a string in language L? [Y/n] ";
    cin >> z;
    // While loop repeats itself until user inputs 'n' for no.
    while (z != 'n') {
        // If statement to break loop if a 'y' or 'n' is not entered.
        if (z != 'n' && z != 'y') {
            cout << "Invalid entry.";
            break;
        }
        // If statement to collect string if 'y' is entered.
        if ( z == 'y') {
            cout << "Enter String: ";

            // Asks user for string input.
            cin >> s;

            // Sets global increment to 0.
            i=0;
            // Calls function q1 after string is input.
            q1();

            // Determines whether or not the string is in the language.
            if (dfa == true) {
                cout << "The string \"" << s << "\" is in the language L.\n\n";
            } else {
                cout << "The string \"" << s << "\" is NOT in the language L.\n\n";
            }
        }
        // User asked to test another string.
        cout << "Do you want to test another string in language L? [Y/n] ";
        cin >> z;
    }
return 0;
}
