#include <stdio.h>

int main()
{
    char a[] = "Hello";

    int len = sizeof(a) / sizeof(a[0]);

    for (int i = len - 2; i >= 0; --i)
    {
        printf("%c", a[i]);
    }

    return 0;
}