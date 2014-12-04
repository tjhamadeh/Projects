#include <iostream>
#include <fstream>
#define SIZE 100

using namespace std;

/*****************************************************************************
* Toufic Hamadeh, , , , 
* This program demonstrates how queue operations work.
* Due Date: March 08, 2012
*****************************************************************************/

typedef int info_rc;

struct queue {
    info_rc i[SIZE];
    int     back;
};

void create_queue(queue &);
bool empty(queue &);
void enque(queue &, info_rc &);
void deque(queue &, info_rc &);
void purge(queue &);
void form_queue(queue &);

bool openfile(fstream &);
void print_queue(fstream &, string, queue &);

int main () {
    fstream outfile;
    
    queue data;
    queue q_1_9;
    queue q_10_19;
    queue q_20_29;
    queue q_30_plus;
    info_rc item;
    
    if (!openfile(outfile))
        cout << "Couldn't open file";
    else {
        form_queue(data);
        create_queue(q_1_9);
        create_queue(q_10_19);
        create_queue(q_20_29);
        create_queue(q_30_plus);
    
        while(!empty(data)) {
            deque(data, item);
            if (item < 10)
                enque(q_1_9, item);
            if (item >= 10 && item < 20)
                enque(q_10_19, item);
            if (item >= 20 && item < 30)
                enque(q_20_29, item);
            if (item >= 30)
                enque(q_30_plus, item);
        }
    }
    
    /*
    print_queue(outfile, q_1_9);
    print_queue(outfile, q_10_19);
    print_queue(outfile, q_20_29);
    print_queue(outfile, q_30_plus);
    */
    
    print_queue(outfile, "1 through 9:\n", q_1_9);
    print_queue(outfile, "\n\n10 through 19:\n", q_10_19);
    print_queue(outfile, "\n\n20 through 29:\n", q_20_29);
    print_queue(outfile, "\n\n30 plus:\n", q_30_plus);
    
    system("pause");
    return 0;
}

void create_queue(queue &q) {
    q.back = -1;
}

bool empty (queue &q) {
    return (q.back == -1);
}

void enque(queue &q, info_rc &item) {
    ++q.back;
    q.i[q.back] = item;
}

void deque(queue &q, info_rc &item) {
    int ct;
    
    item = q.i[0];
    for(ct = 1; ct <= q.back; ++ct)
        q.i[ct-1] = q.i[ct];
    --q.back;
}

void form_queue(queue &data) {
    create_queue(data);
    int num;
    int value;
    cout << "How many items are in the queue? ";
    cin  >> num;
    
    for (int q = 0; q < num; q++) {
        cout << "Please enter number " << q + 1 << ": ";
        cin >> value;
        enque(data, value);
    }
}

void print_queue(fstream &outfile, string s, queue &q) {
    int item;
    
    outfile << s;
    while(!empty(q)) {
        deque(q, item);
        outfile << item << " ";
    }
}

/*
    for(int c = 0; c < SIZE; c++) {
        if(!empty(q))
            outfile << q.i[c] << " ";
        else
            return;
        --q.back;
    }
*/

bool openfile(fstream &outfile) {
    outfile.open("output.txt", ios::out); 
}
