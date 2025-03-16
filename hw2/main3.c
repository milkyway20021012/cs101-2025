#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp_in, *fp_out;
    char line[1000];
    int l = 0;
    fp_in = fopen("main3.c", "r");
    while (fgets(line, sizeof(line), fp_in))
    {
        l++;
        if (strstr(line, "int main()"))
        {
            break;
        }
    }
    fp_out = fopen("main3.txt", "w");
    fprintf(fp_out, "%d", l);
    fclose(fp_out);
    return 0;
}