//
// Created by Edmond on 24/04/2020.
//

#include "game_movement.h"
#include "input_output.h"
#include "game_init.h"
#include "keptPiece_movement.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void movement(square board[BOARD_SIZE][BOARD_SIZE],player *myPlayer) {//this function will allow each player to make a move once its their turn
    int row, column;

    //asking the player to enter the row and column the would like to choose to move
    printf("Enter Row(0-7): \n");
    scanf("%d", &row);
    printf("Enter Column(0-7): \n");
    scanf("%d", &column);
    printf("\n");

//setting conditions for when a piece selected isn't valid
    while ((board[row][column].stack == NULL) || (board[row][column].stack->p_color != myPlayer->player_color)||(board[row][column].type == INVALID)){
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
        printf("You cannot make that move!!\n");
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
    //this deals with movements in a negative direction
    if(row_check<0){
        row_check=row_check*-1;
    }
    if(column_check<0){
        column_check =column_check*-1;
    }
    return row_check + column_check;//returns the differences added together so value of the moves is gotten

}

void stacking_pieces(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,int new_row,int new_column,player *myPlayer) {//this function deals with stacking pieces once they have been moved on top of each other

    piece *top = board[row][column].stack;//pointer will equal the stack we have chosen
    board[row][column].stack = NULL;
    board[row][column].num_pieces=0;

    piece *curr = top;//pointer curr will equal stack that we would like to move to
    while (curr->next != NULL) {//loop that will join one stack to the other
        curr = curr->next;
    }
    curr->next = board[new_row][new_column].stack;
    board[new_row][new_column].stack = top;//top will finally equal the new stack

    board[new_row][new_column].num_pieces=0;
    curr = board[new_row][new_column].stack;
    while(curr!=NULL){
        board[new_row][new_column].num_pieces++;//the number of pieces in the position moved to is incremented
        curr= curr->next;
    }
//check for when a stack is over 5
    int count=1;
    curr=board[new_row][new_column].stack;
    piece *last = NULL;

    while(curr!=NULL){
        if(count<5){//this will just increase the number in the stack and change the top piece
            curr=curr->next;
            board[new_row][new_column].num_pieces = count;
            count++;
        }else{
            last= curr;
            curr = curr ->next;
            board[new_row][new_column].num_pieces = 5;
//removes the excess piece in the stack and either makes it a kept piece or a captured piece
                while(curr!=NULL){
                    piece *toRemove = curr;
                    curr = curr->next;
                    color removed_piece = toRemove->p_color;
                    free(toRemove);//frees up the space of the piece being removed
                    if(myPlayer->player_color == removed_piece) {
                        myPlayer->kept_pieces++;
                    }
                    else {
                        myPlayer->captured_pieces++;
                    }
                }
                last->next = NULL;
            }
        }
    printf("You have %d kept pieces.\n",myPlayer->kept_pieces);
    printf("You have %d captured pieces.\n",myPlayer->captured_pieces);
}




void turns(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],color playerTurn){//this function controls the logic behind each players turns and the options they have on each turn

    if(playerTurn == RED)
    {
        if(players[0].kept_pieces > 0){//if player 1 has a kept piece
            printf("You have %d kept pieces.\n",players[0].kept_pieces);

            if(boardPieces(board,&players[0]) == false ){//if the player has no pieces on the board and they must a kept piece
                printf("You have no pieces on the board and must choose from a kept piece.\n");
                kept(board,&players[0]);
                return;
            }

            printf("Would you like to use a kept pieces->(1 if yes and 2 if no): \n");//giving the player option if they would like to use their kept pieces or not
            int decision;
            scanf("%d",&decision);

            while(decision!=1 && decision!=2){
                printf("Please pick again: \n");
                scanf("%d",&decision);
            }
            if(decision == 1){//if they choose to use the kept piece
                kept(board,&players[0]);

            }else{//if they don't choose to use the kept piece
                movement(board,&players[0]);
            }

        }//if they don't have any pieces the game continues as normal
        else{
            printf("You have 0 kept pieces\n");
            movement(board, &players[0]);
        }//game switches to player 2's turn
        playerTurn = GREEN;
        printf("%s's turn to play now\n",players[1].name);
    }
    else if(playerTurn == GREEN)//the same logic is used when its player 2's turn to play the game,then it switches back to player 1's turn
    {
        if(players[1].kept_pieces > 0)
        {
            printf("You have %d kept pieces.\n", players[1].kept_pieces);

            if (boardPieces(board, &players[1]) == false) {
                printf("You have no pieces on the board and must choose from a kept piece.\n");
                kept(board, &players[1]);
                return;
            }

            printf("Would you like to use a kept pieces->(1 if yes and 2 if no): \n");
            int decision;
            scanf("%d", &decision);


            while (decision != 1 && decision != 2) {
                printf("Please pick again: \n");
                scanf("%d", &decision);
            }
            if (decision == 1) {
                kept(board, &players[1]);
            } else {
                movement(board, &players[1]);
            }
        }
        else{
            printf("You have 0 kept pieces\n");
            movement(board, &players[1]);
        }
        playerTurn = RED;
        printf("%s's turn to play now\n",players[0].name);
    }
}

bool boardPieces(square board[BOARD_SIZE][BOARD_SIZE],player *myPlayer){//this is a function that checks if a player has any pieces on the board
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j].stack != NULL && board[i][j].type == VALID){
                if(board[i][j].stack->p_color == myPlayer->player_color){
                    return true;
                }
            }
        }
    }
    return false;

}
