
#include <stdio.h>
#include <stdlib.h>

int i,j,k;
void mergeSort(int a[], int low, int up)
{
	if (low >= up)
    {
        return;

	}
	int mid = (low+up) / 2,temp[20];
	mergeSort(a, low, mid);
    mergeSort(a, mid + 1, up);
    merge(a,temp, low, up,mid);


}

void merge(int a[],int temp[], int low, int up, int mid)
{
	for(i=low,j=mid+1,k=low;i<=mid && j<=up;k++)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
    }

	while (i <=mid)
    {
		temp[k]=a[i];
        i++;
        k++;
	}


	while (j <=up)
    {
		temp[k]=a[j];
        j++;
        k++;
	}


	for(i=low;i<=up;i++)
    {
        a[i]=temp[i];
    }
}


void main()
{
	int a[20],low=0,up,mid,n;

    printf("Enter size of array");
    scanf("%d", &n);
    up=n-1;
    printf("Enter the array");
    for (i = 0; i<n; i++)
    {
         scanf("%d", &a[i]);
    }




	mergeSort(a, low,up);

	printf("\nSorted array is \n");
	for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        printf("\n");
    }

}

