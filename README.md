# Tic-Tac-Toe
Tictactoe game coded in C
board is a char type 2d array of order 3x3
move is a struct type variable with 2 int variables within it namely row & col

1.isFull():
takes board as input,
checks whether empty spaces are available,
returns false if empty spaces are available otherwise returns true

2.check():
takes board as input,
checks whether any of the 2 players have won,
returns +10 if x wins,-10 if o wins,0 otherwise

3.grid():
takes board as input,
prints the contents of board in the form of the tic-tac-toe grid

4.input():
takes input from the user,
checks whether the input is an integer between 1 and 9 (inclusive),
if input is invalid requests the user to enter a valid input, 
adds valid input to the board

5.minimax():
takes multiple inputs,
recursively searches through the game tree to evaluate a given move,
returns an int type variable bestscore

6.bestmove():
takes the board as input, 
iteratively searches through all empty cells of the board calling the minimax function at each step,
selects the best move and initializes the move variable

7.main():
displays the rules,winner and loser of the game,
runs any 1 of the 2 game loops within it corresponding to single player and multi player modes respectively 
