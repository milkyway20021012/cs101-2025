#include <stdio.h>

int main() {
    char binary[9]; 
    int decimal = 0;
    
    scanf("%8s", binary);
    	
    for (int i = 0; i < 8; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    
    printf("%X\n", decimal);
    
    return 0;
}
