
#include <stdio.h>
#include<conio.h>
int main()
{
    int a[20], n, i, j, start, temp;
    printf("Enter size of array");
    scanf("%d", &n);

    printf("Enter the array");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++)
    {
        start=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[start] > a[j])
                start=j;
        }
        if(start != i)
        {
            temp=a[i];
            a[i]=a[start];
            a[start]=temp;
        }
    }

    printf("Sorted Array:n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

}
