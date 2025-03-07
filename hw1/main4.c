#include <stdio.h>
#include <string.h>

int main()
{
    char a[256];
    scanf("%s", a);
    int len = strlen(a);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    printf("%s\n", a); 
    return 0;
}