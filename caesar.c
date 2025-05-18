#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to print usage and exit
void print_usage_and_exit(void)
{
    printf("Usage: ./caesar key\n");
    exit(1);
}

// Caesar cipher main program
int main(int argc, char *argv[])
{
    // Check for exactly one command-line argument
    if (argc != 2)
    {
        print_usage_and_exit();
    }

    // Ensure key is a number
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            print_usage_and_exit();
        }
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);
    key = key % 26; // Ensure key is within alphabet range

    // Get plaintext input
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt plaintext
    char ciphertext[1000];
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            ciphertext[i] = ((c - 'A' + key) % 26) + 'A';
        }
        else if (islower(c))
        {
            ciphertext[i] = ((c - 'a' + key) % 26) + 'a';
        }
        else
        {
            ciphertext[i] = c; // Non-letter characters stay the same
        }
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';

    // Output ciphertext
    printf("ciphertext: %s", ciphertext);

    return 0;
}
