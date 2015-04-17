/*
 *  Toufic Hamadeh
 *  UCID 31234305
 *  C++ version
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool A(void);
bool E(void);
bool T(void);
bool F(void);
bool P(void);
bool U(void);
bool I(void);
bool C(void);
bool L(void);
bool D(void);

string s;
string z;

int main(int argc, char *argv[]) {
    ifstream in;

    in.open("input.txt" );

    if(in.good())
    {
        while (!in.eof()) {

        getline (in,s);
        z = s;

        if (A() && s == "") {
            cout << "The string \"" << z << "\" is in the language" << endl;
        }
        else {
            cout << "The string \"" << z << "\" is not in the language" << endl;
        }
    }
    in.close();
    }
    else {
        cout << "File not found." << endl;
    }

    return 0;
}

bool A(void) {
    if (I()) {
        if (s[0] == '=') {
            s = s.substr(1);
            if (E()) {
                return true;
            }
        }
    }
    else if (E()) {
        return true;
    }
    else {
        return false;
    }
}

bool E(void) {
    if (T()) {
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
            if (E()) {
                return true;
            }
        }
        return true;
    }
    return false;
}

bool T(void) {
    if (F()) {
        if (s[0] == '/' || s[0] == '*') {
            s = s.substr(1);
            if (T()) {
                return true;
            }
        }
        return true;
    }
    return false;
}

bool F(void) {
    if (P()) {
        if (s[0] == '^') {
            s = s.substr(1);
            if (F()) {
                return true;
            }
        }
        return true;
    }
    return false;
}

bool P(void) {
    if (I()) {
        return true;
    }
    if (L()) {
        return true;
    }
    if (U()) {
        if(I() || L()) {
            return true;
        }
    }
    if (s[0] == '(') {
        s = s.substr(1);
        if (A()) {
            if (s[0] == ')') {
                s = s.substr(1);
                return true;
            }
        }
    }
    return false;
}

bool U(void) {
    if (s[0]=='+'  || s[0] == '-' || s[0] == '!' ) {
        s = s.substr(1);
        return true;
    }
    return false;
}

bool I(void) {
    if (C()) {
        if (I()) {
            return true;
        }
    return true;
    }
    return false;
}

bool C(void) {
    if ('a' <= s[0] && s[0] <= 'z') {
        s = s.substr(1);
        return true;
    }
    return false;
}

bool L(void) {
    if (D()) {
        if (L()) {
            return true;
        }
        return true;
    }
    return false;
}

bool D(void) {
    if ('0' <= s[0] && s[0] <= '9') {
        s = s.substr(1);
        return true;
    }
    return false;
}

