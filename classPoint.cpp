// Tee Wei Zhong
// Lab 11 - Experiment 2
// Date: 21-11-2019
// This Program is a Bingo Chess Game Four in a Row. It uses different header and cpp files with different classes to make a 2 player game.
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "classPoint.h"
using namespace std;

void Point::setInput(int a) { // Input functions are used to see if the user had input a valid number for the placement of his/her token.
  input = a;
}

int Point::getInput () {
  if (input <= 0 || input > 7) {
    input = 0;
  }
  return input - 1;
}

int Point::FullCheck(int turn[6][7]) { // There is also a check to see when a column is full; if there is a column that is full the user will be prompted to re-enter their input.
  int check = 0;
  for (int x = 5; x >= 0; x--) {
    if (turn[x][getInput()] == 1 || turn[x][getInput()] == 2) {
      if (turn[x-1][getInput()] == 1 || turn[x-1][getInput()] == 2) {
        check += x;
      }
    }
  }
  return check;
}

void Point::playerTurn(int turn[6][7]) {
  gravity(turn);
}

void Point::playerTurn(int turn[6][7], int a, int b) {
  turn[b-1][a-1] = 0;
  cout << "Token has been removed!" << endl;
}

void Point::setPlayer1(int a) { // The charcter name of players are returned after the user inputs which number in relation to the character names.
  string firstName, lastName;
  int score;
  fstream inputStream;

  inputStream.open("user.txt");

  for (int x = 0; x < 5; x++) {
    inputStream >> score;
    inputStream >> firstName >> lastName;
    if (x == a) {
      cout << "Name: " << firstName << " " << lastName << endl;
      cout << "Score: " << score << endl;
      player1 = firstName + " " + lastName;
      player1score = score; //player name is returned
    }
  }
  inputStream.close();
}

string Point::getPlayer1() {
  return player1;
}

void Point::setPlayer1score(int a) {
  if (a == 1) {
    player1score = player1score + 1;
  }

  if (a == 0) {
    player1score -= 1;
  }
}

int Point::getPlayer1score() {
  return player1score;
}

void Point::setPlayer2(int a) { // A function is then used to add or deduct points from the user profile the players chose, depending on which player won the game.
  string firstName, lastName;
  int score;
  fstream inputStream;

  inputStream.open("user.txt");

  for (int x = 0; x < 5; x++) {
    inputStream >> score;
    inputStream >> firstName >> lastName;
    if (x == a) {
      cout << "Name: " << firstName << " " << lastName << endl;
      cout << "Score: " << score << endl;
      player2 = firstName + " " + lastName;
      player2score = score;
    }
  }
  inputStream.close();
}

string Point::getPlayer2() {
  return player2;
}

void Point::setPlayer2score(int a) {
  if (a == 1) {
    player2score += 1;
  }

  if (a == 0) {
    player2score -= 1;
  }
}

int Point::getPlayer2score() {
  return player2score;
}

void Point::writeUser(int a, int b) { // A function in point Class then rewrites the textfile to update the new scores; the loser has a score deducted while the winner has a score added.
  string firstName, lastName;
  int score;
  fstream inputStream;
  string names[5];
  int writing[5];

  inputStream.open("user.txt");


  for(int x = 0; x < 5; x++) {
    inputStream >> score;
    inputStream >> firstName >> lastName;
    writing[x] = score;
    names[x] = firstName + " " + lastName;
  }

  inputStream.close();
  for(int x = 0; x < 5; x++) {
    if (x == a) {
      writing[x] += 1;
    }

    else if (x == b) {
      writing[x] -= 1; //point is added or deducted base on which charcter was the winner/loser
    }
  }
  ofstream write;
  write.open("user.txt");
  for(int x = 0; x < 5; x++) {
    write << writing[x] << "\n";
    write << names[x] << "\n"; //the new scores and character names are put into an array and written into the text file.
  }
  write.close();
}
