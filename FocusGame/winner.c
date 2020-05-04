//
// Created by Edmond on 02/05/2020.
//

#include "winner.h"
#include "game_init.h"
#include <stdlib.h>
#include <stdbool.h>

bool Winner(square board[BOARD_SIZE][BOARD_SIZE],player myPlayer){//function that checks if a winner has been found in the game
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j].stack != NULL && board[i][j].type == VALID){
                if(board[i][j].stack->p_color || myPlayer.kept_pieces > 0){
                    return false;
                }
            }
        }
    }
    return true;
}