#include <stdio.h>  // Included for standard input/output functions
#include <ctype.h>   // Included for isdigit()
#include <string.h>  // Included for string manipulation functions
#include <stdbool.h> // used for error handling
#include <math.h> // used for exponents
#include <assert.h> // used for testing

float extractNumeric(char expression[]) {
    float num = 0;
    int sign = 1;
    int count = 0;

    if (expression[0] == '-') { 
        sign = -1;
        count++;
    } else if (expression[0] == '+') {
        sign = 1;
        count++;
    }

    for (int i = count; i < strlen(expression); i++) {
        if (isdigit(expression[i])) { // find the next number by adding each next character
            num = num * 10 + (expression[i] - '0');

        } else if (expression[i] == '.') { 
            break;
             
        } else {
            return -999999.99;
        }   
        count++;
    }

    float decimal = 0;
    float divisor = 1;
    if (expression[count] == '.') {
        for (int i = count+1; i < strlen(expression); i++) {
            if (isdigit(expression[i])) { // find the next number by adding each next character
                divisor = divisor * 10;
                decimal += (expression[i] - '0') / divisor;

            } else {
                return -999999.99;
            }   
            count++;
        }
    }

    return (num + decimal) * sign;
}

int main() {
    char input[100];

    while (true) {
        printf("Input please (enter 'END' to end): ");

        if (fgets(input, sizeof(input), stdin) != NULL) { // using fgets to handle input with spaces
            // Remove the trailing newline character, if present
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
            }
        }
        
        if (strcmp(input, "END") == 0) {
            break;
        }

        float number = extractNumeric(input);
        
        if (number != -1000000.0000) {
            printf("The input is: %.4f\n", number);
        } else {
            printf("The input is invalid.\n");
        }
    }

    return 0;
}