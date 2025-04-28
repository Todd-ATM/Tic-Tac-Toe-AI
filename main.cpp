#include <iostream>

class Board {
  public:
  bool checked[3][3];
    //constructor
    Board() {
        resetBoard();
    }

   void DrawBoard() {
    //nested for loop to draw horizontal and vertical dividers of our board
    std::cout << " +---+---+---+" << std::endl;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            std::cout  << " | "  << MainBoard[i][j];
        }
    std::cout << " | " << std::endl;
    std::cout << " +---+---+---+" << std::endl;

    }
    }

    //should be fed standard input, e.g 1-3, not 0-2
    void MovePiece(int row, int col) {
        //scope
        if (row < 3 && row >= 0 && col < 3 && col >= 0) {

                        // if current player is X
                        if (CurrentPlayer == true) {
                            MainBoard[row][col] = playerX;
                            checked[row][col] = true;
                        // if current player is O
                        } else if (CurrentPlayer == false) {
                            MainBoard[row][col] = playerO;
                            checked[row][col] = true;
                        }
        }
    }

    bool checkWin(int &spaceChecker) {
        char winner;
        //check rows
        for (int i = 0; i < Row; i++) {
            if (MainBoard[i][0] == MainBoard[i][1] && MainBoard[i][1] == MainBoard[i][2] && MainBoard[i][0] != ' ') {
                winner = MainBoard[i][0];
                std::cout << winner << ": Won the game" << std::endl;
                spaceChecker = 0;
                return true;
            }
        }
        for (int i = 0; i < Col; i++) {
            //check col
            if (MainBoard[0][i] == MainBoard[1][i] && MainBoard[1][i] == MainBoard[2][i] && MainBoard[0][i] != ' ') {
                winner = MainBoard[0][i];
                std::cout << winner << ": Won the game" << std::endl;
                spaceChecker = 0;
                return true;
            }
        }
            
            //first diagonal
             if (MainBoard[0][0] == MainBoard[1][1] && MainBoard[1][1] == MainBoard[2][2] && MainBoard[0][0] != ' ') {
                winner = MainBoard[0][0];
                std::cout << winner << ": Won the game" << std::endl;
                spaceChecker = 0;
                return true;
            }
            //last diagonal
             if (MainBoard[0][2] == MainBoard[1][1] && MainBoard[1][1] == MainBoard[2][0] && MainBoard[0][2] != ' ') {
                winner = MainBoard[0][2];
                std::cout << winner << ": Won the game" << std::endl;
                spaceChecker = 0;
                return true;
            }  if (spaceChecker == 9) {
                std::cout << "TIE. " << std::endl;
                spaceChecker = 0;
                return true;
            }
            else return false;
        }

    void resetBoard() {
        char value = ' '; 
        //nested for loops to iterate, and assign value
        //to each element in our 2d array
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                MainBoard[i][j] = value;
                checked[i][j] = false;
            }
        }

        //reset checked board's values
    }

    //basic changer
    bool change() {
        if (CurrentPlayer == true) {
            CurrentPlayer = false;
            return false;
        } 
        else if (CurrentPlayer == false) {
            CurrentPlayer = true;
            return true;
        } else 
        std::cout << "Player invalid" << std::endl;
        return false;
    }


  private:
    int Row = 3;
    int Col = 3;
    char MainBoard[3][3];
    const char playerX = 'X';
    const char playerO = 'O';
    bool CurrentPlayer = false;
    //identical to mainboard but at each element, adds checked bool for true
};

int main() {
    Board main;
    bool CurrentTurn = false; //who's turn is it currently, False = O's
    bool isPlaying = true;
    char FinalDec;
    int spaceChecker = 0;

    //opening message 
    std::cout << "# Welcome to Tic Tac Toe ! " << std::endl;
    std::cout << std::endl;
    std::cout << "This is a starter project to showcase a bit of Object Oriented Programming with " << std::endl;
    std::cout << "a board class, as well user input validation, and game logic" << std::endl;
    std::cout << std::endl;
    main.DrawBoard();
    //main game loop
    while (isPlaying) {
        int rowDec, colDec;
        char next; //char for next line in cin buffer
        //cases for who's turn
        bool WinStatus;

        //call wincheck everytime we restart
        WinStatus = main.checkWin(spaceChecker);

        if (WinStatus) {
            char FinalDec;
            std::cout << "Would you like to try again?" << std::endl;
            std::cout << "Y | N" << std::endl;
            std::cin >> FinalDec;

            //exception handling
            if (!std::cin) { //if user enters non number
                std::cin.clear(); //clear fail state
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid character... Y or N" << std::endl;
                continue; //restart loop
            }

            //set next to next character in cin stream
            next = std::cin.peek();

            if (next == '\n') {
                FinalDec = std::toupper(FinalDec);

                if (FinalDec == 'Y') {
                    std::cout << "You chose to play again. " << std::endl;
                    main.resetBoard();
                    continue;
                } 
                 if (FinalDec == 'N') {
                    isPlaying = false;
                    break;
                } else {
                    std::cout << "Please enter valid character... Y or N" << std::endl;
                    continue; //restart loop
                }
            }

            else {
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid character... Y or N" << std::endl;
                continue; //restart loop
            }

        }
        if (CurrentTurn == false) {
            std::cout << "O's Turn" << std::endl;
        }
        if (CurrentTurn == true) {
            std::cout << "X's Turn" << std::endl;
        }
            std::cout << "Enter Row Number(1-3) -> ";
            std::cin >> rowDec;
            //exception handling
            if (!std::cin) { //if user enters non number
                std::cin.clear(); //clear fail state
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid NUMBER" << std::endl;
                continue; //restart loop
            }
            if (rowDec < 4 && rowDec >= 1) {
                next = std::cin.peek(); //set next char in line to next char variable
                if (next == '\n') { 
                   
                }
                else {
                    std::cin.ignore(100, '\n'); //flush bad input
                    std::cout << "Please enter valid NUMBER" << std::endl;
                    continue; //restart loop
                }
            }
            else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }

            std::cout << "Enter Col Number(1-3) -> ";
            std::cin >> colDec;

            //exception handling
            if (!std::cin) { //if user enters non number
                std::cin.clear(); //clear fail state
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid Col Number. Retry" << std::endl;
                continue; //restart loop
            }
            if (colDec < 4 && colDec >= 1 && rowDec < 4 && rowDec >= 1) {
                next = std::cin.peek();
                rowDec = rowDec - 1;
                colDec = colDec - 1;
                if (next == '\n' && !main.checked[rowDec][colDec]) {
                    main.MovePiece(rowDec, colDec);
                    spaceChecker++;
                    main.DrawBoard();
                    CurrentTurn = main.change();
                } else {
                    std::cin.ignore(100, '\n'); //flush bad input
                    std::cout << "Please enter valid Col Number. Retry" << std::endl;
                    continue; //restart loop
                }
            } else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }
        }
        std::cout << "Thanks for playing. ";
    }
