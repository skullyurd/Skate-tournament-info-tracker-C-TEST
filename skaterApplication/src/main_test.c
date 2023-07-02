#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "unity.h"
#include "skater.h"

#define MAX_NUMBER_SKATERS 100
/*
 * TO DO : 
 *  - Uncomment the declaration of a global array of Skater structures
 * 	- Initialize the global array with the test data provided in the test description
 *  - Uncomment the declaration of a global variable representating the actual number of skaters in the array
 */
 Skater skaters[MAX_NUMBER_SKATERS]; 
 int number_of_skaters = 5;

void setUp(void)
{
    skaters[0].age = 22;
    skaters[0].score = 378;
    strcpy(skaters[0].first_name, "Anna");

    skaters[1].age = 34;
    skaters[1].score = 420;
    strcpy(skaters[1].first_name, "John");

    skaters[2].age = 17;
    skaters[2].score = 280;
    strcpy(skaters[2].first_name, "Lucas");

    skaters[3].age = 28;
    skaters[3].score = 325;
    strcpy(skaters[3].first_name, "Mark");

    skaters[4].age = 17;
    skaters[4].score = 354;
    strcpy(skaters[4].first_name, "Rose");
}

void tearDown(void)
{
    //optional
}

void test_update_score_by_name_Case1()
{
    // Arrange
    setUp();
	int input_test_number_of_skaters = number_of_skaters;
    char input_test_first_name[] = "Mark";
    int input_test_new_score = 320;
	
	// Act
	bool actual_result = update_score_by_name(skaters, input_test_number_of_skaters, input_test_first_name, input_test_new_score);
	
	// Asser
	TEST_ASSERT_TRUE(actual_result);
    TEST_ASSERT_EQUAL_INT(input_test_new_score, skaters[3].score);}

void test_update_score_by_name_Case2()
{
    // Arrange
    setUp();
    int input_test_number_of_skaters = number_of_skaters;
    char input_test_first_name[] = "Baris";
    int input_test_new_score = 15;
	
	// Act
	bool actual_result = update_score_by_name(skaters, input_test_number_of_skaters, input_test_first_name, input_test_new_score);
	
	// Assert
	TEST_ASSERT_FALSE(actual_result);
}

void test_search_winner_case1()
{
    //Arrange
    setUp();
    int input_test_number_of_skaters = number_of_skaters;
    Skater winner;

    //act
    bool actual_result = search_winner(skaters, input_test_number_of_skaters, &winner);
    //assert
    TEST_ASSERT_TRUE(actual_result);
    TEST_ASSERT_EQUAL_MEMORY(&skaters[1], &winner, sizeof(Skater));
}

void test_search_winner_case2()
{
    //Arrange
    int input_test_number_of_skaters = number_of_skaters;
    Skater winner;

    //act
    bool actual_result = search_winner(NULL, input_test_number_of_skaters, &winner);

    //assert
    TEST_ASSERT_FALSE(actual_result);

}

void test_find_youngest_performer_case()
{
    //Arrange
    setUp();
    int input_test_number_of_skaters = number_of_skaters;
    Skater youngest_performer;

    //act
    bool actual_result = find_youngest_performer(skaters, input_test_number_of_skaters, &youngest_performer);

    //assert
    TEST_ASSERT_TRUE(actual_result);
    TEST_ASSERT_EQUAL_MEMORY(&skaters[4], &youngest_performer, sizeof(Skater));
}

int main(void)
{
    UnityBegin(0);

    RUN_TEST(test_update_score_by_name_Case1);
    RUN_TEST(test_update_score_by_name_Case2);
    RUN_TEST(test_search_winner_case1);
    RUN_TEST(test_search_winner_case2);
    RUN_TEST(test_find_youngest_performer_case);

    return UnityEnd();
}
