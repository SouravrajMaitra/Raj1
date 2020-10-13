#include<stdio.h>

int main()
{
    FILE *f;char c;
    f=fopen("Str2.c","r");
    while((c=fgetc(f))!=EOF)
        printf("%c",c);
    fclose(f);
    return 0;
}