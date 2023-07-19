#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //* <--- Need this to acces the absolute and random functions
/*
    stdlib Functions
    - abs(), labs(), llabs()
    - rand(), srand()
*/
#include <time.h> //* <--- Need this to acces current time (used in random seed)
#include <ctype.h> //* <--- Need this to acces the character minipulator and analysis function
/*
    ctype Functions
    -Manipulator: topper(), tolower(),
    -Analysis: isupper(), islower(), isdigit(), isalpha(),isblank(),isspace()
    
*/

//* Size for the C string character arrays (printable character length)

#define STRSIZE 8
#define NAME_LEN 30
#define RECORDS 5
#define DESC_LEN 30
#define PHRASE_LEN 50
void plainCharArray(const char str[], int arrSize)
{
    int i;
    printf("Display 'CString!' using a plain character array (Really inefficient!)\n");

    //* NOTE: We need to know how many characters there are in the character array

    for (i = 0; i < arrSize; i++)
    {
        printf("%c", str[i]);
        //*NOTE: OR, we could use unformatted output:
        //* puthcar(str[i]);
    }
    printf("\n");
}
void clearBuffer(void)
{
    while (getchar() != '\n')
    {
        //*do nothing
        //* Just remove each outstanding character in the input buffer
    }
}
void absoluteInt(void);
void absoluteLong(void);
void absoluteLongLong(void);
void vrandom(void);
void showRandomUpToMax(int max);
//* Manipulators
void showUpper(const char* str) {
    int i;

    printf("Testing toupper() manipulator function\n");
    printf("BEFORE: %s\n", str);
    printf("AFTER : ");

    for (i=0; str[i]!= '\0'; i++)
    {
        putchar(toupper(str[i]));
    }
    printf("\n\n");
}

struct Product {
    int sku;
    int units;
    int minimum;
    float price;
    char description[DESC_LEN + 1]; //*Don't forget to account for the null terminator
};
int main()
{

    //* Declaring and initializing a plain char array (NOT a C String);
    char str[] = {'C', 'S', 't', 'r', 'i', 'n', 'g', '!'}; //* normal char array (NOT a String)
    plainCharArray(str, 8);                                //* function to display this word to the screen

    //*Declaring and initializing C Strings:
    char str1[] = {'C', 'S', 't', 'r', 'i', 'n', 'g', '1', '\0'}; //! long method
    char str2[] = "CString2";                                     //* auto-sizes to 9 (8 printable chars + null terminator byte)
    char str3[9] = "CString3";                                    //*expicitly sized to 9 (printable chars + null terminator byte)
    char str4[STRSIZE + 1] = "CString4";                          //*Macro sizing +1 for null terminator byte

    //*Declaring and initializing C Strings to a safe empty state:
    char str5[6] = {'\0'};        //* Safe empty state (assign null terminator byte)
    char str6[6] = {0};           //* Same as above, only uses decimal ASCII value
    char str7[STRSIZE + 1] = {0}; //* Safe empty state (used for user input later)

    //*Displaying C Strings
    printf("Values of strings\n");
    printf("str1:%s\n", str1);
    printf("str2:%s\n", str2);
    printf("str3:%s\n", str3);
    printf("str4:%s\n", str4);
    printf("str5:%s (empty)\n", str5);
    printf("str6:%s (empty)\n", str6);

    //* C String input (standart input from user):
    printf("Enter str7: ");
    scanf("%s", str7); //*Note: No '&' address-of-oeprator required!
    // clearBuffer();
    printf("str7:%s\n", str7);
    //* Protect/respect char array size:
    printf("Enter str7 (enter > 8 chars):");
    scanf("%8s", str7); //* Note char's > 5th will remain in input buffer!
    printf("str7:%s\n", str7);

    //* Part:1 Getting strings with multiple words (spaces inbetween)
    printf("Enter str7 (enter \"I am\"):");
    scanf("%8s", str7); //* Will only assign 'I' (spaces represent another value story)
    printf("str7:%s\n", str7);

    //* Part2 Getting strings with mutliple words (spaces in between)
    printf("Enter str7 (enter \"I am\"):");
    scanf("%8[^\n]", str7); //* Note: 's' is implied; Both words are stored
    printf("str7:%s\n", str7);

    /*
        //* Pausing
        //* - How to clear the input buffer
        //* - Ensure application pauses for user input
        //* - Modify buffer clearing to pause the application
    */
    int val = -999;
    char ch = '!', initial = '!';

    printf("Enter an int and a char '8B:");
    scanf("%d%c", &val, &ch); //* Prompts for user input; assign val=8 and ch =8
                              //* Input buffer contains: \n (leftover unassigned character)
    clearBuffer();
    // getchar(); //* This will "discard" the \n char left in the buffer
    // while (getchar() != '\n')
    // {
    //     //* do nothing
    //     //* Just remove each outstanding character in the input buffer
    // }
    printf("(Press Enter to Continue)");
    clearBuffer();
    //* Show assigned values
    //* Proves 8B has been removed from the buffer and assigned to variables
    printf("val:%d ch:%c\n\n", val, ch);

    //* Attempt to prompt for 1st initial:
    printf("Enter your 1st Initial:");
    initial = getchar(); //* Will NOT prompt, since there is a \n char in the buffer!

    printf("\n");

    //* If variable 'initial' has a newline we know for sure it did't prompt for user input!
    if (initial == '\n')
    {
        printf("oops... why did't it stop to get my 1st initial?!\n\n");
    }
    else
    {
        printf("initial:%c\n", initial);
    }

    //* Declare and initialize variable to a safe empty state
    char name[NAME_LEN + 1] = {0};
    int yearBorn = 0;
    char favLetter = '\0';
    float heightCm = 0.0f;
    int numSucces = 0;

    //* Display instructions
    printf("Input adata sequence: First name, Birth Year, Favourite letter, Height in cm\n");
    printf("Example: Boris 1962 C 172.5\n\n");

    //*Get user input
    printf("Enter your data: ");
    numSucces = scanf("%30s %d %c %f", name, &yearBorn, &favLetter, &heightCm);
    if (numSucces == 4)
    {
        //*Display succesfully assigned values
        printf("Name  :%s\n ", name);
        printf("Born  :%d\n", yearBorn);
        printf("Letter:%c\n ", favLetter);
        printf("Height:%.1f cm.\n\n", heightCm);
    }
    else {
        printf("ERROR: Data not entered in the order expected or bad data entered.\n");
    }

    //* Printf : Formatting

    //*                                 SKU    Units   Min.  Price.   Description
    struct Product product[RECORDS] = { 
                                    {90623,  1,     5,    210.99,  "Camed Beans"},
                                    {25,     30750, 10,   1325.47, "Aluminum Foil"},
                                    {5,      200,   8,    2.98,    "Doritos Chips - BBQ"},
                                    {6565,   6500,  15,   67.49,   "Orange Juice 6-Pack "},
                                    {325,    15,    150,  12476.89, "Bounty Paper Towels"}                         
                                      };
    int i;
    printf("ACME Product Inventory\n\n");
   
   //*Header Column alignment (data section should match these widths)
    printf("%-6s %-15s %-5s %-7s %9s\n",
        "SKU",
        "Description",
        "Units",
        "Minimum",
        "Price");
        
        for(i = 0; i < RECORDS; i++) 
            {
                printf("%06d %-12.12s... %5d  %7d %9.2f\n",
                    product[i].sku,
                    product[i].description,
                    product[i].units,
                    product[i].minimum,
                    product[i].price);
            }

    //*Absolute
        absoluteInt();
        absoluteLong();
        absoluteLongLong();
        srand(time(NULL));
        vrandom();
        showRandomUpToMax(5);
        char words[PHRASE_LEN + 1] = "IPC 144 is not awesome\n\tSeriously it is not";
        printf("C Type library functions\n");
        printf("Source C string used for all tests\n");
        printf("%s\n\n",words);
    return 0;
}

void absoluteInt(void)
 {
    int val1, val2;
        do
        {
            printf("Enter two integer values (0 's to exit'): ");
            scanf("%d %d", &val1, &val2);

            printf("The delta between value is: %d\n\n", abs(val2 - val1));
        } while(val1 !=0 && val2 !=0);
        
 }

void absoluteLong(void) {

        long int lval1, lval2;
        do {
            printf("Enter two long integer values ('0's to exit): ");
            scanf("%ld %ld", &lval1, &lval2);
  
            printf("The delta between these value is: %ld\n\n", labs(lval1 - lval2));
        } while(lval1 !=0 && lval2 != 0);
}
void absoluteLongLong(void) {

        long long int llval1, llval2;
        do {
            printf("Enter two long integer values ('0's to exit): ");
            scanf("%lld %lld", &llval1, &llval2);
  
            printf("The delta between these value is: %lld\n\n", llabs(llval1 - llval2));
        } while(llval1 !=0 && llval2 != 0);
} 

void vrandom(void) {

    int keepGoing;

    do {
        printf("Random number: %d\n\n", rand());

        printf("Again? (0 to exit):");
        scanf("%d", &keepGoing);
        printf("\n"); 
    }
    while(keepGoing);
}

void showRandomUpToMax(int max)
    {
        int keepGoing;
        int rdm, result;

        do {
            // rdm = rand();
            // result = rdm % max; //* modulus wull reuslt in a value between 0 and (nax-1)
            // result++;

            //printf("Random number between 1 and %d: %d\n", max, result);
            printf("Random number between 1 and %d: %d\n", max, (rand() % max)+1);
            printf("Again? (0 to quit): ");

            scanf(" %d", &keepGoing);
        } while(keepGoing);
    }