#include <iostream>
#include "TicTacToe.h"

player exchange_player(cell player) {
	switch (player) {
		case PLAYER_ONE:
			return PLAYER_TWO;
			break;
		case PLAYER_TWO:
			return PLAYER_ONE;
			break;
	}
}

bool validate_input(int input) {
	return input >= 1 && input <= 9;
}

int main() {
	TicTacToe tris;
	bool game_terminated = false;
	player current_player = PLAYER_ONE;

	while (!game_terminated) {
		std::cout << "E' il turno di " << tris.get_player(current_player) << std::endl;
		tris.print_playground();
		
		std::cout << "Inserisci il numero della casella in cui vuoi inserire la pedina (1 -> 9): ";
		int pos;
		std::cin >> pos;

		// First check if the user input is valid or not
		if (!validate_input(pos)) {
			std::cout << "\"" << pos << "\"" << " invalid input" << std::endl;
			return 1;
		}

		pos--;		// Array's indexes starts from zero, which is not user friendly		

		if (!tris.is_valid_move(pos)) {
			std::cout << "Move not valid" << std::endl;
			return 1;
		}
		else {
			tris.add_move(pos, current_player);
		}

		if (tris.check_tris() != NO_PLAYER) {
			std::cout << tris.get_player(current_player) << " has won!" << std::endl;
			game_terminated = true;
		}
		else if (tris.check_parity()) {
			std::cout << "Game terminated with parity" << std::endl;
			game_terminated = true;
		}

		current_player = exchange_player(current_player);
	}

	std::cin.ignore();
    return 0;
}