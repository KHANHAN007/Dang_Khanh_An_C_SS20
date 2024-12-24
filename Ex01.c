#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[256];
    FILE *f = fopen("bt01.txt", "w");
    if(f==NULL)
    {
        printf("Khong mo tep thanh cong.");
        return 1;
    }
    fgets(str, sizeof(str), stdin);
    fprintf(f, "%s", str);
    fclose(f);
    printf("Mo tap va ghi chuoi thanh cong.");
}
