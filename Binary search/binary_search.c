
#include<stdio.h>
#include<conio.h>


int binarySearch(int arr[], int s, int e, int targate)
{
        int mid;
        if(s>e)
        {

             return -1;

        }

        mid=(s+e)/2;

            if(arr[mid]==targate)
                return mid;
            else if(arr[mid]>targate)
                return binarySearch(arr,s,mid-1,targate);
            else if(arr[mid]<targate)
                return binarySearch(arr, mid + 1, e, targate);



}

int main()
{
	int arr[20];
	int i,n;

	int targate = 12;

	printf("Enter the size of array ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }



	int result = binarySearch(arr, 0, n-1, targate);

	if(result == -1)
	{
	    printf("Element not found");
	}
	else
    {
        printf("\nelement found at %d",result);
    }



	return 0;
}

