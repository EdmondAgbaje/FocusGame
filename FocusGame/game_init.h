//
// Created by Edmond on 03/04/2020.
//

#ifndef UNTITLED5_GAME_INIT_H
#define UNTITLED5_GAME_INIT_H


#define BOARD_SIZE 8
#define PLAYERS_NUM 2
#include <stdbool.h>


//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the color associated with the player
    color player_color;
//player characteristics(name,reserved pieces and captured pieces)
    char name[30];
    int captured_pieces;
    int kept_pieces;

}player;

// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);
void set_invalid(square * s);
void set_empty(square * s);
void set_green(square * s);
void set_red(square * s);
void gameRules();
#endif //UNTITLED5_GAME_INIT_H