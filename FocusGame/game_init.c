//
// Created by Edmond on 03/04/2020.
//

#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void initialize_players(player players[PLAYERS_NUM]) {//function initialises all the aspects to begin the game
    int i,j;
    players[0].player_color = RED;//this initialises player 1 as red
    players[1].player_color = GREEN;//this initialises player 2 as green

    for(i=0;i<2;i++){
        players[i].total = 18;//Each player starts off the game with 18 pieces
        players[i].captured_pieces = 0;//zero pieces have been captured
        players[i].kept_pieces = 0;//zero pieces have been kept as the game is only beginning and all pieces are on the board
        players[i].winner = false;//winner is set to false as nobody has won yet
        printf("PLAYER %d\nEnter name:",i+1);
        fgets(players[i].name,29,stdin);//use fgets to enter name of players
        printf("\n");

        for(j=0;players[i].name[j]!='\0';j++) {//this loop runs through the string and changes the newline to a null terminator
            if (players[i].name[j] == '\n')
                players[i].name[j] = '\0';
        }
    }
    printf("%s is RED,\n%s is GREEN\n",players[0].name,players[1].name);
    printf("\n");
    printf("%s will go first to start the game\n",players[0].name);
    printf("\n");

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