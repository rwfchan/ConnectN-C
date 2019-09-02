//
// Created by Raymond Chan on 11/13/17.
//

#ifndef CONNECTN_CONNECTN_H
#define CONNECTN_CONNECTN_H
  void get_input(int* num_rows, int* num_columns, int* number_of_piece_in_a_row_needed_to_win, int argc, char** argv);
  void check_if_positive(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win);
  char** make_broad(int num_rows, int num_columns);
  void free_array(int rows, char ***array);
  void print_broad(int num_rows, int num_columns, char** broad);
  void player_1_move(int num_rows, int num_columns, char** broad, int* whose_turn);
  void player_2_move(int num_rows, int num_columns, char** broad, int* whose_turn);
  bool is_win_or_tie(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad, int whose_turn);
  bool straight(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad);
  bool column(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad);
  bool diagonal(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad);
  bool diagonal_left(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad);
  bool diagonal_right(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad);
  bool isVaildFormat(int num_args_wanted,int num_args_needed);
  void game_over(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad, int whose_turn);
#endif //CONNECTN_CONNECTN_H
