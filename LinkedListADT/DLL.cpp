#include <iostream>

using namespace std;

/*******************************************************************************
* Toufic Hamadeh
* Programming Assignment - Linked-Lists
* Due Date: April 10, 2012
* Class: CIS-277-601
* 
* Assignment: Linked-Lists
*******************************************************************************/

struct node;
typedef node * Ptr;

struct node {
    char name[20];
    int age;
    float height;
    node * nxt;
};

Ptr start_ptr = NULL;

void add_start();
void add_end();
void add_middle();
void display();
void delete_start();
void delete_end();
void delete_mid();
void step_thru();

int main() {
    int choice;
    do {
        cout << "1) Add\n"
             << "2) Add to start\n"
             << "3) Add middle\n"
             << "4) Display\n"
             << "5) Delete from start\n"
             << "6) Delete from end\n"
             << "7) Delete from middle\n"
             << "8) Exit\n"
             << ">> ";
        cin  >> choice;
        
        switch (choice) {
            case 1:
                add_end();
            break;
            case 2:
                add_start();
            break;
            case 3:
                add_middle();
            break;
            case 4:
                display();
            break;
            case 5:
                delete_start();
            break;
            case 6:
                delete_end();
            break;
            case 7:
                delete_mid();
            break;
            case 8:
                return 0;
            break;
            default:
                cout << "Invalid Choice!\n";
            break;
        }
    } while (choice != 8);
    
    system("pause");
}

void add_start() {
    node * temp, * current;
    current = start_ptr;
    
    while (start_ptr -> nxt != NULL) { 
        current = start_ptr -> nxt;
    }
    temp = new node;
    temp = start_ptr;
        
    cout << "Please enter the name of the person: ";
    cin  >> current -> name;
    cout << "Please enter the age of the person: ";
    cin  >> current -> age;
    cout << "Please enter the height of the person: ";
    cin  >> current -> height;
}

void add_end() {
    node * temp, * temp2;
    temp = new node;
    
    cout << "Please enter the name of the person: ";
    cin  >> temp -> name;
    cout << "Please enter the age of the person: ";
    cin  >> temp -> age;
    cout << "Please enter the height of the person: ";
    cin  >> temp -> height;
    temp -> nxt = NULL;

    if (start_ptr == NULL)
        start_ptr = temp;
    else {
        temp2 = start_ptr;
        while (temp2 -> nxt != NULL)
            temp2 = temp2 -> nxt;
        temp2 -> nxt = temp;
    }
}

void add_middle() {
    node * current, * temp;
    current = start_ptr;
    
    if (current -> nxt == NULL)
        add_end();
    else {
        temp = new node;
        
        cout << "Please enter the name of the person: ";
        cin  >> temp -> name;
        cout << "Please enter the age of the person: ";
        cin  >> temp -> age;
        cout << "Please enter the height of the person: ";
        cin  >> temp -> height;
        
        temp -> nxt = current -> nxt;
        current -> nxt = temp;
    }
}

void display() {
    node * temp, * temp2;
    temp = start_ptr;
    
    do {
        if (temp == NULL)
            cout << "End of list\n";
        else {
            cout << "Name: " << temp -> name << endl;
            cout << "Age: "  << temp -> age  << endl;
            cout << "Height: " << temp -> height << endl;
            temp = temp -> nxt;
        }
    } while (temp != NULL);
}

void delete_start() {
    node * temp;
    temp = start_ptr;
    start_ptr = start_ptr -> nxt;
    delete temp;
}

void delete_end() {
    node * temp1, * temp2;
    if (start_ptr == NULL)
        cout << "The list is empty!\n";
    else {
        temp1 = start_ptr;
        if (temp1 -> nxt == NULL) {
            delete temp1;
            start_ptr = NULL;
        } else {
            while (temp1 -> nxt != NULL) {
                temp2 = temp1;
                temp1 = temp1 -> nxt;
            }
        }
        delete temp1;
        temp2 -> nxt = NULL;
    }
}

void delete_mid() {
    node * current, * temp;
    current = start_ptr;
    
    if (current -> nxt == NULL) {
        cout << "There is no node after current" << endl;
    }
    else {
        temp = current -> nxt;
        current -> nxt = temp -> nxt;
        delete temp;
    }
}
