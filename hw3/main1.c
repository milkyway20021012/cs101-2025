#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 69
#define NUM_COUNT 7
#define MAX_GROUP 5
#define WIN_NUM_COUNT 3

// 設定中獎號碼：02, 04, 06
int winning_numbers[WIN_NUM_COUNT] = {2, 4, 6};

// 檢查彩票是否中獎（只要有一個中獎號碼即可）
int check_winner(int numbers[])
{
    // 檢查彩票中是否包含至少一個中獎號碼
    for (int i = 0; i < NUM_COUNT; i++)
    {
        for (int j = 0; j < WIN_NUM_COUNT; j++)
        {
            if (numbers[i] == winning_numbers[j])
            {
                return 1; // 如果找到一個匹配的中獎號碼，就視為中獎
            }
        }
    }

    return 0; // 如果沒有匹配的號碼，則不算中獎
}

int main()
{
    FILE *input_file = fopen("lotto.txt", "r");
    FILE *output_file = fopen("win.txt", "w");

    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char line[256];
    int numbers[NUM_COUNT];

    // 讀取 lotto.txt 的內容並檢查是否中獎
    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        // 跳過標題和尾部
        if (line[0] == '=' || line[0] == ' ' || line[0] == '\n')
            continue;

        // 解析彩票的號碼
        int num_scanned = sscanf(line, "[%*d]: %d %d %d %d %d %d %d",
                                 &numbers[0], &numbers[1], &numbers[2],
                                 &numbers[3], &numbers[4], &numbers[5], &numbers[6]);

        if (num_scanned == NUM_COUNT)
        {
            // 檢查是否符合中獎條件（只要有一個中獎號碼即可）
            if (check_winner(numbers))
            {
                // 輸出符合中獎條件的彩票
                fprintf(output_file, "%s", line);
            }
        }
        else
        {
            printf("解析彩票號碼錯誤: %s", line);
        }
    }

    // 關閉文件
    fclose(input_file);
    fclose(output_file);

    return 0;
}