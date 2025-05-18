#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
    5, 1, 3, 1, 1, 3,10, 1, 1, 1,
    1, 4, 4, 8, 4,10
};

// Function prototype
int compute_score(char word[]);

int main(void)
{
    char word1[100];
    char word2[100];

    // Prompting for input
    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    // Compute scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// Function to compute score of a word
int compute_score(char word[])
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i];
        if (isalpha(c))
        {
            c = toupper(c);                  // Convert to uppercase
            score += POINTS[c - 'A'];        // Get index in POINTS array
        }
    }
    return score;
}
