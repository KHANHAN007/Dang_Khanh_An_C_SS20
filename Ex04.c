#include <stdio.h>

int main()
{
    char str[256];
    FILE *f = fopen("bt01.txt", "r");
    if (f == NULL)
    {
        printf("Khong mo tep thanh cong.");
        return 1;
    }
    if(fgets(str, sizeof(str), f)!=NULL)
    {
        printf("%s", str);
    }
    else
        printf("Tep rong");
    fclose(f);
}
