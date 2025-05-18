#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);

int main(void)
{
    char text[1000];

    // Prompt user for input
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Count letters, words, sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate L and S
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Output result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

// Count letters: A-Z and a-z
int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count words: assume separated by spaces
int count_words(const char *text)
{
    int count = 1; // Start at 1 assuming at least one word
    for (int i = 0; text[i]; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count sentences: end in '.', '!', or '?'
int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
