// Checking validation and owner of credit card number
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void valids(int cards, int *LENGTHS, string *VALIDATIONS, int * VALSCOREBEF, int *VALSCOREAFT);
void owners(int cards, int *LENGTHS, string *OWNERS, int all_num_len, int * OWNSCOREBEF, int *OWNSCOREAFT);
void show_datat(string *VALIDATIONS, string *OWNERS, int *VALSCOREBEF, int *VALSCOREAFT, int *OWNSCOREBEF, int *OWNSCOREAFT, long *NUMBERS, int all_num_len, int cards);

// Magic numbers
const int thirteenth = 13;
const int fifteenth = 15;
const int sixteenth = 16;

int main(void)
{
    int cards = 0;
    while (cards <= 0)
    {
        cards = get_int("How many cards do you wanna check: ");
    }

    // System arrays
    long NUMBERS[cards];
    int LENGTHS[cards];
    string OWNERS[cards];
    string VALIDATIONS[cards];

    // For show data
    int VALSCOREBEF[(cards) * 2 - 2];
    int VALSCOREAFT[(cards) * 2 - 2];
    int OWNSCOREBEF[(cards) * 2 - 2];
    int OWNSCOREAFT[(cards) * 2 - 2];



    for (int sycle = 0; sycle < cards; sycle++)
    {
        long card_num = 0;
        while (card_num <= 0)
        {
            card_num = get_long("Enter %i credit card number: ", sycle);
        }

        // Luhn's algorithm variables
        int card_num_len = floor(log10(labs(card_num))) + 1;
        int current_num_digit = 0;
        int current_digit_pos = 0;
        int sum = 0;
        char checker = 0;
        const int solid_len = card_num_len;
        LENGTHS[sycle] = card_num_len;

        // Is card length is valid
        if (card_num_len == thirteenth || card_num_len == fifteenth || card_num_len == sixteenth)
        {
            NUMBERS[sycle] = card_num;
            while (card_num_len)
            {
                // Breaking out each digit of whole credit card number
                current_num_digit = card_num % 10;
                card_num /= 10;
                current_digit_pos++;
                card_num_len--;

                // Is thise last digit of card number
                if ((solid_len - current_digit_pos) == 0)
                {
                    checker = current_num_digit;
                }

                if (current_digit_pos % 2 == 0)
                {
                    if (current_num_digit > 4)
                    {
                        sum += (current_num_digit * 2) - 9;
                    }
                    else
                    {
                        sum += current_num_digit * 2;
                    }
                }
                else
                {
                    sum += current_num_digit;
                }
            }
            if (sum % 10 == 0)
            {
                VALIDATIONS[sycle] = "VALID";

                if (checker == 5)
                {
                    OWNERS[sycle] = "Mastercard";
                }
                else if (checker == 4)
                {
                    OWNERS[sycle] = "Visa";
                }
                else if (checker == 3)
                {
                    OWNERS[sycle] = "American Exp.";
                }
                else
                {
                    OWNERS[sycle] = "Other";
                }
            }
            else
            {
                VALIDATIONS[sycle] = "INVALID";
                OWNERS[sycle] = "-";
            }
        }
        else
        {
            printf("Thise is not a card number card\n");
            sycle--;
        }
        card_num = 0;
    }

    int all_num_len = 0;
    // The lenght of line with whole values
    for (int index = 0; index < cards; index++)
    {
        all_num_len += floor(log10(labs(NUMBERS[index]))) + 2;
    }
    all_num_len++;

    // Showing data
    valids(cards, LENGTHS, VALIDATIONS, VALSCOREBEF, VALSCOREAFT);
    owners(cards, LENGTHS, OWNERS, all_num_len, OWNSCOREBEF, OWNSCOREAFT);
    show_datat(VALIDATIONS, OWNERS, VALSCOREBEF, VALSCOREAFT, OWNSCOREBEF, OWNSCOREAFT, NUMBERS, all_num_len, cards);
}
//
//
//
void valids(int cards, int *LENGTHS, string *VALIDATIONS, int *VALSCOREBEF, int *VALSCOREAFT)
{
    for (int index = 0; index < cards; index++)
    {
        string print_val = VALIDATIONS[index];
        int print_len = LENGTHS[index];
        long val_len = strlen(VALIDATIONS[index]);

        for (int k = 0; k < round((print_len - val_len) / 2); k++)
        {
            VALSCOREBEF[index]++;
        }
        VALSCOREAFT[index] = print_len - val_len - VALSCOREBEF[index];
    }
}
//
//
//
void owners(int cards, int *LENGTHS, string *OWNERS, int all_num_len, int *OWNSCOREBEF, int *OWNSCOREAFT)
{
    for (int index = 0; index < cards; index++)
    {
        OWNSCOREBEF[index] = 0;
        string print_own = OWNERS[index];
        int print_len = LENGTHS[index];
        long own_len = strlen(OWNERS[index]);

        for (int k = 0; k < round((print_len - own_len) / 2); k++)
        {
            OWNSCOREBEF[index]++;
        }
        OWNSCOREAFT[index] = print_len - own_len - OWNSCOREBEF[index];
    }

}

void show_datat(string *VALIDATIONS, string *OWNERS, int *VALSCOREBEF, int *VALSCOREAFT, int *OWNSCOREBEF, int *OWNSCOREAFT, long *NUMBERS, int all_num_len, int cards)
{
    //Underline
    for (int i = 0; i < all_num_len; i++)
    {
        printf("_");
    }
    printf("\n|");
    //
    //
    for(int index = 0; index < cards; index++)
    {
        printf("%ld|", NUMBERS[index]);
    }
    printf("\n|");
    //
    //
    for(int index = 0; index < cards; index++)
    {
        for(int i = 0; i < VALSCOREBEF[index]; i++)
        {
            printf("-");
        }
        printf("%s", VALIDATIONS[index]);

        for(int i = 0; i < VALSCOREAFT[index]; i++)
        {
            printf("-");
        }
        printf("|");
    }
    printf("\n|");
    //
    //
    for(int index = 0; index < cards; index++)
    {
        for(int i = 0; i < OWNSCOREBEF[index]; i++)
        {
            printf("-");
        }
        printf("%s", OWNERS[index]);

        for(int i = 0; i < OWNSCOREAFT[index]; i++)
        {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
    //
    //Upperline
    for (int i = 0; i < all_num_len; i++)
    {
        printf("‾");
    }
    printf("\n");
}
