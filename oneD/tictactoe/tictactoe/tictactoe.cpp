// ########################################
// # TicTacToe 1.0 (against the computer) #
// ########################################

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions(); // Displays game instructions
char askYesNo(string question); // asks a yes/no question and receives a y or n char
int askNumber(string question, int high, int low = 0); // Asks for a number between low and high
char humanPiece(); // Determines if it is a human piece, yeterns 'X' or 'O'
char opponent(char piece); // Calculates opposing piece (X/O), given a piece
void displayBoard(const vector<char>& board); // Receives a board array and displays it on screen
char winner(const vector<char>& board); // Determines the game winner (X, O, Tie, None)
bool isLegal(const vector<char>& board, int move); // Determines whether a move is legal
int humanMove(const vector<char>& board, char human); // Get's the human's move
int computerMove(vector<char> board, char computer); // Calculates the computer's move
void announceWinner(char winner, char computer, char human); // Declares winner or tie


int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);

	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = humanMove(board, human);
			board[move] = human;
		}
		else {
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}

	announceWinner(winner(board), computer, human);

	return 0;
}


void instructions() {
	cout << "\nWelcome to Tic Tac Toe!\n";
}

char askYesNo(string question) {
	char rawResponse;
	do {
		cout << "\n" + question + "? (y)es  (n)o: ";
		cin >> rawResponse;
	} while ((rawResponse != 'y') && (rawResponse != 'n'));
	return rawResponse;
}


int askNumber(string question, int high, int low) {
	int rawResponse;

	do {
		cout << "\n" << question << low << " - " << high << ": ";
		cin >> rawResponse;
	} while ((rawResponse < low) && (rawResponse > high));

	return rawResponse;
}


char humanPiece() {
	char human = askYesNo("Player X goes first. Do you want to be player X?");
	if (human == 'y') {
		return X;
	}
	else {
		return O;
	}
}

char opponent(char piece) {
	char oppo;
	oppo = (piece == O ? X : O);
	return oppo;
}

void displayBoard(const vector<char>& board) {
	cout << "Welcome to 1-D TicTacToe\n\n";

	cout << "\n " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "-----------" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "-----------" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "\n\n";
}

char winner(const vector<char>& board) {
	const int TOTAL_ROWS = 8;
	const int WINNING_ROWS[8][3] = { { 0,1,2 }, { 3,4,5 }, { 6,7,8 }, { 0,3,6 }, { 1,4,7 }, { 2,5,8 }, {0,4,9}, {2,4,7} };
	

	for (int i = 0; i < TOTAL_ROWS; ++i) {
		if ((board[WINNING_ROWS[i][0]] != EMPTY) && 
			((board[WINNING_ROWS[i][0]] == board[WINNING_ROWS[i][1]]) 
				&& (board[WINNING_ROWS[i][1]] == board[WINNING_ROWS[i][2]]))) {
			return board[WINNING_ROWS[i][0]];
		}
		if (count(board.begin(), board.end(), EMPTY) == 0) {
			return TIE;
		}
	}
	return NO_ONE;
}

bool isLegal(int move, const vector<char> board) {
	return (board[move] == EMPTY);
 }

int humanMove(const vector<char>& board, char human) {
	int response = askNumber("Where will you move?", (board.size() - 1));

	while (!isLegal(response, board)) {
		cout << "\nThat square is taken - choose again!\n" ;
		response = askNumber("Where will you move?", (board.size() - 1));
	}
	return response;
}

int computerMove(vector<char> board, char computer) {
	unsigned int move = 0;
	bool found = false;

	while (!found && move < board.size()) {
		if (isLegal(move, board)) {
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found) {
			++move;
		}
	}

	if (!found) {
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size()) {
			if (isLegal(move, board)) {
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found) {
				++move;
			}
		}		
	}

	if (!found) {
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		
		while (!found && i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			++i;
		}
	}
	
	cout << "Computer takes square " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human) {
	if (winner == computer || winner==human) {
		cout << winner << " wins!\n";
	}
	else {
		cout << "It's a tie!\n";
	}
}