//
// Created by Raymond Chan on 11/13/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "connectn.h"

void get_input(int* num_rows, int* num_columns, int* number_of_piece_in_a_row_needed_to_win, int argc, char** argv) {

  if(argc < 4) {
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns ");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }
  if(argc > 4){
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns ");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }

  sscanf(argv[1], "%d", num_rows);
  sscanf(argv[2], "%d", num_columns);
  sscanf(argv[3], "%d", number_of_piece_in_a_row_needed_to_win);

}

void check_if_positive(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win){
  if(num_rows <= 0 || num_columns <= 0 || number_of_piece_in_a_row_needed_to_win <= 0){
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns ");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }

}

bool isVaildFormat(int num_args_wanted, int num_args_needed) {
  bool format_is_good = num_args_wanted == num_args_needed;

  char character;

  do{
    scanf("%c",&character);
    if(!isspace(character)){
      format_is_good = false;
    }
  }while(character != '\n');

  return format_is_good;
}

char** make_broad(int num_rows, int num_columns) {
  int rows = num_rows + 1;
  int cols = num_columns + 1;
  char** arr = (char**) malloc(rows * sizeof(char*));
  for(int i = 0; i < rows; i++){
    arr[i] = (char*) malloc(cols * sizeof(char));
    for(int j = 0; j < cols; j++){
      if(i == rows - 1){
        arr[i][j] = ' ';
      }else if(j == 0) {
        arr[i][j] = ' ';
      }else{
        arr[i][j] = '*';
      }
    }
  }
  return arr;
}

void print_broad(int num_rows, int num_columns, char** broad){
  int rows = num_rows + 1;
  int cols = num_columns + 1;
  int x = num_rows - 1;
  int y = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(i == rows - 1){
        if(j == 0){
          printf("%c ", broad[i][j]);
        }else{
          printf("%d ", y);
          y++;
        }
      }else if(j == 0) {
        printf("%d ", x);
        x--;
      }else{
        printf("%c ", broad[i][j]);
      }
    }
    printf("\n");
  }
}

void player_1_move(int num_rows, int num_columns, char** broad, int* whose_turn) {
  int move;
  int x = num_rows - 1;
  const int argu_needed = 1;
  int argu_have;

  do {
    printf("Enter a column between 0 and %d to play in: ", num_columns - 1);
    argu_have = scanf(" %d", &move);
  }while(!isVaildFormat(argu_needed, argu_have) || move < 0 || move > num_columns - 1);

  move++;

  while(broad[x][move] != '*'){
    if(x == 0){
      return;
    }else {
      x--;
    }
  }
  broad[x][move] = 'X';

  print_broad(num_rows, num_columns, broad);
  *whose_turn = 0;
}

void player_2_move(int num_rows, int num_columns, char** broad, int* whose_turn) {
  int move;
  int x = num_rows - 1;
  const int argu_needed = 1;
  int argu_have;

  do {
    printf("Enter a column between 0 and %d to play in: ", num_columns - 1);
    argu_have = scanf(" %d", &move);
  }while(!isVaildFormat(argu_needed, argu_have) || move < 0 || move > num_columns - 1);

  move++;

  while(broad[x][move] != '*'){
    if(x == 0){
      return;
    }else {
      x--;
    }
  }
  broad[x][move] = 'O';

  print_broad(num_rows, num_columns, broad);
  *whose_turn = 1;
}

bool is_win_or_tie(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad, int whose_turn) {
  int i = 0;

  if((straight(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad) || column(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad) || diagonal(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad)) && whose_turn == 0){
    printf("Player 1 Won!\n");
    return true;
  }else if((straight(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad) || column(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad) || diagonal(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad)) && whose_turn == 1){
    printf("Player 2 Won!\n");
    return true;
  }

  while(broad[0][i] != '*'){
    if(i == num_columns){
      printf("Tie game!\n");
      return true;
    }else {
      i++;
    }
  }

  return false;
}

bool straight(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad) {
  int win_counter = 1;

  for(int i = 0; i < num_rows; i++){
    win_counter = 1;
    for(int j = 1; j < num_columns; j++){
      if(broad[i][j] == '*'){
        continue;
      }
      if(broad[i][j] != broad[i][j + 1]){
        win_counter = 1;
        continue;
      }
      win_counter++;
      if(win_counter == number_of_piece_in_a_row_needed_to_win){
        return true;
      }
    }
  }
  return false;
}
bool column(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad) {
  int win_counter = 1;

  for(int j = 1; j <= num_columns; j++){
    win_counter = 1;
    for(int i = 0; i < num_rows; i++){
      if(broad[i][j] == '*'){
        continue;
      }
      if(broad[i][j] != broad[i + 1][j]){
        win_counter = 1;
        continue;
      }
      win_counter++;
      if(win_counter == number_of_piece_in_a_row_needed_to_win){
        return true;
      }
    }
  }
  return false;
}

bool diagonal(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad) {
  if(diagonal_left(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad)||diagonal_right(num_rows, num_columns, number_of_piece_in_a_row_needed_to_win, broad)){
    return true;
  }
  return false;
}

bool diagonal_left(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad) {
  int win_counter = 1;

  for(int i = 0; i < num_rows; i++){
    for(int j = 1; j < num_columns; j++){
      if(broad[i][j] == '*'){
        continue;
      }
      if(broad[i][j] != broad[i + 1][j + 1]){
        break;
      }
      int k = i;
      int l = j;
      win_counter = 1;
      while(broad[k][l] == broad[k + 1][l + 1]){
        k++;
        l++;
        win_counter++;
        if(win_counter == number_of_piece_in_a_row_needed_to_win){
          return true;
        }
        if(l + 1 > num_columns){
          break;
        }
      }
    }
  }

  return false;
}
bool diagonal_right(int num_rows, int num_columns, int number_of_piece_in_a_row_needed_to_win, char** broad) {
  int win_counter = 1;

  for(int i = 0; i < num_rows; i++){
    for(int j = num_columns; j > 1; j--){
      if(broad[i][j] == '*'){
        continue;
      }
      if(broad[i][j] != broad[i + 1][j - 1]){
        break;
      }
      int k = i;
      int l = j;
      win_counter = 1;
      while(broad[k][l] == broad[k + 1][l - 1]){
        k++;
        l--;
        win_counter++;
        if(win_counter == number_of_piece_in_a_row_needed_to_win){
          return true;
        }
        if(l - 1 <= 0){
          break;
        }
      }
    }
  }
  return false;
}

void free_array(int rows, char ***array) {
  for(int i = 0; i < rows; i++){
    free((*array)[i]);
  }
  free(*array);
  *array = NULL;
}
