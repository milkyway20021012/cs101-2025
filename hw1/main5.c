#include <stdio.h>
void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("%d", i);
            if (j < i - 1) {
                printf(" "); 
            }
        }
        printf("\n"); 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    print_pyramid(n);
    
    return 0;
}