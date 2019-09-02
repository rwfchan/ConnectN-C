#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "connectn.h"

int main(int argc, char** argv) {
  int num_rows;
  int num_columns;
  int number_of_piece_in_a_row_needed_to_win;

  get_input(&num_rows, &num_columns, &number_of_piece_in_a_row_needed_to_win, argc, argv);
  check_if_positive(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win);

  char** broad = make_broad(num_rows, num_columns);
  int whose_turn = 1;

  print_broad(num_rows, num_columns, broad);

  game_over(num_rows,num_columns, number_of_piece_in_a_row_needed_to_win, broad, whose_turn);

  free_array(num_rows, &broad);
}
void game_over(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad, int whose_turn) {
  while(!is_win_or_tie(num_rows,num_columns, number_of_piece_in_a_row_needed_to_win, broad, whose_turn)) {
    if(whose_turn == 1){
      player_1_move(num_rows,num_columns, broad, &whose_turn);
    }else if(whose_turn == 0){
      player_2_move(num_rows,num_columns, broad, &whose_turn);
    }
  }
}