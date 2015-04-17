// Toufic Hamadeh
// UCID 31234305
// 20-FEB-2013

// Professor Kapleau
// CS-280-002
// Knight's Tour in C++

#include <iostream>
#include <iomanip>
using namespace std;

// Global
const int SIZE = 8;
int chessBoard[SIZE][SIZE];
int start = 1;
int border = 8;
int x, y;

// Function Prototypes
void calculate(int, int);
void tourBoard(int, int);
void printBoard();

// Main
int main(int argc, char *argv[]) {
    tourBoard(0, 0);
    printBoard();

    return 0;
}

void calculate(int i, int j) {
    int a;
    int b;
    int counter;

    a = i;
    b = j;
    counter = 0;

    if ((a >= 0 && b >= 0) && (a < 8 && b < 8)) {
        if ((a-2 >= 0 && a-2 < 8 && b+1 >= 0 && b+1 < 8) && (chessBoard[a-2][b+1]==0)) {
            counter++;
        }
        if ((a-2 >= 0 && a-2 < 8 && b-1 >= 0 && b-1 < 8) && (chessBoard[a-2][b-1]==0)) {
            counter++;
        }
        if ((a-1 >= 0 && a-1 < 8 && b+2 >= 0 && b+2 < 8) && (chessBoard[a-1][b+2]==0)) {
            counter++;
        }
        if ((a-1 >= 0 && a-1 < 8 && b-2 >= 0 && b-2 < 8) && (chessBoard[a-1][b-2]==0)) {
            counter++;
        }
        if ((a+2 >= 0 && a+2 < 8 && b+1 >= 0 && b+1 < 8) && (chessBoard[a+2][b+1]==0)) {
            counter++;
        }
        if ((a+2 >= 0 && a+2 < 8 && b-1 >= 0 && b-1 < 8) && (chessBoard[a+1][b-1]==0)) {
            counter++;
        }
        if ((a+1 >= 0 && a+1 < 8 && b+2 >= 0 && b+2 < 8) && (chessBoard[a+1][b+2]==0)) {
            counter++;
        }
        if ((a+1 >= 0 && a+1 < 8 && b-2 >= 0 && b-2 < 8) && (chessBoard[a+1][b-2]==0)) {
            counter++;
        }
    }
    if (counter < border) {
        border = counter;
        x = i;
        y = j;
    }
}

void tourBoard(int i, int j) {
    int a, b;
    a = i;
    b = j;

    if (start < 65) {
        if (chessBoard[a+2][b-1] == 0)
            if(a+2 >= 0 && a+2 < 8)
                if(b-1 >= 0 && b-1 < 8)
                    calculate(a+2, b-1);
        if(chessBoard[a+2][b+1] == 0)
            if(a+2 >= 0 && a+2 < 8)
                if(b+1 >= 0 && b+1 < 8)
                    calculate(a+2, b+1);
        if(chessBoard[a-1][b+2] == 0)
            if(a-1 >= 0 && a-1 < 8)
                if(b+2 >= 0 & b+2 < 8)
                    calculate(a-1, b+2);
        if(chessBoard[a+1][b+2] == 0)
            if(a+1 >= 0 && a+1 < 8)
                if(b+2 >= 0 && b+2 < 8)
                    calculate(a+1, b+2);
        if(chessBoard[a-2][b+1] == 0)
            if(a-2 >= 0 && a-2 < 8)
                if(b+1 >= 0 && b+1 < 8)
                    calculate(a-2, b+1);
        if(chessBoard[a-2][b-1] == 0)
            if(a-2 >= 0 && a-2 < 8)
                if(b-1 >= 0 && b-1 < 8)
                    calculate(a-2, b-1);
        if(chessBoard[a+1][b-2] == 0)
            if(a+1 >= 0 && a+1 < 8)
                if(b-2 >= 0 && b-2 < 8)
                    calculate(a+1, b-2);
        if(chessBoard[a-1][b-2] == 0)
            if(a-1 >= 0 && a-1 < 8)
                if(b-2 >= 0 && b-2 < 8)
                    calculate(a-1, b-2);

         chessBoard[i][j]=start++;
         border = 8;
         tourBoard(x, y);
    }
}

// Output
void printBoard() {
    cout << "\n Knight's Tour\n\n";
    for(int i = 0; i < 8; i++) {
          for(int j = 0; j < 8; j++)
          cout << " " << setw (2) << chessBoard[i][j];
          cout << endl << endl;
     }
     cout << endl << endl;
}
