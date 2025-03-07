#include <stdio.h>

int main()
{
    char a[256];
    scanf("%s",a);
    int i = 0;
    int count = 1;
    int flag = 1;
    while (a[i] != '\0')
    {
        char cur = a[i];
        if (a[i + 1] == cur)
        {
            count++;
            ++i;
            flag = 0;
        }
        else
        {
            flag = 1;
        }
        if (flag)
        {
            // count 最多九個
            if (count > 9)
            {
                count = 9;
            }
            printf("%c%d", a[i], count);
            count = 1;
            ++i;
        }
    }

    return 0;
}