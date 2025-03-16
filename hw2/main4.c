#include <stdio.h>

// 定義結構 (struct) 來儲存書籍資料
typedef struct Books
{
    int id;          // 書籍ID
    int price;       // 書籍價格
    char title[100]; // 書籍標題
} book_t;

// 定義書籍資料
book_t books[] = {
    {1, 1000, "All the Light We Cannot See"},
    {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
    {3, 1000, "The Ballad of Songbirds and Snakes"},
    {4, 550, "Killers of the Flower Moon"},
    {5, 870, "Elon Musk"},
    {6, 1344, "Milk and Honey 12-Month 2024"}};

void total_price()
{
    int total = 0;
    for (int i = 0; i < 6; i++)
    {
        total += books[i].price;
    }
    printf("%d\n", total); // 輸出總價
}
void list_books(int id)
{
    if (id >= 1 && id <= 6)
    {
        printf("%d %s\n", books[id - 1].price, books[id - 1].title);
    }
    else
    {
        printf("Invalid input\n");
    }
}

int main()
{
    int choice;
    scanf("%d", &choice);

    if (choice == 0)
    {
        total_price(); // 計算並輸出總價格
    }
    else if (choice >= 1 && choice <= 6)
    {
        list_books(choice); // 輸出對應書籍資料
    }
    else
    {
        printf("Invalid input\n"); // 輸入無效的處理
    }

    return 0;
}