#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000


int isNonDecreasing(int number) {
    int prevDigit = 10; 
    
    while (number > 0) {
        int digit = number % 10;
        if (digit > prevDigit) {
            return 0; 
        }
        prevDigit = digit;
        number /= 10;
    }
    
    return 1; 
}

int main() {
    char line[MAX_SIZE];
    int numbers[MAX_SIZE], count = 0;
    
   
    printf("Nh?p dãy s? (k?t thúc b?ng EOF):\n");
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int num = 0;
            
            for (int i = 0; token[i] != '\0'; i++) {
                if (isdigit(token[i])) {
                    num = num * 10 + (token[i] - '0');
                }
            }
            numbers[count++] = num;
            token = strtok(NULL, " \n");
        }
    }
    
    
    int freq[MAX_SIZE] = {0};
    
    // Duy?t qua t?ng s? trong m?ng numbers
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i])) {
            freq[numbers[i]]++;
        }
    }
    
    
    printf("Các s? không gi?m và s? l?n xu?t hi?n:\n");
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i]) && freq[numbers[i]] > 0) {
            printf("S? %d xu?t hi?n %d l?n\n", numbers[i], freq[numbers[i]]);
            freq[numbers[i]] = 0; 
        }
    }

    return 0;
}
