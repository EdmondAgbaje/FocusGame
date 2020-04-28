//
// Created by Edmond on 24/04/2020.
//

#include "game_movement.h"
#include "game_init.h"
#include "input_output.h"
#include <stdio.h>


void turns(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM]) {//this function will allow each player to make a move once its their turn
    int row, column;
    /*color playerTurn = RED;
    if(playerTurn == GREEN){
        playerTurn = GREEN;
        printf("%s's turn to play now",players[1].name);
    } else{
        printf("%s's turn to play now"),players[0].name);
    }*/

    //asking the player to enter the row and column the would like to choose to move
    printf("Enter Row(0-7)(0 is equivalent to row and 7 is equivalent to row 8): ");
    scanf("%d", &row);
    printf("Enter Column(0-7)(0 is equivalent to column and 7 is equivalent to column 8): ");
    scanf("%d", &column);
    printf("\n");

//setting conditions for when a piece selected isn't valid
    while ((board[row][column].stack == NULL) || (board[row][column].stack->p_color != players[0].player_color) ||
           (board[row][column].stack->p_color != players[1].player_color) || (board[row][column].type == INVALID) {
        row = 0;
        column = 0;
        //if invalid piece is chosen the row and column are reset and player is asked to re-select a piece
        printf("The chosen piece is invalid\n");
        printf("Re-Enter row(0-7):");
        scanf("%d", &row);
        printf("Re-Enter column(0-7):"):
        scanf("%d", &column);
    }

    int moveNum;
    printf("You allowed to move maximum of %d squares\n",board[row][column].num_pieces);//this will tell player the maximum amount of moves they can make for that turn
    int moveNum;
    printf("Select the amount of moves you would like to make: ");//player chooses number of moves they'd like to make
    scanf("%d", &moveNum);

    if((moveNum >board[row][column].num_pieces)||(moveNum <= 0)){//if an invalid number of moves is selected player is asked to re-enter
        printf("You cannot make that amount of moves.Please select again: ");
        scanf("%d",&moveNum);
    }
    //ask player for co-ordinates of the position they would like to move to
    int new_row,new_column;
    printf("Enter Row you would like to move to(0-7): ");
    scanf("%d",&new_row);
    printf("Enter Column you would like to move to(0-7): ");
    scanf("&d",&new_column);

    //if the number of moves allowed is less than the amount of moves you're allowed to make,player will be asked to re-enter where they would like to move to
    while(movement_checker(row,column,new_row,new_column)>board[row][column].num_pieces){
        printf("Re-Enter Row you would like to move to(0-7): ");
        scanf("%d",&new_row);
        printf("Re-Enter Column you would like to move to(0-7): ");
        scanf("%d",&new_column);
    }
    stacking_pieces()

}

/*void moving_pieces(square board[BOARD_SIZE][BOARD_SIZE],int row,int column){
    int moveNum;
    printf("You allowed to move maximum of %d squares\n",board[row][column].num_pieces);
    printf("Select the amount of moves you would like to make: ");
    scanf("%d",&moveNum);

    if((moveNum >board[row][column].num_pieces)||(moveNum <= 0)){
        printf("You cannot make that amount of moves.Please select again: ");
        scanf("%d",&moveNum);
    }
}*/
int movement_checker(int row,int column,int new_row,int new_column){//this is a function that will calculate the difference between the current position and the position you would like to move to
    int row_check = row -new_row;
    int column_check = column -new_column;

    return row_check + column_check;//returns the differences added together so value of the moves is gotten

}

void stacking_pieces(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,int new_row,int new_column,player players[PLAYERS_NUM]){//this function deals with stacking pieces once they have been moved on top of each other
    piece *top = board[row][column].stack;//pointer will equal the stack we have chosen
    board[row][column].stack=NULL;

    piece *curr = board[new_row][new_column].stack;//pointer curr will equal stack that we would like to move to
    while(curr->next != NULL){//loop that will join one stack to the other
        curr = curr->next;
        curr->next = board[new_row][new_column].stack;
        board[new_row][new_column].stack=top;//top will finally equal the new stack
    }

}