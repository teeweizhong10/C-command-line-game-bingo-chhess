# C-command-line-game-bingo-chhess

Authour: Wei Zhong Tee
Last Updated: 15 November 2019
Project Type: Command line game with C++

This is bingo chess game four in a row game that is meant to be run on the command line.

It uses different header and cpp
files with different classes to make a 2 player game. A 2 dimension array is first
initialised with 0s. The players first select which character they would like to use from
the list of characters. A class named BasePoint is created and it has several functions.
The gravity function ensures that the token the user inputs is brought to the lowest point
of this game board. This is done by using a bubble sort like method, where if the array
index underneath the token is empty the token location is swapped with the blank array
index below. A new two dimension array is made with string data types. This is for what
the user sees in the output. While the game works in 0s, 1s and 2s, the user only sees
Xs and Os. Player 1's icons are represented by the Os and player 2's icons are
represented by the Xs. The function winCheck() checks if either of the players has won
the game. The first check it does it to see if a user has won by having 4 tokens that are
vertically in a row. If there is, it returns a value that indicates a player has won.
When a token of the player is detected, it checks if there are three consecutive tokens
underneath. If there are, it is considered a win. The second check is if there are four
consecutive horizontal tokens. Like the vertical test, the horizontal test checks to see if
there is a token in place. If there is, it checks all the tokens to its right to see if there are
4 consecutive tokens. The final and most complicated check is the diagonal check. This
check has to run twice; once for the tokens that are ascending from left to right, and
once for the tokens that are ascending from right to left. When a token is detected, it
checks if there are 4 consecutive diagonal tokens on the board. This is done by
searching either array index to the bottom right or the array index to the top right. Input

functions are used to see if the user had input a valid number for the placement of
his/her token. There is also a check to see when a column is full; if there is a column
that is full the user will be prompted to re-enter their input. The character name of
players are returned after the user inputs which number in relation to the character
names. A function is then used to add or deduct points from the user profile the players
chose, depending on which player won the game. A function in point Class then rewrites
the text file to update the new scores; the loser has a score deducted while the winner
has a score added.
An infinite loop runs the game until the win checking functions returns a value that
indicates a player has won. The players take turns to input a token. Functions ensure
that users do not place a token in a full column.
