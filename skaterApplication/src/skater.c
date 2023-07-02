#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "skater.h"

bool update_score_by_name(Skater* skaters, int number_of_skaters, char first_name[], int new_score)
{
    if(skaters == NULL || number_of_skaters <= 0 || first_name == NULL || new_score < 0)
    {
        printf("Invalid input\n");
        return false;
    }
    for(int i = 0; i < number_of_skaters; i++)
    {
        if(strcmp(skaters[i].first_name, first_name) == 0)
        {
            printf("Found skater %s\n", first_name);
            printf("Old score: %d\n", skaters[i].score);
            skaters[i].score = new_score;printf("New score: %d\n", skaters[i].score);
            return true;
        }
    }
    printf("Skater %s not found\n", first_name);
return false;
}

bool search_winner(Skater* skaters, int number_of_skaters, Skater* winner)
{
    if(skaters == NULL || number_of_skaters <= 0 || winner == NULL)
    {
        printf("Invalid input\n");
        return false;
    }
    Skater* current_winner = skaters;
    for(int i = 0; i < number_of_skaters; i++)
    {
        if(skaters[i].score > current_winner->score)
        {
            current_winner = &skaters[i];
        }
    }
    *winner = *current_winner;
    printf("Winner is %s\n", winner->first_name);
    return true;
}

bool find_youngest_performer(Skater* skaters, int number_of_skaters, Skater* youngest_performer)
{
    if(skaters == NULL || number_of_skaters <= 0 || youngest_performer == NULL)
    {
        printf("Invalid input\n");
        return false;
    }
    Skater* current_youngest_performer = skaters;
    for(int i = 0; i < number_of_skaters; i++)
    {
        if(skaters[i].age < current_youngest_performer->age)
        {
            current_youngest_performer = &skaters[i];
        }
        else if(skaters[i].age == current_youngest_performer->age)
        {
            if(skaters[i].score > current_youngest_performer->score)
            {
                current_youngest_performer = &skaters[i];
            }
        }
    }
    *youngest_performer = *current_youngest_performer;
    printf("Youngest performer is %s with a score of %d\n", youngest_performer->first_name, youngest_performer->score);
    return true;
}