// Tee Wei Zhong
// Lab 11 - Experiment 2
// Date: 21-11-2019
// This Program is a Bingo Chess Game Four in a Row. It uses different header and cpp files with different classes to make a 2 player game.
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "classBasePoint.h" // A class named BasePoint is created and it has several functions.
using namespace std;

void BasePoint::gravity(int turn[6][7]) { // The gravity function ensures that the token the user inputs is brought to the lowest point of this game board.

  for (int x = 5; x >= 0 ;  x--) {
    for (int y = 0; y < 7; y++) {
      if (turn[x][y] == 1) {
        if (turn[x-1][y] == 0) { // This is done by using a bubble sort like method, where if the array index underneath the token is empty the token location is swapped with the blank array index below.
          turn [x][y] = 0;
          turn[x-1][y] = 1;
        }
      }

      else if (turn[x][y] == 2) {
        if (turn[x-1][y] == 0) {
          turn [x][y] = 0;
          turn[x-1][y] = 2;
        }
      }
    }
  }
}

void BasePoint::printGame (int turn[6][7]) {

  string game[6][7];

  for (int x = 5; x >= 0 ;  x--) {
    for (int y = 0; y < 7; y++) { // A new two dimension array is made with string data types. This is for what the user sees in the output.
      game[x][y] = " ";
    }
  }


  for (int x = 5; x >= 0; x--) {
    for (int y = 6; y >= 0 ; y--) { // While the game works in 0s, 1s and 2s, the user only sees Xs and Os. Player 1's icons are represented by the Os and player 2's icons are represented by the Xs.
      if (turn[x][y] == 1) {
        game[x][y] = "O";
      }

      else if (turn[x][y] == 2) {
        game[x][y] = "X";
      }
    }
  }

  cout << "_______________________________" << endl;
  cout << " 1  2  3  4  5  6  7  " << endl;

  for (int x = 5; x >= 0 ;  x--) {
    for (int y = 0; y < 7; y++) {
      cout << "[" << game[x][y] << "]";
    }
    cout << endl;
  }

  cout << "_______________________________" << endl << endl;
}

int BasePoint::winCheck(int turn[6][7]) { // The function winCheck() checks if either of the players has won the game.
  int win = 0;

  //vertical
  for (int x = 5; x >= 0 ;  x--) { // The first check it does it to see if a user has won by having 4 tokens that are vetically in a row. If there is, it returns a value that indicates a player has won.
    for (int y = 0; y < 7; y++) {
      //player 1
      if (turn[x][y] == 1) {
        if (turn[x-1][y] == 1) { // When a token of the player is detected, it checks if there are three consecutive tokens underneath. If there are, it is considered a win.
          if (turn[x-2][y] == 1) {
            if (turn[x-3][y] == 1) {
              win = 1;
            }
          }
        }
      }
      //player 2
      if (turn[x][y] == 2) {
        if (turn[x-1][y] == 2) {
          if (turn[x-2][y] == 2) {
            if (turn[x-3][y] == 2) {
              win = 1;
            }
          }
        }
      }
    }
  }

  //horizontal
  for (int x = 5; x >= 0 ;  x--) { // The second check is if there are four consecutive horizontal tokens.
    for (int y = 0; y < 7; y++) {
      //player 1
      if (turn[x][y] == 1) {
        if (turn[x][y+1] == 1) { // Like the vertical test, the horizontal test checks to see if there is a token in place. If there is, it checks all the tokens to its right to see if there are 4 consecutive tokens.
          if (turn[x][y+2] == 1) {
            if (turn[x][y+3] == 1) {
              win = 1;
            }
          }
        }
      }
      //player 2
      if (turn[x][y] == 2) {
        if (turn[x][y+1] == 2) {
          if (turn[x][y+2] == 2) {
            if (turn[x][y+3] == 2) {
              win = 1;
            }
          }
        }
      }
    }
  }

  //diagonal
  for (int x = 5; x >= 0 ;  x--) { // The final and most complicated check is the diagonal check. This check has to run twice; once for the tokens that are ascending from left to right, and once for the tokens that are ascending from right to left.
    for (int y = 0; y < 7; y++) {
      //player 1
      if (turn[x][y] == 1) {
        if (turn[x+1][y+1] == 1) { // When a token is detected, it checks if there are 4 consecutive diagonal tokens on the board. This is done by searching either array index to the bottom right or the array index to the top right.
          if (turn[x+2][y+2] == 1) {
            if (turn[x+3][y+3] == 1) {
              win = 1;
            }
          }
        }
      }
      //player 2
      if (turn[x][y] == 2) {
        if (turn[x+1][y+1] == 2) {
          if (turn[x+2][y+2] == 2) {
            if (turn[x+3][y+3] == 2) {
              win = 1;
            }
          }
        }
      }

      //player 1
      if (turn[x][y] == 1) {
        if (turn[x-1][y+1] == 1) {
          if (turn[x-2][y+2] == 1) {
            if (turn[x-3][y+3] == 1) {
              win = 1;
            }
          }
        }
      }
      //player 2
      if (turn[x][y] == 2) {
        if (turn[x-1][y+1] == 2) {
          if (turn[x-2][y+2] == 2) {
            if (turn[x-3][y+3] == 2) {
              win = 1;
            }
          }
        }
      }
    }
  }
  return win;
}
