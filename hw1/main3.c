#include <stdio.h>
#include <string.h>
int main()
{
    // 8bits to 16進制

    char a[] = "10001111";
    int sum = 0;   // 計算總和
    int power = 8; // 用來充當2的n次方
    int Bits = 4;  // 用來判斷是否已經計算了 4個bits
    int len = strlen(a);
    int flag = 0;
    for (int i = 0; i <len; ++i)
    {
        flag = 0;
        sum += power* (a[i] - '0');
        --Bits;
        power /=2;
        if(Bits == 0){
            flag = 1;
        }
        if(flag){
            switch(sum){
                case 10:
                    printf("%c",'A');
                    break;
                case 11:
                    printf("%c",'B');
                    break;
                case 12:
                    printf("%c",'C');
                    break;
                case 13:
                    printf("%c",'D');
                    break;
                case 14:
                    printf("%c",'E');
                    break;
                case 15:
                    printf("%c",'F');
                    break;
                default:
                    printf("%c",sum + '0');
                    break;
            }
            // 重置
            sum = 0; 
            Bits = 4;
            power = 8;
        }
    }

    return 0;
}