// Tee Wei Zhong
// Lab 11 - Experiment 2
// Date: 21-11-2019
// This Program is a Bingo Chess Game Four in a Row. It uses different header and cpp files with different classes to make a 2 player game.
#ifndef BASEPOINT_H
#define BASEPOINT_H
class BasePoint {
public:
  void gravity(int turn[6][7]);
  void printGame (int turn[6][7]);
  int winCheck(int turn[6][7]);
};

#endif
