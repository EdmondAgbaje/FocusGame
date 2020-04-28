#include <stdio.h>
#include "input_output.h"
#include <stdlib.h>
#include <stdbool.h>


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

/*    color playerTurn = RED;
    if( RED){
        playerTurn = GREEN;
        printf("%s's turn to play now",players[1].name);
    } else{
        printf("%s's turn to play now"),players[0].name);
    }*/


    return 0;
}

