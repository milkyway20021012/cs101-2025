#include <stdio.h>

int main(){
    // '0' = 48
    char a[256];
    scanf("%s",a);
    int i = 1; // 數字字元的起始位置
    int j = 0; // 字母字元的起始位置
    
    while(a[j] != '\0'){
        while(a[i] < 58 && a[i]-- > 48){
            printf("%c",a[j]);
        }
        i+=2;
        j+=2;
    }

    return 0;
}