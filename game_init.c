//
// Created by Edmond on 03/04/2020.
//

#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>



void initialize_players(player players[PLAYERS_NUM]){

    // implement here the functionality to initialize the players
    player One;
    player Two;

    int playerNUMBER;
    printf("Enter 1 for player One to be RED and player Two to be Green\n or 2 for player One to be GREEN and player Two to be RED: \n");
    scanf("%d",&playerNUMBER);

    if(playerNUMBER==1){
        One.player_color = RED;
        Two.player_color = GREEN;
    }
    if(playerNUMBER==2){
        One.player_color = GREEN;
        Two.player_color = RED;
    }
    if(playerNUMBER!=1 && playerNUMBER!=2){
        printf("Invalid number entered");
        exit(-1);
    }

}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //invalid squares
            if ((i == 0 && (j == 0 || j == 1 || j == 6 || j == 7)) ||
                (i == 1 && (j == 0 || j == 7)) ||
                (i == 6 && (j == 0 || j == 7)) ||
                (i == 7 && (j == 0 || j == 1 || j == 6 || j == 7)))
                set_invalid(&board[i][j]);

            else {
                //squares with no pieces
                if (i == 0 || i == 7 || j == 0 || j == 7)
                    set_empty(&board[i][j]);
                else {
                    //squares with red pieces
                    if ((i % 2 == 1 && (j < 3 || j > 4)) ||
                        (i % 2 == 0 && (j == 3 || j == 4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }


    }


}