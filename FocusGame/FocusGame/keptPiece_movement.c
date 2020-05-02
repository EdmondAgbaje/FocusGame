//
// Created by Edmond on 02/05/2020.
//

#include "keptPiece_movement.h"
#include "game_movement.h"
#include "input_output.h"
#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>

void kept(square board[BOARD_SIZE][BOARD_SIZE],player myPlayer){
    int row;
    int column;

    printf("Enter row you would like to move the kept piece to(0-7): \n");
    scanf("%d",&row);
    printf("Enter column you would like to move the kept piece to(0-7): \n");
    scanf("%d",&column);

    while(board[row][column].type == INVALID){
        row = 0;
        column = 0;
        printf("The chosen piece is invalid\n");
        printf("Re-Enter row(0-7): \n");
        scanf("%d", &row);
        printf("Re-Enter column(0-7): \n");
        scanf("%d", &column);
    }
    keptPiece_stacking(board,row,column,myPlayer);
    print_board(board);
    myPlayer.kept_pieces--;
    printf("You now have %d kept pieces.\n",myPlayer.kept_pieces);
}

void keptPiece_stacking(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,player myPlayer){

    piece *top = board[row][column].stack;
    board[row][column].num_pieces = 0;

    piece *added_piece = (piece *)malloc(sizeof(piece));
    added_piece->p_color = myPlayer.player_color;
    added_piece->next = top;
    board[row][column].stack = added_piece;

    square *new_position = &board[row][column];
    new_position->num_pieces = 0;
    piece *curr = new_position->stack;
    while(curr!=NULL){
        new_position->num_pieces++;
        curr = curr->next;
    }

    int count = 1;
    curr = new_position->stack;
    piece *last = NULL;
    while(curr!=NULL){
        if(count < 5){
            curr = curr->next;
            count++;
        }else{
            last = curr;
            curr = curr->next;

            while(curr!=NULL){
                piece *toRemove = curr;
                curr = curr->next;
                color removed_piece = toRemove->p_color;
                free(toRemove);//frees up the space of the piece being removed
                new_position->num_pieces--;
                if(myPlayer.player_color == removed_piece){
                    myPlayer.kept_pieces++;
                }else{
                    myPlayer.captured_pieces++;
                }
                last->next = NULL;
            }
        }
    }
    printf("You have %d kept pieces.\n",myPlayer.kept_pieces);
    printf("You have %d captured pieces.\n",myPlayer.captured_pieces);
}