#include<stdio.h>
#include<conio.h>


struct stack {
    int s[20];
    int top;
}s;


void intialize(struct stack *a)
{

    a->top=-1;
}

void push(struct stack *a, int data)
{
    if(a->top==19)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        a->top++;
        a->s[a->top]=data;
    }
}

void pop(struct stack *a)
{
    if(a->top==-1)
    {
        printf("Stack is Underflow");

    }
    else
    {
        int pe;
        pe=a->s[a->top];
        a->top--;
        printf("%d is removed", pe);
    }
}

void peep(struct stack *a, int index)
{
    if((a->top-index+1)<0)
    {
        printf("Invalid Index");
    }
    else
    {
        printf("\nData-%d is at %d \n" ,a->s[a->top-index+1],index );
    }
}

void change(struct stack *a,int data,int loc)
{
    if((a->top-loc+1)<0)
    {
        printf("Invalid Index\n");
    }
    else
    {
        a->s[a->top-loc+1]=data;
        printf("Element at Index %d is Change to %d\n" ,loc,data );
    }
}

void display(struct stack *a)
{
    int i;
    for(i=a->top;i>=0;i--)
    {
        printf("%d\n" , a->s[i]);
    }
}
void main()
{
    intialize(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    pop(&s);
    peep(&s,2);
    change(&s,5,2);
    display(&s);
}
