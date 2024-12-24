#include <stdio.h>

int main()
{
    FILE *f = fopen("bt01.txt", "r");
    if(f==NULL)
    {
        printf("Khong the mo tap.");
        return 1;
    }
    char c = fgetc(f);
    if(c !=EOF)
        printf("%c", c);
    else
        printf("Tep rong.");
    fclose(f);
}