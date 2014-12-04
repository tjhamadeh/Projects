// Toufic Hamadeh
// UCID 31234305
// 20-FEB-2013

// Professor Kapleau
// CS-280-002
// Knight's Tour

#include <iostream>
#include <iomanip>
using namespace std;

// Global
const int SIZE = 8;
int chessBoard[SIZE][SIZE];

// Function Prototypes
void calculate(int, int, int&, int&, int&);
void tourBoard(int, int, int&, int&, int& , int&);
void printBoard();

// Main
int main(int argc, char *argv[]) {
    int x, y;
    int start;
    int border;

    start = 1;

    tourBoard(0, 0, start, border, x, y);
    printBoard();

    return 0;
}

void calculate(int i, int j, int& border, int& x, int& y) {
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

void tourBoard(int i, int j, int& start, int& border, int& x, int& y) {
    int a, b;
    a = i;
    b = j;

    if (start < 65) {
        if ((chessBoard[a+2][b+1] == 0) && (a+2 >= 0 && a+2 < 8) && (b+1 >= 0 && b+1 < 8))
		calculate(a+2, b+1, border, x, y);

	if ((chessBoard[a+2][b-1] == 0) && (a+2 >= 0 && a+2 < 8) && (b-1 >= 0 && b-1 < 8))
		calculate(a+2, b-1, border, x, y);

	if ((chessBoard[a-1][b+2] == 0) && (a-1 >= 0 && a-1 < 8) && (b+2 >= 0 && b+2 < 8))
		calculate(a-1, b+2, border, x, y);

	if ((chessBoard[a+1][b+2] == 0) && (a+1 >= 0 && a+1 < 8) && (b+2 >= 0 && b+2 < 8))
		calculate(a+1, b+2, border, x, y);

	if ((chessBoard[a-2][b+1] == 0) && (a-2 >= 0 && a-2 < 8) && (b+1 >= 0 && b+1 < 8))
		calculate(a-2, b+1, border, x, y);

	if ((chessBoard[a-2][b-1] == 0) && (a-2 >= 0 && a-2 < 8) && (b-1 >= 0 && b-1 < 8))
		calculate(a-2, b-1, border, x, y);

	if ((chessBoard[a+1][b-2] == 0) && (a+1 >= 0 && a+1 < 8) && (b-2 >= 0 && b-2 < 8))
		calculate(a+1, b-2, border, x, y);

        if ((chessBoard[a-1][b-2] == 0) && (a-1 >- 0 && a-1 < 8) && (b-2 >= 0 && b-2 < 8))
		calculate(a-1, b-2, border, x, y);

         chessBoard[i][j]=start++;
         border = 8;
         tourBoard(x, y, start, border, x, y);
    }
}

// Output
void printBoard() {
    cout << "\n Knight's Tour\n\n";
    for(int i = 0; i < 8; i++) {
          for(int j = 0; j < 8; j++)
          cout << " " << setw (2) << setfill('0') << chessBoard[i][j];
          cout << endl << endl;
     }
     cout << endl << endl;
}
