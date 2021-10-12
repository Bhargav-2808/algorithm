#include<stdio.h>
void knapsack(int num,float Weight[],float Profit[],int cap)
{
    int i;
    float total_profit=0,C[num];
    for(i=0;i<num;i++)
    {
        if(cap>0 && Weight[i]<=cap)
        {
            cap-=Weight[i];
            total_profit+=Profit[i];
            //printf(" %d \n ", total_profit);
            C[i]=1;
            printf("\n%f",C[i]);
        }
        else if(cap>0)
        {
            float temp=(Profit[i]/Weight[i]);
            total_profit+=((temp)*(cap));
            //printf(" %d \n ", total_profit);
            C[i]=cap/Weight[i];
            cap=0;
            printf("\n%f",C[i]);
            break;
        }
    }
    printf("\nTotal profit:%f ",total_profit);
}

void main()
{
    int n,i,j,capacity;
    float W[20],P[20],R[20],temp;

    printf("Enter no of object:");
    scanf("%d",&n);

    printf("\nEnter the capacity of bag:");
    scanf("%d",&capacity);

    printf("\nEnter weight of the objects ");
    for(i=0;i<n;i++)
    {
        printf("\nWeight of obj %d:",i+1);
        scanf("%f",&W[i]);

    }
    printf("\nEnter profit of the object");
    for(i=0;i<n;i++)
    {
        printf("\nProfit of obj %d:",i+1);
        scanf("%f",&P[i]);

    }

    for(i=0;i<n;i++)
    {
        R[i] = P[i]/W[i];

    }




    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(R[i]<R[j])
            {
                temp=R[j];
                R[j]=R[i];
                R[i]=temp;

                temp=W[j];
                W[j]=W[i];
                W[i]=temp;

                temp=P[j];
                P[j]=P[i];
                P[i]=temp;
            }
        }
    }
    knapsack(n,W,P,capacity);

}
