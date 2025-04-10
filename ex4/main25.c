#include <stdio.h>
int multi(int i, int j)
{
    if (j == 1)
    {
        printf("%d*%d=%d\n", i, j, i * j);
        return i;
    }
    else
    {
        multi(i, j - 1);
        printf("%d*%d=%d\n", i, j, i * j);
    }
    
}

int main()
{
    multi(0, 9);
    return 0;
}
