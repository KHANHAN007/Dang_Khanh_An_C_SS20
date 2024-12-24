#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[100];
    int age;
};
int readInfor(char *fileName, struct Student *students)
{
    FILE *f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Khong mo file %s.\n", fileName);
        return 0;
    }
    int i = 0;
    while (fgets(students[i].name, sizeof(students[i].name), f) != NULL)
    {
        char temp[100];
        if (sscanf(students[i].name, "%d,%99[^,],%d", &students[i].id, temp, &students[i].age) == 3)
        {
            strcpy(students[i].name, temp);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            i++;
            if (i >= MAX_STUDENTS)
            {
                break;
            }
        }
    }
    fclose(f);
    return i;
}

void printStudents(struct Student *students, int n)
{
    printf("Danh sachsach:\n");
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int numStudents;
    numStudents = readInfor("students.txt", students);
    if (numStudents > 0)
    {
        printStudents(students, numStudents);
    }
    else
    {
        printf("Khong co du lieulieu.\n");
    }
}
