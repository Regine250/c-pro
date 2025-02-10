#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[length - 1 - i] == '1') {
            decimal += (1 << i); 
        }
    }
    
    return decimal;
}

void decimalToHexadecimal(int decimal) {
    char hex[20];
    int index = 0;

    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    for (; decimal > 0; decimal /= 16) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = (remainder - 10) + 'A'; 
        }
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

int main() {
    char binary[65]; 

    printf("Enter a binary number: ");
    scanf("%s", binary);

    int decimal = binaryToDecimal(binary);
    
    decimalToHexadecimal(decimal);

    return 0;
}