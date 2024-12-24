#include <stdio.h>

int main()
{
    FILE *sourceFile, *destFile;
    char ch;
    sourceFile = fopen("bt01.txt", "r");
    if (sourceFile == NULL)
    {
        printf("Khong the mo file.");
        return 1;
    }
    destFile = fopen("bt06.txt", "w");
    if (destFile == NULL)
    {
        printf("Khong the tao file");
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile);
    }
    printf("Sao chep thanh cong.");
    fclose(sourceFile);
    fclose(destFile);
}
