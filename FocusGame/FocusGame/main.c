#include <stdio.h>
#include "input_output.h"
#include "game_movement.h"
#include "game_init.h"
#include "winner.h"
#include <stdbool.h>


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    color playerTurn = RED;//this initially sets the color to red and player 1 is assigned to this color
    while(Winner(board,players[0]) == false && Winner(board,players[1])== false){//if a winner hasn't been found the players turns will continue to switch after each move is made
        turns(board, players, playerTurn);
        if(playerTurn == RED){
            playerTurn = GREEN;
        }else if(playerTurn == GREEN){
            playerTurn = RED;
        }
    }

    if(Winner(board,players[0]) == true){
        printf("%s cannot make any moves",players[1].name);
        printf("%s is the WINNER!!!!\n",players[0].name);
        printf("CONGRATS!!!!!\n");
        printf("GAME OVER.");
    }
    else if(Winner(board,players[1]) == true){
        printf("%s cannot make any more moves\n",players[0].name);
        printf("%s is the WINNER!!!!\n",players[1].name);
        printf("CONGRATS!!!!!\n");
        printf("GAME OVER.");
    }


    return 0;
}

