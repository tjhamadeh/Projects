// Toufic Hamadeh
// UCID 31234305
// 20-FEB-2013

// Professor Kapleau
// CS-280-002
// Knight's Tour in Java

public class tour {
  public static void main(String[] args) {
    KnightsTour kt = new KnightsTour();
    kt.begin(0, 0);
  }
}

class KnightsTour {
    int chessBoard[][] = new int[8][8];
    int checkBoard[][] = new int[8][8];
    int[] horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
    int[] vertical =   {-1, -2, -2, -1, 1, 2, 2, 1};
    int cRow;
    int cCol;
    int moveNumber;
    int counter = 0;
    int hori, vert;
    int possible = 0;
    int fMove, lMove;
    int tempV, tempH;
       
public void begin(int a, int b){
    for(int i = 0; i < chessBoard.length; i++){
        for(int u = 0; u < chessBoard[i].length; u++){
            chessBoard[i][u] = 0;
        }
    }
    runAccess();
               
    cRow = a;
    cCol = b;
    move();
}
       
public void runAccess(){
    for(int i = 0; i < checkBoard.length; i++){
        for(int u = 0; u < checkBoard[i].length; u++){
            cRow = i;
            cCol = u;
            access();
            checkBoard[i][u] = possible;
        }
    }
}

// Moves the knight
public void move(){
    chessBoard[cRow][cCol] = counter + 1;
    tempH = cCol;
    tempV = cRow;
    runAccess();

    cCol = tempH;
    cRow = tempV;
    access();

    moveNumber = fMove;
    hori = horizontal[moveNumber];
    vert = vertical[moveNumber];
    cRow += vert;
    cCol += hori;
    
    ++counter;
    if(counter == 64){
        runAccess();
        finalPrint();
    } else {
        move();
    }
}

public void finalPrint(){
    System.out.println("\n Knight's Tour\n");
    for(int i = 0; i < chessBoard.length; i++){
        for(int u = 0; u < chessBoard[i].length; u++){
            System.out.printf(" %2d", chessBoard[u][i]);
        }
        System.out.println("\n");
    }
}

public void access(){
               
    moveNumber = 0;
    possible = 0;
    fMove = 0;
    lMove = 9;

    for(int i = 0; i < 8; i++){
        moveNumber = i;
        hori = horizontal[moveNumber];
        vert = vertical[moveNumber];
        if(cRow + vert < checkBoard.length && cCol + hori < checkBoard[i].length && cRow + vert >= 0 && cCol + hori >= 0){
            if(chessBoard[cRow + vert][cCol + hori] == 0){
                ++possible;
                if(checkBoard[cRow + vert][cCol + hori] < lMove){
                    fMove = i;
                    lMove = checkBoard[cRow + vert][cCol + hori];
                }
            }      
        }
    }
}

} // end KnightsTour
