// Tee Wei Zhong
// Lab 11 - Experiment 2
// Date: 21-11-2019
// This Program is a Bingo Chess Game Four in a Row. It uses different header and cpp files with different classes to make a 2 player game.

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "classBasepoint.h"
#include "classPoint.h"
using namespace std;

int main() {
  BasePoint run;
  Point player1, player2;

  int game[6][7];

  for (int x = 5; x >= 0 ;  x--) {
    for (int y = 0; y < 7; y++) { // A 2 dimension array is first initialised with 0s.
      game[x][y] = 0;
    }
  }

  int input;
  int gameRun = 1;
  int valid = 1;
  int turn = 1;
  int user1;
  int user2;

  string firstName, lastName;
  int score;
  fstream inputStream;

  inputStream.open("user.txt");

  for(int x = 0; x < 5; x++) {
    inputStream >> score;
    inputStream >> firstName >> lastName;
    cout << "(" << x + 1 << ") Name: " << firstName << " " << lastName << endl;
    cout << "Score: " << score << endl;
  }

  cout << endl;
  while (valid == 1) { // The players first select which character they would like to use from the list of characters.
    cout << "Input which user profile data you want player 1 to play as: ";
    cin >> user1;

    if (user1 <= 0 || user1 > 5) {
      cout << "Invalid input. Only choose a number from 1 to 5." << endl;
    }

    else {
      player1.setPlayer1(user1 - 1);
      cout << "Player 1 has chosen to play as " << player1.getPlayer1() << "." << endl << endl;
      valid = 0;
    }
  }
  valid = 1;
  cout << endl;
  while (valid == 1) {
    cout << "Input which user profile data you want player 2 to play as: ";
    cin >> user2;

    if (user2 <= 0 || user2 > 5) {
      cout << "Invalid input. Only choose a number from 1 to 5." << endl; //if player 2 chooses a chosen player, they will be asked to re-select their charcter
    }

    else if (user2 == user1) {
      cout << "This character has already been chosen." << endl;
    }

    else {
      player2.setPlayer2(user2 - 1);
      cout << "Player 2 has chosen to play as " << player2.getPlayer2() << "." << endl << endl;
      valid = 0;
    }
  }

  inputStream.close();

  while (gameRun == 1) { // An infinite loop runs the game until the the win checking functions returns a value that indicates a player has won.
    //PLAYER 1
    while (turn == 1) { // The players take turns to input a token.
      cout << "Player 1's turn.\nInput number to input token: ";
      cin >> input;
      player1.setInput(input);
      if (input <= 0 || input > 8 ) {
        cout << "Only input numbers from 1 to 7" << endl;
        turn = 1;
        break;
      }

      if (player1.FullCheck(game) == 15 ) {
        cout << "Only input a column with blank spaces" << endl; // Functions ensure that users do not place a token in a full column.
        turn = 1;
        break;
      }

      if (input == 8) { // When the special key is entered, the user is prompted to enter coordinates to have the opponent's token removed.
        int remove1;
        int remove2;
        cout << "You have entered the special number to remove your opponent's token." << endl;
        cout << "Enter the X coordinate for the token to be removed: ";
        cin >> remove1;
        cout << "Enter the Y coordinate for the token to be removed: ";
        cin >> remove2;
        player2.playerTurn(game, remove1, remove2);
        player2.playerTurn(game);
        run.printGame(game);
        turn = 2;
      }

      else {
        game[5][input - 1] = 1;
        player1.playerTurn(game);
        run.printGame(game);
        turn = 2;
      }
    }

    if (run.winCheck(game) == 1) {
      cout << player1.getPlayer1() <<" has won!" << endl;
      player1.writeUser(user1 - 1, user2 - 1);
      gameRun = 0;
      break;
    }

    //PLAYER 2
    while (turn == 2) {
      cout << "Player 2's turn.\nInput number to input token: ";
      cin >> input;
      player2.setInput(input);
      if (input <= 0 || input > 8 ) {
        cout << "Only input numbers from 1 to 7" << endl;
        turn = 2;
        break;
      }

      if (player2.FullCheck(game) == 15 ) {
        cout << "Only input a column with blank spaces" << endl;
        turn = 2;
        break;
      }

      if (input == 8) {
        int remove1;
        int remove2;
        cout << "You have entered the special number to remove your opponent's token." << endl;
        cout << "Enter the X coordinate for the token to be removed: ";
        cin >> remove1;
        cout << "Enter the Y coordinate for the token to be removed: ";
        cin >> remove2;

        player1.playerTurn(game, remove1, remove2);
        player1.playerTurn(game);
        run.printGame(game);
        turn = 1;
      }


      else {
        game[5][input - 1] = 2;
        player2.playerTurn(game);
        run.printGame(game);
        turn = 1;
      }
    }
    if (run.winCheck(game) == 1) {
      cout << player2.getPlayer2() << " has won!" << endl;
      player2.writeUser(user2 - 1, user1 - 1);
      gameRun = 0;
      break;
    }
  }
  return 0;
}
