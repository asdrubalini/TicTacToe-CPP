#pragma once
#include <iostream>

#define PLAYGROUND_SIZE 9

/*
Custom types so you don't have to repeat 'signed int' every time,
just use 'cell' or 'player' so the code is more readable.
*/
typedef signed int cell;
typedef signed int player;

// Player constants
const cell PLAYER_ONE = -1;
const cell PLAYER_TWO = 1;
const cell NO_PLAYER = 0;

class TicTacToe {
private:
	/* 
	We first need to create and initialize the playground to empty.
	This array will be updated for every new move.
	*/
	cell playground[PLAYGROUND_SIZE] = {
		NO_PLAYER, NO_PLAYER, NO_PLAYER,
		NO_PLAYER, NO_PLAYER, NO_PLAYER,
		NO_PLAYER, NO_PLAYER, NO_PLAYER
	};

	/* 
	All the combinations (which are 8) are hardcoded.
	Those integers are the playground[] index used by check_tris() function
	*/ 
	int COMBINATIONS[8][3] = {
		// Rows
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},

		// Columns
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},

		// Diagonals
		{0, 4, 8},
		{2, 4, 6}
	};

	// Total moves count in the game
	int moves = 0;
public:
	TicTacToe();
	
	/*
	Check whether or not someone won the game.
	Should be called from one move and the other.
	*/
	player check_tris();
	/*
	Check whether or not the game terminated in parity
	*/
	bool check_parity();
	/*
	Check whether or not the desired move is valid.
	Should be called before adding the move in memory
	*/
	bool is_valid_move(int pos);
	/* 
	Add the actual move in memory.
	Please, call check_tris() and THEN add_move()
	*/
	void add_move(int pos, player player);
	/*
	Get beautified version of player.
	Instead of printing 1 or -1, this function will return
	"player one" or "player two" which is way more appreciated
	*/
	std::string get_player(player player);

	// Pretty print
	void print_winner();
	void print_playground();

	~TicTacToe();
};