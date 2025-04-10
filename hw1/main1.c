#include <stdio.h>
#include <string.h>
int main()
{
    char buf[256];
    int count = 1;
    scanf("%s", buf);
    for (int i = 0; i < strlen(buf); ++i)
    {
        if (buf[i + 1] != buf[i])
        {
            printf("%c%d", buf[i], count);
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return 0;
}