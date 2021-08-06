#include<stdio.h>
#include<conio.h>


void main()
{
    int i,j,temp;

    int a[] ={10,4,15,3,2};

    for(i=0;i<5;i++)
    {

        for(j=0;j<5;j++)
        {
            //sprintf("%d %d \n", i,j);
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }

    for(i=0;i<5;i++)
    {
        printf("%d\n", a[i]);
    }
}
