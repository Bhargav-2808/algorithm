#include<conio.h>
#include <stdio.h>


int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


int knapSack(int Total_W,int w[],int v[],int num)
{

	if(num == 0 || Total_W == 0)
    {
        return 0;
    }

    if (w[num-1] > Total_W)
    {
        return knapSack(Total_W,w,v,num-1);
    }
    else
    {
        return max( v[num-1]+knapSack(Total_W-w[num-1],w,v,num-1), knapSack(Total_W,w,v,num-1) );
    }

}


int main()
{
    int Total_W=8,num = 4;
	int v[] = {1,2,5,6};
	int w[] = {2,3,4,5};
	printf("%d", knapSack(Total_W,w,v,num));
	return 0;
}

