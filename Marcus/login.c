int loginCheck()
{
    char name[100];
    int i;
    int c=3;
    while(c)
    {   i=0;
        strcpy(name,"\0");
        printf("\nEnter your password:");
        fflush(stdin);
        while((name[i]=getch())!='\r')
        {
            printf("*");
            ++i;
        }
        name[i]='\0';
        if(!c)
            {
                printf("Account Locked");
                break;
            }
        if(strcmp(name,"admin")==0)
            {printf("\nLogin Successful!!!");return 0;}
        else
            printf("\nWrong Password!!! %d tries left.",--c);
    }     
    return 1;
}