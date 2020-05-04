//
// Created by Edmond on 03/04/2020.
//

#include "input_output.h"
#include <stdio.h>


/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    printf("---------------------------------\n");
    printf("| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");//showing players what each number equals on the board
    printf("---------------------------------\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("|%dG ",board[i][j].num_pieces);
                    else printf("|%dR ",board[i][j].num_pieces);
                }
            }
            else
                printf("| - ");
        }
        printf("|\n");
    }
    printf("\n");
}

