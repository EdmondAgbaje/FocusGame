//
// Created by Edmond on 03/04/2020.
//

#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>

void gameRules(){
    printf("Welcome to the Focus Game!!!\n---------------------------\nHere is how to play this 2-player game:\nEach player has 18 pieces each.The objective of the game is to make moves and capture pieces in a manner that leaves\n your opponent with no pieces\n");
    printf("You select piece/stack you want to move.You can only move a piece that's your own color or a stack with your color as\n the top piece.\n");
    printf("You can only move UP,DOWN,LEFT or RIGHT.You can a stack to a number of positions based on the size of the stack.\n");
    printf("The number that appears on the board indicates the number of pieces at that position while the letter indicates what the top piece is\n");
    printf("Once stack is over 5 pieces,pieces from bottom are kept by the current player as either captured opponent pieces or\nreserved pieces that can re-enter the game\n");
    printf("Okay these are the rules.LETS PLAY!!\n\n");
}



void initialize_players(player players[PLAYERS_NUM]) {//function initialises all the aspects to begin the game
    int i,j;
    players[0].player_color = RED;//this initialises player 1 as red
    players[1].player_color = GREEN;//this initialises player 2 as green


    for(i=0;i<2;i++){
        players[i].captured_pieces = 0;//zero pieces have been captured
        players[i].kept_pieces = 0;//zero pieces have been kept as the game is only beginning and all pieces are on the board
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
    printf("%s will go first to start the game\n",players[0].name);//player 1 will start the game
    printf("\n");

}
//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
void set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s){
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