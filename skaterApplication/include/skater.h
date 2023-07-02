#ifndef SKATER_H
#define SKATER_H

#define MAX_LENGTH_NAME 20
#define MAX_NUMBER_SKATERS 100

#include <stdbool.h>

typedef struct
{
    char first_name[MAX_LENGTH_NAME];
    int age;
    int score;

} Skater;

bool update_score_by_name(Skater* skaters, int number_of_skaters, char first_name[], int new_score);
bool search_winner(Skater* skaters, int number_of_skaters, Skater* winner);
bool find_youngest_performer(Skater* skaters, int number_of_skaters, Skater* youngest_performer);

#endif