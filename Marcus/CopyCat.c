#include<stdio.h>
#include<stdio.h>

struct student
{
    long rollno;
    char name[100];
    int mark;
}stud;

int avlrollno(int r)
{
    FILE *f;int c=0;
    f=fopen("Record","r");
    while(fread(&stud,sizeof(stud),1,f))
        if(r==stud.rollno)
        {c=1;break;}
    fclose(f);
    return c;
}

void deletefile()
{
        FILE *fpo;
        FILE *fpt;
        int r, s;
        printf("Enter the Roll no you want to delete :");
        scanf("%d", &r);
        if (avlrollno(r) == 0)
                        printf("Roll no %d is not available in the file\n", r);
        else
        {
                        fpo = fopen("Record", "r");
                        fpt = fopen("TempFile", "w");
                        while (fread(&stud, sizeof(stud), 1, fpo))
                        {
                                s = stud.rollno;
                                if (s != r)
                                fwrite(&stud, sizeof(stud), 1, fpt);
                        }
                        fclose(fpo);
                        fclose(fpt);
                        fpo = fopen("Record", "w");
                        fpt = fopen("TempFile", "r");
                        while (fread(&stud, sizeof(stud), 1, fpt))
                                fwrite(&stud, sizeof(stud), 1, fpo);
                        printf("\nRECORD DELETED\n");
                        fclose(fpo);
                        fclose(fpt);
        }

}

void update()
{
        int avl;
        FILE *fpt;
        FILE *fpo;
        int s, r, ch;
        printf("Enter roll number to update:");
        scanf("%d", &r);
        avl = avlrollno(r);
        if (avl == 0)
        {
                printf("Roll number %d is not Available in the file", r);
        }
        else
        {
                fpo = fopen("Record", "r");
                fpt = fopen("TempFile", "w");
                while (fread(&stud, sizeof(stud), 1, fpo))
                {
                        s = stud.rollno;
                        if (s != r)
                        fwrite(&stud, sizeof(stud), 1, fpt);
                        else
                        {
                        printf("\n\t1. Update Name of Roll Number %d", r);
                        printf("\n\t2. Update Mark of Roll Number %d", r);
                        printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
                        printf("\nEnter your choice:");
                        scanf("%d", &ch);
                        switch (ch)
                        {
                                case 1:
                                        printf("Enter Name:");
                                        scanf("%s", &stud.name);
                                        break;
                                case 2:
                                        printf("Enter Mark : ");
                                        scanf("%f", &stud.mark);
                                        break;
                                case 3:
                                        printf("Enter Name: ");
                                        scanf("%s", &stud.name);
                                        printf("Enter Mark: ");
                                        scanf("%f", &stud.mark);
                                        break;
                                default:
                                        printf("Invalid Selection");
                                        break;
                        }
                fwrite(&stud, sizeof(stud), 1, fpt);
                }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record", "w");
        fpt = fopen("TempFile", "r");
        while (fread(&stud, sizeof(stud), 1, fpt))
        {
                fwrite(&stud, sizeof(stud), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED");
        }
}

void sort()
{
        int a[20], count = 0, i, j, t, c;
        FILE *fpo;
        fpo = fopen("Record", "r");
        while (fread(&stud, sizeof(stud), 1, fpo))
        {
                a[count] = stud.rollno;
                count++;
        }
        c = count;
        for (i = 0; i<count - 1; i++)
        {
                for (j = i + 1; j<count; j++)
                {
                                if (a[i]>a[j])
                                {
                                t = a[i];
                                a[i] = a[j];
                                a[j] = t;
                                }
                }
        }
        printf("Roll No.\tName\t\tMark\n\n");
        count = c;
        for (i = 0; i<count; i++)
        {
                rewind(fpo);
                while (fread(&stud, sizeof(stud), 1, fpo))
                {
                                if (a[i] == stud.rollno)
                                printf("\n %d\t\t %s \t\t %2f",stud.rollno, stud.name, stud.mark);
                }

        }       
}
int empty()
{
        int c = 0;
        FILE *fp;
        fp = fopen("Record", "r");
        while (fread(&stud, sizeof(stud), 1, fp))
                {c = 1;break;}
        fclose(fp);
        return c;
}