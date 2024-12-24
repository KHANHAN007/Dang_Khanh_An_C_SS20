#include <stdio.h>

int main()
{
    FILE *f = fopen("bt05.txt", "w");
    int numLines;
    char str[256];

    if(f==NULL)
    {
        printf("Khong the mo file.");
        return 1;
    }
    printf("Nhap so dong.");
    scanf("%d", &numLines);
    getchar();

    for (int i = 0; i < numLines;++i)
    {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(str, 256, stdin);
        fprintf(f, "%s", str);
    }
    fclose(f);
    f = fopen("bt05.txt", "r");

    if (f == NULL)
    {
        printf("Khong the mo file.");
        return 1;
    }
    while(fgets(str, 256, f)!=NULL)
    {
        printf("%s", str);
    }
    fclose(f);
}