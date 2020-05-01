//
// Created by Edmond on 24/04/2020.
//

#ifndef UNTITLED5_GAME_MOVEMENT_H
#define UNTITLED5_GAME_MOVEMENT_H
#include "game_init.h"
void turns(square board[BOARD_SIZE][BOARD_SIZE],player myPlayers);
int movement_checker(int row,int column,int new_row,int new_column);
void stacking_pieces(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,int new_row,int new_column,player myPlayer);
#endif //UNTITLED5_GAME_MOVEMENT_H


