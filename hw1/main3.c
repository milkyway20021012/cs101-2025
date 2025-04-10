#include <stdio.h>

int main()
{
    // 10001111 -- 8F
    char buf[9];
    scanf("%s", buf);
    int ret = 0;
    int times = 1;
    for (int i = 7; i >= 0; --i)
    {
        ret += ((buf[i] - '0') * times);
        times *= 2;
    }
    printf("%d\n", ret);
    printf("%X\n", ret); // 大小寫會改變輸出的大小寫
    return 0;
}