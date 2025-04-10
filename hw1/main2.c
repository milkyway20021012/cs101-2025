#include <stdio.h>
#include <string.h>

// A3B4C5 -- AAABBBBCCCCC

int main()
{
    char buf[256];
    scanf("%s", buf);

    for (int i = 0; i < strlen(buf); ++i)
    {
        char cur = buf[i];
        if (buf[i] >= '1' && buf[i] <= '9')
        {
            int count = buf[i] - '0';
            cur = buf[i - 1];
            for (int j = 0; j < count; j++)
            {
                printf("%c", cur);
            }
        }
    }

    return 0;
}