#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to convert a character to its corresponding value in the given base
int val(char c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';  // If the character is a digit, return its integer value
    else
        return (int)c - 'A' + 10;  // If the character is a letter, return its integer value in base 10
}

// Function to check if the input number is valid for the given base
bool is_valid_number(char *str, int base) {
    if (base < 2) {
        return false;  // Base must be at least 2 for a valid number
    }
    for (int i = 0; i < strlen(str); i++) {
        if (val(str[i]) >= base) {
            return false;  // The digit must be less than the base
        }
    }
    return true;  // The number is valid for the given base
}

// Function to convert a number in a given base to decimal
int toDeci(char *str, int base) {
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (val(str[i]) >= base) {
            printf("Invalid Number");  // If a digit is not valid for the base, print an error message
            return -1;  // Return -1 to indicate an error
        }

        num += val(str[i]) * power;
        power = power * base;
    }

    return num;  // Return the decimal equivalent of the number
}

// Function to convert a decimal number to a given base
void toBase(int decimal, int base) {
    char result[100];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            result[index] = remainder + '0';  // If the remainder is a digit, store it as a character
        } else {
            result[index] = remainder - 10 + 'A';  // If the remainder is a letter, store it as a character
        }
        index++;
        decimal /= base;
    }

    printf("Result: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);  // Print the result in reverse order
    }
    printf("\n");
}

int main() {
    char str[100];
    int from_base, to_base;

    printf("Enter the number to convert: ");
    scanf("%s", str);

    printf("Enter the base of the input number: ");
    scanf("%d", &from_base);

    printf("Enter the base to convert to: ");
    scanf("%d", &to_base);

    if (is_valid_number(str, from_base)) {
        int decimal = toDeci(str, from_base);

        if (decimal != -1) {
            printf("Decimal equivalent: %d\n", decimal);
            toBase(decimal, to_base);
        }
    } else {
        printf("Error: Invalid input\n");
    }

    return 0;
}
