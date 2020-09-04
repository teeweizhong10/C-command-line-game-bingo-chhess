// Tee Wei Zhong
// Lab 11 - Experiment 2
// Date: 21-11-2019
// This Program is a Bingo Chess Game Four in a Row. It uses different header and cpp files with different classes to make a 2 player game.
#ifndef POINT_H
#define POINT_H

#include "classBasePoint.h"

class Point: public BasePoint {
public:
  void setInput(int a);
  int getInput ();
  int FullCheck(int turn[6][7]);
  void playerTurn(int turn[6][7]);
  void playerTurn(int turn[6][7], int a, int b);
  void setPlayer1(int a);
  std::string getPlayer1();
  void setPlayer1score(int a);
  int getPlayer1score();
  void setPlayer2(int a);
  std::string getPlayer2();
  void setPlayer2score(int a);
  int getPlayer2score();
  void writeUser(int a, int b);

private:
  int input;
  std::string player1;
  std::string player2;
  int player1score;
  int player2score;
};
#endif
