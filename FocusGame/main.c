#include <stdio.h>

#include "input_output.h"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);

   // while(1!=2) {
       // player *playerPtr = &players[0];

       // if ((playerPtr->player_color) == RED){
         //   playerPtr==players[1];
         //   printf("%s goes first\n",players[0].name);
      //  }
  //  }


    return 0;
}

