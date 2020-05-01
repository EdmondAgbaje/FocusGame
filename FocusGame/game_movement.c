//
// Created by Edmond on 24/04/2020.
//

#include "game_movement.h"
#include "input_output.h"
#include "game_init.h"
#include <stdio.h>


void turns(square board[BOARD_SIZE][BOARD_SIZE],player myPlayer) {//this function will allow each player to make a move once its their turn
    int row, column;

    //asking the player to enter the row and column the would like to choose to move
    printf("Enter Row(0-7): \n");
    scanf("%d", &row);
    printf("Enter Column(0-7): \n");
    scanf("%d", &column);
    printf("\n");

//setting conditions for when a piece selected isn't valid
    while ((board[row][column].stack == NULL) || (board[row][column].stack->p_color != myPlayer.player_color)||(board[row][column].type == INVALID)){
        row = 0;
        column = 0;
        //if invalid piece is chosen the row and column are reset and player is asked to re-select a piece
        printf("The chosen piece is invalid\n");
        printf("Re-Enter row(0-7): \n");
        scanf("%d", &row);
        printf("Re-Enter column(0-7): \n");
        scanf("%d", &column);
    }
    int moveNum;
    printf("You allowed to move maximum of %d squares\n",board[row][column].num_pieces);//this will tell player the maximum amount of moves they can make for that turn
    printf("Select the amount of moves you would like to make: \n");//player chooses number of moves they'd like to make
    scanf("%d", &moveNum);

    while((moveNum >board[row][column].num_pieces)||(moveNum <= 0)){//if an invalid number of moves is selected player is asked to re-enter
        printf("You cannot make that amount of moves.Please select again: \n");
        scanf("%d",&moveNum);
    }
    //ask player for co-ordinates of the position they would like to move to
    int new_row, new_column;
    printf("Enter Row you would like to move to(0-7): \n");
    scanf("%d",&new_row);
    printf("Enter Column you would like to move to(0-7): \n");
    scanf("%d",&new_column);

    //if the number of moves allowed is less than the amount of moves you're allowed to make,player will be asked to re-enter where they would like to move to
    while(movement_checker(row,column,new_row,new_column)>board[row][column].num_pieces){
        printf("Re-Enter Row you would like to move to(1-6): \n");
        scanf("%d",&new_row);
        printf("Re-Enter Column you would like to move to(1-6): \n");
        scanf("%d",&new_column);
    }
    stacking_pieces(board,row,column,new_row,new_column,myPlayer);
    print_board(board);
}

int movement_checker(int row,int column,int new_row,int new_column){//this is a function that will calculate the difference between the current position and the position you would like to move to

    int row_check = row -new_row;
    int column_check = column -new_column;
    if(row_check<0){
        row_check=row_check*-1;
    }
    if(column_check<0){
        column_check =column_check*-1;
    }
    return row_check + column_check;//returns the differences added together so value of the moves is gotten

}

void stacking_pieces(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,int new_row,int new_column,player myPlayer) {//this function deals with stacking pieces once they have been moved on top of each other

    piece *top = board[row][column].stack;//pointer will equal the stack we have chosen
    board[row][column].stack = NULL;

    piece *curr = top;//pointer curr will equal stack that we would like to move to
    while (curr->next != NULL) {//loop that will join one stack to the other
        curr = curr->next;
        curr->next = board[new_row][new_column].stack;
        board[new_row][new_column].stack = top;//top will finally equal the new stack
    }
}