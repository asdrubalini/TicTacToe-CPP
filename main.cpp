#include <iostream>
#include "TicTacToe.h"

cell exchange_player(cell player) {
	switch (player) {
		case PLAYER_ONE:
			return PLAYER_TWO;
			break;
		case PLAYER_TWO:
			return PLAYER_ONE;
			break;
	}
}

int main() {
	TicTacToe tris;
	bool someone_won = false;
	cell current_player = PLAYER_ONE;

	while (!someone_won) {
		std::cout << "E' il turno di " << tris.get_player(current_player) << std::endl;
		tris.print_playground();
		
		std::cout << "Inserisci il numero della casella in cui vuoi inserire la pedina: ";
		int pos;
		std::cin >> pos;

		if (!tris.is_valid_move(pos)) {
			std::cout << "Move not valid" << std::endl;
			return 1;
		}
		else {
			tris.add_move(pos, current_player);
		}

		if (tris.check_tris() != NO_PLAYER) {
			std::cout << tris.get_player(current_player) << " has won!";
			someone_won = true;
		}

		current_player = exchange_player(current_player);
	}

	std::cin.ignore();
    return 0;
}