#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
struct Book
{
    int id;
    char name[100];
    char author[100];
    float price;
    char category[50];
};
void inputBook(struct Book *book)
{
    printf("Nhap ma sach: ");
    scanf("%d", &book->id);
    getchar();
    printf("Nhap ten sach: ");
    fgets(book->name, sizeof(book->name), stdin);
    book->name[strcspn(book->name, "\n")] = '\0';
    printf("Nhap tac gia: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';
    printf("Nhap gia sach: ");
    scanf("%f", &book->price);
    getchar();
    printf("Nhap the loai sach: ");
    fgets(book->category, sizeof(book->category), stdin);
    book->category[strcspn(book->category, "\n")] = '\0';
}
void saveBooksToFile(const char *filename, struct Book *books, int count)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Khong the mo file.\n");
        return;
    }
    fwrite(books, sizeof(struct Book), count, file);
    fclose(file);
    printf("Thong tin sach da đuoc luu vao file.\n");
}
int loadBooksFromFile(const char *filename, struct Book *books)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Khong the mo file de đoc.\n");
        return 0;
    }
    int count = 0;
    while (fread(&books[count], sizeof(struct Book), 1, file))
    {
        count++;
    }
    fclose(file);
    return count;
}
void displayBooks(struct Book *books, int count)
{
    if (count == 0)
    {
        printf("Khong co sach de hien thi.\n");
        return;
    }
    printf("Danh sach sach:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Ma sach: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
        printf("-------------------------------------\n");
    }
}
int main()
{
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;
    const char *filename = "books.dat";
    do
    {
        printf("\n\t\tMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Nhap so luong sach: ");
            scanf("%d", &bookCount);
            getchar();
            if (bookCount > MAX_BOOKS)
            {
                printf("Khong hop le.\n");
                bookCount = MAX_BOOKS;
            }
            for (int i = 0; i < bookCount; i++)
            {
                printf("Nhap thong tin %d:\n", i + 1);
                inputBook(&books[i]);
            }
            break;

        case 2:
            saveBooksToFile(filename, books, bookCount);
            break;
        case 3:
            bookCount = loadBooksFromFile(filename, books);
            printf("Da lay %d lay tu file.\n", bookCount);
            break;
        case 4:
            displayBooks(books, bookCount);
            break;
        case 5:
            printf("Tam bietbiet.\n");
            break;
        default:
            printf("Khong hop le. Nhap lai.\n");
        }
    } while (choice != 5);
}
