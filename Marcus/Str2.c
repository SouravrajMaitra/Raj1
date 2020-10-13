//Pid(String and integer),name,quantity,purchase price,sale price,gst,discount
#include<stdio.h>
#include<string.h>
struct Details
{
    char Pid[100];
    char name[100];
    int quantity;
    float pprice;
    float sprice;
    float GST;
    float discount;
};

int comp(struct Details a,struct Details b)
{
    int flag=0;
    if(!(stricmp(a.Pid,b.Pid)))
    ++flag;
    if(!(stricmp(a.name,b.name)))
    ++flag;
    if(a.quantity==b.quantity)
    ++flag;
    if(a.pprice==b.pprice)
    ++flag;
    if(a.sprice==b.sprice)
    ++flag;
    if(a.discount==b.discount)
    ++flag;
    if(flag==6)
    return 1;
    return 0;
}
int main()
{
    struct Details product[100];int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        product[i].GST=0.18;
        fflush(stdin);
        printf("Enter the product id:");
        gets(product[i].Pid);
        printf("Enter the product name:");
        gets(product[i].name);fflush(stdin);
        printf("Enter the quantity,purchase price and discount:");
        scanf("%d%f%f",&product[i].quantity,&product[i].pprice,&product[i].discount);
        product[i].sprice=product[i].pprice*(1+product[i].GST);
        product[i].sprice=product[i].sprice*(1-product[i].discount/100);
        printf("\nDetails of the product:\n");
        printf("Id:%s\nName:%s\nQuantity:%d\nPurchase price:%f\nSale price:%f\nGST:%f\nDiscount:%f\n\n",product[i].Pid,product[i].name,product[i].quantity,product[i].pprice,product[i].sprice,product[i].GST,product[i].discount);
    }
    int j;
        for(i=0;i<n;i++)
        {
            printf("((e[%d]),(",i);

    for(j=0;j<n;j++)
    {
        if(i==j)
        continue;
        if(comp(product[i],product[j]))       
        printf("e[%d]",j);
    }
    printf(")))");
        }

    return 0;
}