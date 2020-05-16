/******************************************************************************
 * Description: This program is a variation of the card game known as 21. The 
 *              random number generator, generate two integers that will 
 *              represent the first two cards drawn from a standard deck of 52 
 *              cards. There is a player will now compete against the dealer,
 *              and there is no limit to the number of cards that can be drawn.
 *              Once the player completes their hand, the dealer will initiate 
 *              their hand assuming the player did not bust. The dealer wins
 *              and loses according to the rules as well.
 * Programmers: Sohan Pramanik   pramanis@purdue.edu
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void getInput(int *seed);
void getSuit(int card, int drawNO);
int getLess16(int score, int *score_ace, int *aceNO, int drawNO);
void tell_result(int score_ace, int score_ace_1);
void getCard(int score, int score_1, int *score_ace, int *score_ace_1, int aceNO, int aceNO_1, int drawNO, int drawNO_1);

int main()
{
  int seed; // random seed generator
  int score = 0; // score without ace consideration for player
  int score_ace = 0; // score with ace consideration for player
  int aceNO = 0; // tell whether ace exist or not for player
  int drawNO = 1; // tell how many times card is drawn for player

  int score_1 = 0; // score without ace consideration for dealer
  int score_ace_1 = 0; // score with ace consideration for dealer
  int aceNO_1 = 0; // tell whether ace exist or not for dealer
  int drawNO_1 = 1; // tells how many times card is drawn for dealer

  // function call for seed 
  getInput(&seed);

  // function call for getting card for dealer and player
  getCard(score, score_1, &score_ace, &score_ace_1, aceNO, aceNO_1, drawNO, drawNO_1);

  // function call for getting score
  tell_result(score_ace, score_ace_1);

  return 0;
}

/******************************************************************************
 * Function:    getInput
 * Description: Creates a random seed generator from user inputted values.
 * Parameters:  seed, int, user inputted seed value
 * Return:      NA
 ******************************************************************************/
void getInput(int *seed)
{
  // gets random seed
  printf("Enter the seed value -> ");
  scanf("%d", seed);
  printf("\n");
  srand(*seed);

  return;
}

/******************************************************************************
 * Function:    getCard
 * Description: Gets the cards for the dealer and the player, and prints out their scores.
 * Parameters:  score, int, score without ace consideration for player
 *              score_1, int, score without ace consideraton for dealer
 *              score_ace, int, score with ace consideration for player
 *              score_ace_1, int, score with ace consideration for dealer
 *              aceNO, int, tell whether ace exist or not for player
 *              aceNO_1, int, tell whether ace exist or not for dealer
 *              drawNO, int, tell how many times card is drawn for player
 *              drawNO_1, int, tells how many times card is drawn for dealer
 * Return:      NA
 ******************************************************************************/
void getCard(int score, int score_1, int *score_ace, int *score_ace_1, int aceNO, int aceNO_1, int drawNO, int drawNO_1)
{
  int score_ace_0 = 0; // sets a new variable for score_ace inside function
  int score_ace_1_0 = 0; // sets a new variable for score_ace_1 inside function

  // gets player's score
  while (score_ace_0 < 16)
  {
    score = getLess16(score, &score_ace_0, &aceNO, drawNO);
    drawNO = drawNO + 1;
  }

  printf("Player's Score: %d\n", score_ace_0);

  if (score_ace_0 <= 21)
  {
    // gets dealer's score
    printf("\n");
    while (score_ace_1_0 < 16)
    {
      score_1 = getLess16(score_1, &score_ace_1_0, &aceNO_1, drawNO_1);
      drawNO_1 = drawNO_1 + 1;
    }

    printf("Dealer's Score: %d\n", score_ace_1_0);
  }

  // makes sure the variables are getting replaced
  *score_ace = score_ace_0;
  *score_ace_1 = score_ace_1_0;

  return;
}

/******************************************************************************
 * Function:    getSuit
 * Description: Gets the corresponding suit and number of the card.
 * Parameters:  card, int, the corresponding suit and number of the card
 *              drawNO, int, tells how many times card is drawn for player
 * Return:      NA
 ******************************************************************************/
void getSuit(int card, int drawNO)
{
  printf("Card #%d: ", drawNO);
  switch (card % 13)
  {
    // gets the number of the corresponding card
    case 1: printf("Ace of ");
            break;
    case 2: printf("2 of ");
            break;
    case 3: printf("3 of ");
            break;
    case 4: printf("4 of ");
            break;
    case 5: printf("5 of ");
            break;
    case 6: printf("6 of ");
            break;
    case 7: printf("7 of ");
            break;
    case 8: printf("8 of ");
            break;
    case 9: printf("9 of ");
            break;
    case 10: printf("10 of ");
             break;
    case 11: printf("Jack of ");
             break;
    case 12: printf("Queen of ");
             break;
    case 0: printf("King of ");
            break;
  }

  // gets the type of the corresponding card
  if (card <= 13)
  {
    printf("Clubs\n");
  }
  else if (card <= 26)
  {
    printf("Diamonds\n");
  }
  else if (card <= 39)
  {
    printf("Hearts\n");
  }
  else
  {
    printf("Spades\n");
  }

  return;
}

/******************************************************************************
 * Function:    getLess16
 * Description: Calculates the total score. If the score is less than 16, it
 *              will take another card and loop again. Finds also the number of
 *              random, and calculates score of ace as well.
 * Parameters:  score, int, total score without ace consideration
 *              score_ace, int, total score with ace consideration
 *              aceNO, int, tells whether ace exist or not
 *              drawNO, int, tells how many times card is drawn for player
 * Return:      score
 ******************************************************************************/
int getLess16(int score, int *score_ace, int *aceNO, int drawNO)
{
  // if score is less than 16

  int card; // the random card number generated

  // gets the random number 
  card = rand() % 52 + 1;

  // calls function to print out the card name
  getSuit(card, drawNO);

  // calculates the card score
  if ((card % 13) == 0)
  {
    card = 13;
  }
  else
  {
    card = card % 13;
  }

  if (card > 10)
  {
    card = 10;
  }

  score = card + score;

  // Tell whether an ace card exist or not
  if (card == 1)
  {
    *aceNO = 1;
  }

  // calculates score with ace consideration
  if (*aceNO)
  {
    if ((score + 10) < 22)
    {
      *score_ace = score + 10;
    }
    else
    {
      *score_ace = score;
    }
  }
  else
  {
    *score_ace = score;
  }

  return score;
}

/******************************************************************************
 * Function:    tell_result
 * Description: Using the calculated score, it tells the final result of what
 *              the dealer does.
 * Parameters:  score_ace, int, total score with ace consideration for player
 *              score_ace_1, int, total score with ace consideration for dealer
 * Return:      NA
 ******************************************************************************/
void tell_result(int score_ace, int score_ace_1)
{
  // tells what the dealer does
  if (score_ace > 21)
  {
    printf("\nDealer wins!\n");
  }
  else if (score_ace > score_ace_1)
  {
    printf("\nDealer loses!\n");
  }
  else if ((score_ace_1 == 21) || ((score_ace_1 >= score_ace) && (score_ace_1 < 21)))
  {
    printf("\nDealer wins!\n");
  }
  else if (score_ace_1 > 21)
  {
    printf("\nDealer busts.\n");
  }

  return;
}
