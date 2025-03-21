#include <stdio.h>

int main()
{
    FILE *fp = fopen("main2.c", "r");
    FILE *fout = fopen("main.txt", "w");

    if (fp == NULL)
    {
        perror("Failed to open main.c");
        return 1; // 非 0 代表程式錯誤結束
    }

    if (fout == NULL)
    {
        perror("Failed to open main.txt");
        fclose(fp);
        return 1;
    }

    char c;
    while ((c = getc(fp)) != EOF)
    {
        fputc(c, fout);
    }

    fprintf(fout, "\n");

    fclose(fp); // 記得關閉檔案，避免記憶體洩漏
    fclose(fout);

    return 0;
}