#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "Hello";
    int len = strlen(a);
    for(int i = 0,j=len-1; i!=j && i+1 != j;i++,j--){
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    for(int i = 0;i<len;i++){
        printf("%c",a[i]);
    }
    return 0;
}