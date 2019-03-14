#include "TicTacToe.h"
#include <iostream>


TicTacToe::TicTacToe() {
}


player TicTacToe::check_tris() {
	for (int i = 0; i < 8; i++) {
		int* combinations = COMBINATIONS[i];

		// Sum up all the combinations
		int sum = 0;
		for (size_t i = 0; i < 3; i++) {
			sum += playground[combinations[i]];
		}

		switch (sum) {
			case -3:
				// Player one won, return it
				return PLAYER_ONE;
				break;
			case 3:
				// Player two won, return it
				return PLAYER_TWO;
				break;
		}
	}

	// Nobody won. Return NO_PLAYER which is 0
	return NO_PLAYER;
}

bool TicTacToe::is_valid_move(int pos) {
	signed int current = playground[pos];
	return (current == NO_PLAYER);
}

void TicTacToe::add_move(int pos, player player) {
	playground[pos] = player;
}

std::string TicTacToe::get_player(player player) {
	// Return player as string
	switch (player) {
		case PLAYER_ONE:
			return "player one";
			break;
		case PLAYER_TWO:
			return "player two";
			break;
		case NO_PLAYER:
			return "";
			break;
	}
}

void TicTacToe::print_winner() {
	int tris = TicTacToe::check_tris();

	switch (tris) {
		case PLAYER_ONE:
			std::cout << "Player one won" << std::endl;
			break;
		case PLAYER_TWO:
			std::cout << "Player one won" << std::endl;
			break;
		case NO_PLAYER:
			// Nobody won, do nothing
			break;
	}
}

void TicTacToe::print_playground() {
	for (int i = 0; i < sizeof(playground) / sizeof(playground[0]); i++) {
		switch (playground[i]) {
			case -1:
				//std::cout << "-1 ";
				std::cout << "o ";
				break;
			case 1:
				//std::cout << "1 ";
				std::cout << "x ";
				break;
			case 0:
				//std::cout << "0 ";
				std::cout << "# ";
				break;
		}

		if (i % 3 == 2) {
			std::cout << "\n";
		}
	}

	std::cout << "\n";
}


TicTacToe::~TicTacToe() {
}
