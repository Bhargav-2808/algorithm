#include<stdio.h>
#include<conio.h>


void main()
{
    int i,j,temp,   flag=0;

    int a[] ={10,5,26,2,45};

    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            //printf("%d %d \n ", i,j);
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;

            }
            if(flag==0)
            {
            break;
            }
        }


    }

    for(i=1;i<=5;i++)
    {
        printf("%d\n", a[i]);
    }
}

