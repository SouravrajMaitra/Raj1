#include<stdio.h>

struct student
{
    long long roll;
    char name[100];
    int marks;
};
typedef struct student Student;
Student st;

int isavail(long long roll)
{
    FILE *f=fopen("Record","r");
    while(fread(&st,sizeof(Student),1,f))
    if(roll==st.roll)
    return(1);
    return(0);
}

int empty()
{
    FILE *f=fopen("Record","r");
    if(!(fread(&st,sizeof(Student),1,f)))
    {
        fclose(f);
        return 1;
    }
    fclose(f);
    return 0;
}

int menu()
{
    int ch;
    printf("\n----------Menu----------");
    printf("\n\t1.INSERT\n\t2.DELETE\n\t3.SEARCH\n\t4.SORT\n\t5.DISPLAY\n\t6.UPDATE\n\t7.EXIT\n\nEnter your choice:");
    scanf("%d",&ch);
    printf("----------------------------------------------------------------------------------------------------------");
    return(ch);
}

void insert()
{
    fflush(stdin);
    printf("\nEnter name:");
    gets(st.name);
    fflush(stdin);
    printf("Roll:");
    scanf("%lld",&st.roll);
    printf("Marks:");
    scanf("%d",&st.marks);
    FILE *f;
    f=fopen("Record","a");
    fwrite(&st,sizeof(Student),1,f);
    fclose(f);
}

void delete()
{
    FILE *fo,*ft;long long roll;
    printf("\nEnter the roll:");
    scanf("%lld",&roll);
    fo=fopen("Record","r");
    ft=fopen("Temp","a+");
    if(empty())
    {
        printf("\nNothing to delete!!!");
        return;
    }
    if(!(isavail(roll)))
    printf("\nRecord to be deleted is not present!!!");

    while(fread(&st,sizeof(Student),1,fo))
        if(roll!=st.roll)
            fwrite(&st,sizeof(Student),1,ft);
    fclose(fo);
    rewind(ft);
    fo=fopen("Record","w");
    while(fread(&st,sizeof(Student),1,ft))
        fwrite(&st,sizeof(Student),1,fo);
    fclose(ft);
    fclose(fo);
    remove("Temp");
}

long search(long long roll)
{
    FILE *f;long t;
    f=fopen("Record","r");
    while(!feof(f))
    {   
        t=ftell(f);
        fread(&st,sizeof(Student),1,f);
        if(st.roll==roll)
            {printf("\nName:%s\nRoll:%lld\nMarks:%d\n\n",st.name,st.roll,st.marks);return(t);}
    }
        printf("\nRecord not found!!!");
        return(-1);
}

void swap(long long *a,long long *b)
{
    long long t;
    t=*a;*a=*b;*b=t;
}

void sort1(long long *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        if(a[i]>a[j])
        swap(a+i,a+j);
    }
}

void sort()
{
    long long a[100];int i,l=0;
    FILE *f;
    f=fopen("Record","r");
    while(fread(&st,sizeof(Student),1,f))
        a[l++]=st.roll;
    fclose(f);
    sort1(a,l);
    for(i=0;i<l;i++)
        search(a[i]);
}

void display()
{
    FILE *f;int i=0;
    f=fopen("Record","r");
    while(fread(&st,sizeof(Student),1,f))
        printf("\n\n\nStudent %d:\nName:%s\nRoll:%lld\nMarks:%d",++i,st.name,st.roll,st.marks);
}

void update()
{
    long long roll;
    int ch,t;
    char m='y';
    while(m=='y')
    {
        printf("\nEnter roll number:");
        scanf("%lld",&roll);
        t=search(roll);
        FILE *fo;
        if(t==-1)
        return;
        fo=fopen("Record","a+");
        fseek(fo,0,t);
        fread(&st,sizeof(Student),1,fo);
        printf("\n\nWhat you want to update?\n1.Name\n2.Marks\n3.Both\n4.Exit\n\n");
        scanf("%d",&ch);
         if(ch==1)
        {
            printf("\nEnter name:");
            fflush(stdin);
            gets(st.name);
            fflush(stdin);
            fseek(fo,0,t);
            fwrite(&st,sizeof(Student),1,fo);
        }
        else if(ch==2)
        {
            printf("\nEnter your marks:");
            scanf("%d",&st.marks);
            fseek(fo,0,t);
            fwrite(&st,sizeof(Student),1,fo);
        }
        else if(ch==3)
        {
            printf("\nEnter name:");
            fflush(stdin);
            gets(st.name);
            printf("Enter your marks:");
            scanf("%d",&st.marks);
            fseek(fo,0,t);
            fwrite(&st,sizeof(Student),1,fo);
        }
        else if(ch==4)
            break;
        else
            printf("\nWrong choice,try again!!!\n\n");
            fflush(stdin);
            printf("Want to enter more?(y/n)");
            scanf(" %c",&m);
    }
}