#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 69
#define NUM_COUNT 7
#define MAX_GROUP 5

void generate_lotto_numbers(int numbers[])
{
    int i, j, temp, is_unique;
    for (i = 0; i < NUM_COUNT; i++)
    {
        do
        {
            is_unique = 1;
            temp = rand() % MAX_NUM + 1; // 產生 1-69 之間的數字
            // 檢查是否重複
            for (j = 0; j < i; j++)
            {
                if (numbers[j] == temp)
                {
                    is_unique = 0;
                    break;
                }
            }
        } while (!is_unique); // 若有重複則重新生成
        numbers[i] = temp;
    }
}

int main()
{
    FILE *file = fopen("lotto.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int N;
    scanf("%d", &N); // 讀取 N

    // 設定隨機數種子為固定值 1，保證每次運行產生相同的結果
    srand(1);

    // 輸出標題
    fprintf(file, "========= lotto649 =========\n");

    // 生成 N 組樂透號碼並寫入檔案
    for (int i = 0; i < N; i++)
    {
        int numbers[NUM_COUNT];
        generate_lotto_numbers(numbers);

        fprintf(file, "[%d]:", i + 1);
        for (int j = 0; j < NUM_COUNT; j++)
        {
            fprintf(file, " %02d", numbers[j]); // 格式化輸出，保證兩位數
        }
        fprintf(file, "\n");
    }

    // 如果 N 少於 5，填充剩餘的組數為 " __ __ __ __ __ __ __ "
    for (int i = N; i < MAX_GROUP; i++)
    {
        fprintf(file, "[%d]: __ __ __ __ __ __ __\n", i + 1);
    }

    // 輸出結尾
    fprintf(file, "========= csie@CGU =========\n");

    // 關閉檔案
    fclose(file);

    return 0;
}