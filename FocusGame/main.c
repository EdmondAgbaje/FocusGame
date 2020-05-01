#include <stdio.h>
#include "input_output.h"
#include "game_movement.h"
#include "game_init.h"
#include <stdbool.h>


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    color playerTurn = RED;//this initially sets the color to red and player 1 is assigned to this color
    while(players[0].winner== false && players[1].winner==false){//if a winner hasn't been found the players turns will continue to switch after each move is made
        if(playerTurn == RED) {
            turns(board, players[0]);
        }else{
            turns(board,players[1]);
        }

        if(playerTurn == RED){
        playerTurn = GREEN;
        printf("%s's turn to play now\n",players[1].name);
    } else{
            playerTurn = RED;
            printf("%s's turn to play now\n",players[0].name);
        }
    }


    return 0;
}

