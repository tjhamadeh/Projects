/********************************************************
 *
 * Toufic Hamadeh
 * Long Integer ADT (Step 2)
 * Due Date: April 14, 2014
 *
 ********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/********************************************************
 *
 *   Function Prototypes
 *
 ********************************************************/
int digit(int);
int overFlow(int &);

/********************************************************
 *
 *   Structure to define the doubly linked list
 *
 ********************************************************/
struct node {
    int value;
    
    node *next;
    node *prev;
};

/********************************************************
 *
 *   Structure to define the list ADT
 *
 ********************************************************/
struct listAdt {
    node *head;
    node *tail;
    
    listAdt();
    void insert_Left(int);
    void insert_Right(int);
    node *next_Right(node *);
    node *next_Left(node *);
    node *get_First();
    node *get_Last();
    int element(node *);
    int get_Index();
    bool isFirst(node *);
    bool isLast(node *);
};

/********************************************************
 *
 *   Structure to define the long int ADT
 *
 ********************************************************/
struct longIntAdt {
    bool sign;
    listAdt tmp;
    
    listAdt initialize(string);
    longIntAdt add(longIntAdt);
    longIntAdt sub(longIntAdt);
    longIntAdt mul(longIntAdt);
    int getDigitCount();
    int getSign();
    bool equalTo(longIntAdt);
    bool lessThan(longIntAdt);
    bool greaterThan(longIntAdt);
    void setSign(char);
    void print();
};

/********************************************************
 *
 *   listAdt functions
 *
 ********************************************************/
//  Initializes the new list, sets head and tail to NULL
listAdt::listAdt() {
    head = tail = NULL;
}

//  Creates a new head node left if the list is brand new
//  Otherwise it adds the new node to the head of the list
//  and reassigns the head to the newly created node
void listAdt::insert_Left(int x) {
    if (head == NULL) {
        head = new node;
        tail = head;
        head->value = x;
        
        return;
    }
    else {
        head->prev = new node;
        head->prev->next = head;
        head = head->prev;
        head->prev = NULL;
        head->value = x;
    }
}

//  Creates a new tail node right if the list is brand new
//  Otherwise it adds the new node to the tail of the list
//  and reassigns the tail to the newly created node
void listAdt::insert_Right(int x) {
    if (tail == NULL) {
        tail = new node;
        head = tail;
        tail->value = x;
        
        return;
    }
    else {
        tail->next = new node;
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = NULL;
        tail->value = x;
    }
}

//  Returns the entire node to the left of the specified node n
node *listAdt::next_Left(node *n) {
    node *tmp;
    tmp = n;
    
    return tmp->prev;
}

//  Returns the entire node to the right of the specified node n
node *listAdt::next_Right(node *n) {
    node *tmp;
    tmp = n;
    
    return tmp->next;
}

//  Returns the entire head node of the list
node *listAdt::get_First() {
    return head;
}

//  Returns the entire tail node of the list
node *listAdt::get_Last() {
    return tail;
}

//  Returns the value stored in the given node
//  this function was not in the requirements but made
//  my life a lot easier with comparisons
int listAdt::element(node *x) {
    return x->value;
}

//  Compared the given node to see if it is equivalent
//  to the head node
//  Returns true or false
bool listAdt::isFirst(node *x) {
    if (x == head) {
        return true;
    }
    return false;
}

//  Compared the given node to see if it is equivalent
//  to the tail node
//  Returns true or false
bool listAdt::isLast(node *x) {
    if (x == tail) {
        return true;
    }
    return false;
}

/********************************************************
 *
 *   longIntAdt functions
 *
 ********************************************************/
//  This functions returns if the long int is positive or negative
//  1 == Negative
//  0 == Positive
int longIntAdt::getSign() {
    if (sign) {
        return 1;
    }
    else {
        return 0;
    }
}

//  This function checks for the '-' char and will set the sign
//  stored in the longIntAdt.
//  true == Negative
//  false == Positive
void longIntAdt::setSign(char c) {
    if (c == '-') {
        sign = true;
    }
    else {
        sign = false;
    }
}

//  Given input Q.greaterThan(R)
//  This function will check if Q > R
//  Order of comparisons are: sign, digit length,
//  compare each node until it reaches the least significant node
//  to see which long int given is larger.
bool longIntAdt::greaterThan(longIntAdt x) {
    listAdt cmp = x.tmp;
    
    if (sign == true && x.sign == false) {
        return false;
    }
    if (sign == false && x.sign == true) {
        return true;
    }
    if (getDigitCount() > x.getDigitCount()) {
        return true;
    }
    if (getDigitCount() < x.getDigitCount()) {
        return false;
    }
    if (tmp.element(tmp.get_First()) > cmp.element(cmp.get_First())) {
        return true;
    }
    node *q = tmp.get_First();
    node *w = cmp.get_First();
    
    if (!tmp.isLast(q) && !cmp.isLast(w)) {
        q = tmp.next_Right(q);
        w = cmp.next_Right(w);
    }
    while (!tmp.isLast(q) && !cmp.isLast(w)) {
        if (tmp.element(q) > cmp.element(w)) {
            return true;
        }
        q = tmp.next_Right(q);
        w = cmp.next_Right(w);
    }
    if (tmp.element(tmp.get_Last()) > cmp.element(cmp.get_Last())) {
        return true;
    }
    return false;
}

//  Given input Q.lessThan(R)
//  This function will check if Q < R
//  Order of comparisons are: sign, digit length,
//  compare each node until it reaches the least significant node
//  to see which long int given is smaller.
bool longIntAdt::lessThan(longIntAdt x) {
    listAdt cmp = x.tmp;
    
    if (sign == true && x.sign == false) {
        return true;
    }
    if (sign == false && x.sign == true) {
        return false;
    }
    if (getDigitCount() < x.getDigitCount()) {
        return true;
    }
    if (getDigitCount() > x.getDigitCount()) {
        return false;
    }
    if (tmp.element(tmp.get_First()) < cmp.element(cmp.get_First())) {
        return true;
    }
    node *q = tmp.get_First();
    node *w = cmp.get_First();
    
    if (!tmp.isLast(q) && !cmp.isLast(w)) {
        q = tmp.next_Right(q);
        w = cmp.next_Right(w);
    }
    while (!tmp.isLast(q) && !cmp.isLast(w)) {
        if (tmp.element(q) < cmp.element(w)) {
            return true;
        }
        q = tmp.next_Right(q);
        w = cmp.next_Right(w);
    }
    if (tmp.element(tmp.get_Last()) < cmp.element(cmp.get_Last())) {
        return true;
    }
    return false;
}


//  Given input Q.greaterThan(R)
//  This function will check if Q = R
//  It will run both greaterThan and lessThan function
//  If both return false than the longInt is equivalent
bool longIntAdt::equalTo(longIntAdt x) {
    if (!(greaterThan(x) || lessThan(x))) {
        return true;
    }
    return false;
}

//  This functio will parse a string into an integer
//  It will check the very first character for a negative
//  If a negative is found it will remove and store it in the long int adt
//  It will then modulo the string length and then parse the string accordingly
//  and store the values of max size 4 into the listAdt value (int) variable
listAdt longIntAdt::initialize(string s) {
    int cnt = 0;
    int num = 0;
    int x;
    int j;
    
    if (s[0] == '-') {
        setSign('-');
        s = s.substr(1);
    }
    else {
        setSign('+');
    }
    
    if(s.length() % 4 != 0) {
        x = 0;
        num = 0;
        for (int i = 4-(s.length() % 4); i < 4; i++) {
            x = (int)s[cnt] - 48;
            j = i;
            while(j < 3) {
                j++;
                x *= 10;
            }
            num = num + x;
            cnt++;
        }
        tmp.insert_Right(num);
    }
    while (s[cnt] != '\0') {
        x = 0;
        num = 0;
        for (int i = 0; i < 4; i++) {
            if (s[cnt] == '\0') {
                break;
            }
            x = (int)s[cnt] - 48;
            j = i;
            while(j < 3) {
                j++;
                x *= 10;
            }
            num = num + x;
            cnt++;
        }
        tmp.insert_Right(num);
    }
    return tmp;
}

//  This will simply return the length of an integer by comparing its size
//  and incrementing a counter.
int longIntAdt::getDigitCount() {
    int num = 0;
    node *last = tmp.get_Last();
    node *curr = tmp.get_First();
    
    if (tmp.element(curr) >= 0 && tmp.element(curr) < 10) {
        num = num + 1;
    }
    else if (tmp.element(curr) >= 10 && tmp.element(curr) < 100) {
        num = num + 2;
    }
    else if (tmp.element(curr) >= 100 && tmp.element(curr) < 1000) {
        num = num + 3;
    }
    else {
        num = num + 4;
    }
    if (curr != last) {
        curr = tmp.next_Right(curr);
        while (curr != last) {
            num = num + 4;
            curr = tmp.next_Right(curr);
        }
        num = num + 4;
    }
    
    return num;
}

//  This function will print the entire long int
//  It will first check for the sign and then step through the list
//  printing each value stored in every node until it reaches the end.
void longIntAdt::print() {
    node *last = tmp.get_Last();
    node *curr = tmp.get_First();
    
    if (getSign() == 1) {
        cout << "-";
    }
    while (curr != last) {
        if (curr == tmp.get_First()) {
            cout << curr->value;
        }
        else {
            cout << setfill('0') << setw(4) << curr->value;
        }
        curr = tmp.next_Right(curr);
    }
    
    if (curr != NULL) {
        if (curr->value == 0) {
            cout << curr->value;
        }
        else {
            cout << setfill('0') << setw(4) << curr->value;
        }
    }
    cout << endl;
}

//  This function will perform addition operations on two longIntAdt types
//  It will store the sum into a new longIntAdt type
//  it will then return the new longIntAdt back to main
longIntAdt longIntAdt::add(longIntAdt Q)
{
    int overflow = 0, sum = 0;
    longIntAdt final;
    listAdt bottom, top, fin;
    node *b, *t;
    
    if (getDigitCount() > Q.getDigitCount()) {
        bottom = Q.tmp;
        top = tmp;
        
        b = bottom.get_Last();
        t = top.get_Last();
    }
    else {
        bottom = tmp;
        top = Q.tmp;
        
        b = bottom.get_Last();
        t = top.get_Last();
    }
    
    if (getSign() == Q.getSign()) {
        if (getSign() == 0) {
            final.setSign('+');
        }
        else {
            final.setSign('-');
        }
        fin = final.tmp;
        while (b != NULL) {
            sum = b->value + t->value + overflow;
            overflow = overFlow(sum);
            fin.insert_Left(sum);
            
            b = bottom.next_Left(b);
            t = top.next_Left(t);
        }
        if (t != NULL) {
            while (t != NULL) {
                if (overflow != 0) {
                    sum = t->value + overflow;
                    fin.insert_Left(sum);
                    overflow = overFlow(sum);
                }
                else {
                    sum = t->value;
                    fin.insert_Left(sum);
                }
                t = top.next_Left(t);
            }
        }
    }
    else {
        if (getSign() == 1 && (getDigitCount() > Q.getDigitCount())) {
            final.setSign('-');
        }
        else {
            final.setSign('+');
        }
        fin = final.tmp;
        while (b != NULL) {
            sum = b->value + t->value + overflow;
            overflow = overFlow(sum);
            fin.insert_Left(sum);
            
            b = bottom.next_Left(b);
            t = top.next_Left(t);
        }
        if (t != NULL) {
            while (t != NULL) {
                if (overflow != 0) {
                    sum = t->value + overflow;
                    fin.insert_Left(sum);
                    overflow = overFlow(sum);
                }
                else {
                    sum = t->value;
                    fin.insert_Left(sum);
                }
                t = top.next_Left(t);
            }
        }
    }
    
    final.tmp = fin;
    return final;
}

//  This function will perform subtraction operations on two longIntAdt types
//  It will store the difference into a new longIntAdt type
//  it will then return the new longIntAdt back to main
longIntAdt longIntAdt::sub(longIntAdt Q) {
    int first_neg = 1, second_neg = 1;
    int first_digit = 0, second_digit = 0;
    longIntAdt final;
    listAdt second, fin;
    node *s, *f, *y, *x;
    
    f = tmp.get_Last();
    second = Q.tmp;
    s = second.get_Last();
    y = NULL;
    fin = final.tmp;
    
    first_digit = getDigitCount();
    second_digit = Q.getDigitCount();
    
    if (getSign() == 1) {
        first_neg = -1;
    }
    if (Q.getSign() == 1) {
        second_neg = -1;
    }
    
    if (second_digit > first_digit && second_neg == -1) {
        final.setSign('+');
    }
    else if (second_digit > first_digit && second_neg == 1) {
        final.setSign('-');
    }
    else if (second_digit < first_digit && first_neg == -1) {
        final.setSign('-');
    }
    else if (second_digit < first_digit && first_neg == 1) {
        final.setSign('+');
    }
    else if (second_digit == first_digit && second_neg == 1) {
        final.setSign('+');
    }
    else {
        final.setSign('+');
    }
    
    if (equalTo(Q)) {
        fin.insert_Left(0);
    }
    else if (greaterThan(Q)) {
        while (s != NULL) {
            if (f->value == s->value) {
                f = tmp.next_Left(f);
                if (second.next_Left(s) != NULL) {
                    s = second.next_Left(s);
                }
            }
            else if ((f->value - s->value) < 0) {
                if (tmp.next_Left(f) != NULL) {
                    x = tmp.next_Left(f);
                    x->value = x->value - 1;
                    f->value = f->value + 10000;
                }
                fin.insert_Left(f->value - s->value);
            }
            else {
                fin.insert_Left(f->value - s->value);
            }
            y = fin.get_First();
            
            f = tmp.next_Left(f);
            s = second.next_Left(s);
        }
        if (f != NULL) {
            while (f != NULL) {
                fin.insert_Left(f->value);
                f = tmp.next_Left(f);
            }
            final.setSign('+');
        }
    }
    else {
        while (f != NULL) {
            if (f->value == s->value) {
                f = tmp.next_Left(f);
                if (second.next_Left(s) != NULL) {
                    s = second.next_Left(s);
                }
            }
            else if ((f->value - s->value) < 0) {
                fin.insert_Left((f->value - s->value) * -1);
            }
            else {
                fin.insert_Left(f->value - s->value);
            }
            y = fin.get_First();
            
            f = tmp.next_Left(f);
            s = second.next_Left(s);
        }
        if (s != NULL) {
            while (s != NULL) {
                fin.insert_Left(s->value);
                s = second.next_Left(s);
            }
            final.setSign('-');
        }
    }
    
    final.tmp = fin;
    return final;
}

//  This function will perform multiplication operations on two longIntAdt types
//  It will store the product into a new longIntAdt type
//  it will then return the new longIntAdt back to main
longIntAdt longIntAdt::mul(longIntAdt Q) {
    int count = 0;
    int overflow = 0, product = 0;
    longIntAdt result, final;
    listAdt bottom, top, res, fin;
    node *b, *t, *r;
    final.initialize("0");
    if (getDigitCount() > Q.getDigitCount()) {
        bottom = Q.tmp;
        top = tmp;
        
        b = bottom.get_Last();
        t = top.get_Last();
    }
    else {
        bottom = tmp;
        top = Q.tmp;
        
        b = bottom.get_Last();
        t = top.get_Last();
    }
    res = result.tmp;
    r = NULL;
    
    if (getSign() == Q.getSign()) {
        final.setSign('+');
        result.setSign('+');
    }
    else {
        final.setSign('-');
        result.setSign('-');
    }
    while (b != NULL) {
        overflow = 0;
        t = top.get_Last();
        while (t != NULL) {
            product = (b->value * t->value) + overflow;
            overflow = overFlow(product);
            res.insert_Left(product);
            t = top.next_Left(t);
        }
        if (overflow != 0) {
            res.insert_Left(overflow);
        }
        
        for (int i = 0; i < count; i++) {
            res.insert_Right(0);
        }
        count++;
        result.tmp = res;
        final = final.add(result);
        
        result.tmp.~listAdt();
        new (&result.tmp) listAdt();
        res = result.tmp;
        
        b = bottom.next_Left(b);
    }

    return final;
}

/********************************************************
 *
 *   main, digit, overFlow
 *
 ********************************************************/
int main () {
    int intB = 12349999;
    string A = "2222";                                                                                      // A  = 4 digits
    string B = "99999999";                                                                                  // B  = 8 digits
    string C = "246813575732";                                                                              // C  = 12 digits
    string D = "180270361023456789";                                                                        // D  = 18 digits
    string AX = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";   // AX = 86 digits
    string AZ = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";           // AZ = 77 digits
    longIntAdt adtA, adtB, adtC, adtD, adtAX, adtAZ;
    longIntAdt adtE, adtF, adtG, adtH, adtI, adtJ;
    longIntAdt adtK, adtL, adtM, adtN, adtO, adtP;
    longIntAdt adtQ, adtR, adtS, adtT, adtU, adtV;
    
    // Step 1 Test Cases
    cout << "initialize(A)" << endl;
    adtA.initialize(A);
    cout << "Function Print(): ";
    adtA.print();
    cout << "Original String : " << A << endl;
    cout << "getDigitCount() : " << adtA.getDigitCount() << endl << endl;
    
    cout << "initialize(B)" << endl;
    adtB.initialize(B);
    cout << "Function Print(): ";
    adtB.print();
    cout << "Original String : " << B << endl;
    cout << "getDigitCount() : " << adtB.getDigitCount() << endl << endl;
    
    cout << "initialize(C)" << endl;
    adtC.initialize(C);
    cout << "Function Print(): ";
    adtC.print();
    cout << "Original String : " << C << endl;
    cout << "getDigitCount() : " << adtC.getDigitCount() << endl << endl;
    
    cout << "initialize(D)" << endl;
    adtD.initialize(D);
    cout << "Function Print(): ";
    adtD.print();
    cout << "Original String : " << D << endl;
    cout << "getDigitCount() : " << adtD.getDigitCount() << endl << endl;
    
    cout << "initialize(AX)" << endl;
    adtAX.initialize(AX);
    cout << "Function Print(): ";
    adtAX.print();
    cout << "Original String : " << AX << endl;
    cout << "getDigitCount() : " << adtAX.getDigitCount() << endl << endl;
    
    cout << "initialize(AZ)" << endl;
    adtAZ.initialize(AZ);
    cout << "Function Print(): ";
    adtAZ.print();
    cout << "Original String : " << AZ << endl;
    cout << "getDigitCount() : " << adtAZ.getDigitCount() << endl << endl;
    
    cout << "intB: " << intB << endl;
    cout << "overFlow(intB) " << endl;
    cout << overFlow(intB) << " <- Overflow\tintB -> ";
    cout << intB << endl;
    
    cout << endl << "A.lessThan(x)" << endl;
    cout << "A < A?  " << adtA.lessThan(adtA) << endl;
    cout << "A < B?  " << adtA.lessThan(adtB) << endl;
    cout << "A < C?  " << adtA.lessThan(adtC) << endl;
    cout << "A < D?  " << adtA.lessThan(adtD) << endl;
    cout << "A < AX? " << adtA.lessThan(adtAX) << endl;
    cout << "A < AZ? " << adtA.lessThan(adtAZ) << endl;
    cout << endl << "A.greaterThan(x)" << endl;
    cout << "A > A?  " << adtA.greaterThan(adtA) << endl;
    cout << "A > B?  " << adtA.greaterThan(adtB) << endl;
    cout << "A > C?  " << adtA.greaterThan(adtC) << endl;
    cout << "A > D?  " << adtA.greaterThan(adtD) << endl;
    cout << "A > AX? " << adtA.greaterThan(adtAX) << endl;
    cout << "A > AZ? " << adtA.greaterThan(adtAZ) << endl;
    cout << endl << "A.equalTo(x)" << endl;
    cout << "A = A?  " << adtA.equalTo(adtA) << endl;
    cout << "A = B?  " << adtA.equalTo(adtB) << endl;
    cout << "A = C?  " << adtA.equalTo(adtC) << endl;
    cout << "A = D?  " << adtA.equalTo(adtD) << endl;
    cout << "A = AX? " << adtA.equalTo(adtAX) << endl;
    cout << "A = AZ? " << adtA.equalTo(adtAZ) << endl << endl;
    
    cout << endl << "B.lessThan(x)" << endl;
    cout << "B < A?  " << adtB.lessThan(adtA) << endl;
    cout << "B < B?  " << adtB.lessThan(adtB) << endl;
    cout << "B < C?  " << adtB.lessThan(adtC) << endl;
    cout << "B < D?  " << adtB.lessThan(adtD) << endl;
    cout << "B < AX? " << adtB.lessThan(adtAX) << endl;
    cout << "B < AZ? " << adtB.lessThan(adtAZ) << endl;
    cout << endl << "B.greaterThan(x)" << endl;
    cout << "B > A?  " << adtB.greaterThan(adtA) << endl;
    cout << "B > B?  " << adtB.greaterThan(adtB) << endl;
    cout << "B > C?  " << adtB.greaterThan(adtC) << endl;
    cout << "B > D?  " << adtB.greaterThan(adtD) << endl;
    cout << "B > AX? " << adtB.greaterThan(adtAX) << endl;
    cout << "B > AZ? " << adtB.greaterThan(adtAZ) << endl;
    cout << endl << "B.equalTo(x)" << endl;
    cout << "B = A?  " << adtB.equalTo(adtA) << endl;
    cout << "B = B?  " << adtB.equalTo(adtB) << endl;
    cout << "B = C?  " << adtB.equalTo(adtC) << endl;
    cout << "B = D?  " << adtB.equalTo(adtD) << endl;
    cout << "B = AX? " << adtB.equalTo(adtAX) << endl;
    cout << "B = AZ? " << adtB.equalTo(adtAZ) << endl << endl;
    
    cout << endl << "C.lessThan(x)" << endl;
    cout << "C < A?  " << adtC.lessThan(adtA) << endl;
    cout << "C < B?  " << adtC.lessThan(adtB) << endl;
    cout << "C < C?  " << adtC.lessThan(adtC) << endl;
    cout << "C < D?  " << adtC.lessThan(adtD) << endl;
    cout << "C < AX? " << adtC.lessThan(adtAX) << endl;
    cout << "C < AZ? " << adtC.lessThan(adtAZ) << endl;
    cout << endl << "C.greaterThan(x)" << endl;
    cout << "C > A?  " << adtC.greaterThan(adtA) << endl;
    cout << "C > B?  " << adtC.greaterThan(adtB) << endl;
    cout << "C > C?  " << adtC.greaterThan(adtC) << endl;
    cout << "C > D?  " << adtC.greaterThan(adtD) << endl;
    cout << "C > AX? " << adtC.greaterThan(adtAX) << endl;
    cout << "C > AZ? " << adtC.greaterThan(adtAZ) << endl;
    cout << endl << "C.equalTo(x)" << endl;
    cout << "C = A?  " << adtC.equalTo(adtA) << endl;
    cout << "C = B?  " << adtC.equalTo(adtB) << endl;
    cout << "C = C?  " << adtC.equalTo(adtC) << endl;
    cout << "C = D?  " << adtC.equalTo(adtD) << endl;
    cout << "C = AX? " << adtC.equalTo(adtAX) << endl;
    cout << "C = AZ? " << adtC.equalTo(adtAZ) << endl << endl;
    
    cout << endl << "D.lessThan(x)" << endl;
    cout << "D < A?  " << adtD.lessThan(adtA) << endl;
    cout << "D < B?  " << adtD.lessThan(adtB) << endl;
    cout << "D < C?  " << adtD.lessThan(adtC) << endl;
    cout << "D < D?  " << adtD.lessThan(adtD) << endl;
    cout << "D < AX? " << adtD.lessThan(adtAX) << endl;
    cout << "D < AZ? " << adtD.lessThan(adtAZ) << endl;
    cout << endl << "D.greaterThan(x)" << endl;
    cout << "D > A?  " << adtD.greaterThan(adtA) << endl;
    cout << "D > B?  " << adtD.greaterThan(adtB) << endl;
    cout << "D > C?  " << adtD.greaterThan(adtC) << endl;
    cout << "D > D?  " << adtD.greaterThan(adtD) << endl;
    cout << "D > AX? " << adtD.greaterThan(adtAX) << endl;
    cout << "D > AZ? " << adtD.greaterThan(adtAZ) << endl;
    cout << endl << "D.equalTo(x)" << endl;
    cout << "D = A?  " << adtD.equalTo(adtA) << endl;
    cout << "D = B?  " << adtD.equalTo(adtB) << endl;
    cout << "D = C?  " << adtD.equalTo(adtC) << endl;
    cout << "D = D?  " << adtD.equalTo(adtD) << endl;
    cout << "D = AX? " << adtD.equalTo(adtAX) << endl;
    cout << "D = AZ? " << adtD.equalTo(adtAZ) << endl << endl;
    
    cout << endl << "AX.lessThan(x)" << endl;
    cout << "AX < A?  " << adtAX.lessThan(adtA) << endl;
    cout << "AX < B?  " << adtAX.lessThan(adtB) << endl;
    cout << "AX < C?  " << adtAX.lessThan(adtC) << endl;
    cout << "AX < D?  " << adtAX.lessThan(adtD) << endl;
    cout << "AX < AX? " << adtAX.lessThan(adtAX) << endl;
    cout << "AX < AZ? " << adtAX.lessThan(adtAZ) << endl;
    cout << endl << "AX.greaterThan(x)" << endl;
    cout << "AX > A?  " << adtAX.greaterThan(adtA) << endl;
    cout << "AX > B?  " << adtAX.greaterThan(adtB) << endl;
    cout << "AX > C?  " << adtAX.greaterThan(adtC) << endl;
    cout << "AX > D?  " << adtAX.greaterThan(adtD) << endl;
    cout << "AX > AX? " << adtAX.greaterThan(adtAX) << endl;
    cout << "AX > AZ? " << adtAX.greaterThan(adtAZ) << endl;
    cout << endl << "AX.equalTo(x)" << endl;
    cout << "AX = A?  " << adtAX.equalTo(adtA) << endl;
    cout << "AX = B?  " << adtAX.equalTo(adtB) << endl;
    cout << "AX = C?  " << adtAX.equalTo(adtC) << endl;
    cout << "AX = D?  " << adtAX.equalTo(adtD) << endl;
    cout << "AX = AX? " << adtAX.equalTo(adtAX) << endl;
    cout << "AX = AZ? " << adtAX.equalTo(adtAZ) << endl << endl;
    
    cout << endl << "AZ.lessThan(x)" << endl;
    cout << "AZ < A?  " << adtAZ.lessThan(adtA) << endl;
    cout << "AZ < B?  " << adtAZ.lessThan(adtB) << endl;
    cout << "AZ < C?  " << adtAZ.lessThan(adtC) << endl;
    cout << "AZ < D?  " << adtAZ.lessThan(adtD) << endl;
    cout << "AZ < AX? " << adtAZ.lessThan(adtAX) << endl;
    cout << "AZ < AZ? " << adtAZ.lessThan(adtAZ) << endl;
    cout << endl << "AZ.greaterThan(x)" << endl;
    cout << "AZ > A?  " << adtAZ.greaterThan(adtA) << endl;
    cout << "AZ > B?  " << adtAZ.greaterThan(adtB) << endl;
    cout << "AZ > C?  " << adtAZ.greaterThan(adtC) << endl;
    cout << "AZ > D?  " << adtAZ.greaterThan(adtD) << endl;
    cout << "AZ > AX? " << adtAZ.greaterThan(adtAX) << endl;
    cout << "AZ > AZ? " << adtAZ.greaterThan(adtAZ) << endl;
    cout << endl << "AZ.equalTo(x)" << endl;
    cout << "AZ = A?  " << adtAZ.equalTo(adtA) << endl;
    cout << "AZ = B?  " << adtAZ.equalTo(adtB) << endl;
    cout << "AZ = C?  " << adtAZ.equalTo(adtC) << endl;
    cout << "AZ = D?  " << adtAZ.equalTo(adtD) << endl;
    cout << "AZ = AX? " << adtAZ.equalTo(adtAX) << endl;
    cout << "AZ = AZ? " << adtAZ.equalTo(adtAZ) << endl << endl;
    
    // Step 2 Test Cases
    adtE = adtA.add(adtD);
    adtF = adtB.add(adtC);
    adtG = adtC.add(adtD);
    adtH = adtE.add(adtE);
    adtI = adtA.add(adtE);
    adtJ = adtB.add(adtG);
    cout << "Addition" << endl;
    cout << "E = A + D: "; adtE.print();
    cout << "F = B + C: "; adtF.print();
    cout << "G = C + D: "; adtG.print();
    cout << "H = E + E: "; adtH.print();
    cout << "I = A + E: "; adtI.print();
    cout << "J = B + G: "; adtJ.print();
    
    adtK = adtA.sub(adtD);
    adtL = adtC.sub(adtD);
    adtM = adtD.sub(adtC);
    adtN = adtH.sub(adtH);
    adtO = adtL.sub(adtK);
    adtP = adtJ.sub(adtM);
    cout << "\nSubtraction" << endl;
    cout << "K = A - D: "; adtK.print();
    cout << "L = C - D: "; adtL.print();
    cout << "M = D - C: "; adtM.print();
    cout << "N = H - H: "; adtN.print();
    cout << "O = L - K: "; adtO.print();
    cout << "P = J - M: "; adtP.print();
    
    adtQ = adtA.mul(adtD);
    adtR = adtB.mul(adtC);
    adtS = adtD.mul(adtD);
    adtT = adtK.mul(adtE);
    adtU = adtF.mul(adtL);
    adtV = adtI.mul(adtJ);
    cout << "\nMultiplication" << endl;
    cout << "Q = A * D: "; adtQ.print();
    cout << "R = B * C: "; adtR.print();
    cout << "S = D * D: "; adtS.print();
    cout << "T = K * E: "; adtT.print();
    cout << "U = F * L: "; adtU.print();
    cout << "V = I * J: "; adtV.print();
    
    return 0;
}

//  This function returns the total number of digits in a specified int
//  If the num returned is > 4 then there is an overflow.
int digit(int x) {
    int num = 0;
    
    if (x < 10) {
        num = num+1;
    }
    else if (x < 100) {
        num = num+2;
    }
    else if (x < 1000) {
        num = num+3;
    }
    else if (x < 10000) {
        num = num+4;
    }
    else if (x < 100000) {
        num = num+5;
    }
    else if (x < 1000000) {
        num = num+6;
    }
    else if (x < 10000000) {
        num = num+7;
    }
    else {
        num = num+8;
    }
    return num;
}

//  This function will pass an integer by reference and then call
//  digit() to see if the number of integers is greater than 4.
//  If it is greater, it will return the overflow, and modify
//  t to the proper size.
int overFlow(int &t) {
    int x = 0;

    if (digit(t) > 4) {
        x = t / 10000;
        t = t % 10000;
        return x;
    }
    return 0;
}