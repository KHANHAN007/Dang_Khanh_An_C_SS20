#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[100];
    int age;
};
void inputStudent(struct Student *student)
{
    printf("ID: ");
    scanf("%d", &student->id);
    getchar();
    printf("Tenen: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';
    printf("Tuoiuoi: ");
    scanf("%d", &student->age);
}
void saveToFile(struct Student *students, int n)
{
    FILE *file = fopen("students.txt", "w");
    if (file == NULL)
    {
        printf("Khong the mo filefile.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d, %s, %d\n", students[i].id, students[i].name, students[i].age);
    }

    fclose(file);
    printf("Lua thanh cong.\n");
}
int main()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL)
    {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        inputStudent(&students[i]);
    }
    saveToFile(students, n);
    free(students);
}
