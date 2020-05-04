//
// Created by Edmond on 02/05/2020.
//

#include "keptPiece_movement.h"
#include "game_movement.h"
#include "input_output.h"
#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>

void kept(square board[BOARD_SIZE][BOARD_SIZE],player *myPlayer){//this function deals with the movement of kept pieces into the game
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
    myPlayer->kept_pieces--;
    printf("You now have %d kept pieces.\n",myPlayer->kept_pieces);
}

void keptPiece_stacking(square board[BOARD_SIZE][BOARD_SIZE],int row,int column,player *myPlayer){//this functions deals with stacking the of a kept piece brought back into the game

    piece *top = board[row][column].stack;//pointer equals the stack of the position to be moved to
    board[row][column].num_pieces = 0;

    piece *added_piece = (piece *)malloc(sizeof(piece));//this creates space in memory for the kept piece being added
    added_piece->p_color = myPlayer->player_color;//makes the new piece the players color
    added_piece->next = top;
    board[row][column].stack = added_piece;//the kept piece will then equal the stack of the new position being moved to

    square *new_position = &board[row][column];//new position points to the address of the position to be moved to
    new_position->num_pieces = 0;
    piece *curr = new_position->stack;//curr will now point to the stack at the new position
    while(curr!=NULL){
        new_position->num_pieces++;//the number of pieces in the position increases
        curr = curr->next;//curr points to the next position in the stack
    }

    //checks if the new stack is over 5
    int count = 1;
    curr = new_position->stack;
    piece *last = NULL;
    while(curr!=NULL){//this will just increase the number in the stack and change the top piece
        if(count < 5){
            curr = curr->next;
            count++;
        }else{
            last = curr;
            curr = curr->next;

            //removes the excess piece in the stack and either makes it a kept piece or a captured piece
            while(curr!=NULL){
                piece *toRemove = curr;
                curr = curr->next;
                color removed_piece = toRemove->p_color;
                free(toRemove);//frees up the space of the piece being removed
                new_position->num_pieces--;
                if(myPlayer->player_color == removed_piece)
                    myPlayer->kept_pieces++;
                else
                    myPlayer->captured_pieces++;
                }
                last->next = NULL;
            }
        }
    printf("You have %d kept pieces.\n",myPlayer->kept_pieces);
    printf("You have %d captured pieces.\n",myPlayer->captured_pieces);

}

