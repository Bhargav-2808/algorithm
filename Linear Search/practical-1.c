#include<stdio.h>
#include<conio.h>


void main()
{
    int i , targat=10, flag=0;
    int a[5]={45,25,10,26,13};


    for(int i=0; i<5;i++)
    {
        if(targat==a[i])
        {
            printf("element found");
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("element not found");
    }
}
