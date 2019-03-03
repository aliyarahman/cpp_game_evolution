#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char rawResponse, firstTurn, playAgain;
	bool keepPlaying = true;
	//int squareNum;

	while (keepPlaying == true) {
		cout << "Welcome to 1-D TicTacToe\n\n";
		
		cout << "\n 1 | 2 | 3 \n";
		cout << "-----------\n";
		cout << " 4 | 5 | 6 \n";
		cout << "-----------\n";
		cout << " 7 | 8 | 9 \n";
		
		cout << "\n Do you want the first turn? (Y)es  (N)o: ";
		cin >> rawResponse;
		firstTurn = tolower(rawResponse);
		
		while (0) {
			// Game
		}
		
		cout << "\n Play again? (Y)es  (N)o: ";
		cin >> rawResponse;
		playAgain = tolower(rawResponse);
		if (playAgain == 'n') { keepPlaying = false;}
	}
	cout << "\n\nGoodbye!\n\n" << endl;
	cout << endl;
	return 0;
}
