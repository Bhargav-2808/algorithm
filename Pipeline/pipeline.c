#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct LinkList *head=NULL;
struct LinkList{
    int data;
    struct LinkList *next;
};


struct stack{
    int stk[20];
    int top;
}s;

struct stack1{
    int stk1[20];
    int top1;
}s1;

struct queue{
    int que[10];
    int front;
    int rear;
}q;

void init(struct stack *a,struct queue *b,struct stack1 *c){
    a->top=-1;
    c->top1=-1;
    b->front=-1;
    b->rear=-1;
}

void Insert(int key){
    struct LinkList *new;
    struct LinkList *ptr;
    new=(struct LinkList*)malloc(sizeof(struct LinkList));
    new->data=key;
    new->next=NULL;
    ptr=new;
    ptr->next=head;
    head=ptr;
}

int Delete(){
    struct LinkList *ptr,*temp;
    int popItem;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    popItem=ptr->data;
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        temp=ptr->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    temp=temp->next;
    free(temp);
    return popItem;
}
int Length(){
    int count=0;
    struct LinkList *ptr,*temp;
    ptr=head;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    return count;
}

void Display(){
    struct LinkList *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
}



void Push1(struct stack *a, int data){
    if(a->top==19){
        printf("\n......Stack Overflow......\n");
    }
    else{
        a->top++;
        a->stk[a->top]=data;
    }
}

void StackDisplay1(struct stack *a){
    for(int i=a->top;i>=0;i--){
        printf("\n\t%d",a->stk[i]);
    }
}

void Push2(struct stack1 *c, int data){
    if(c->top1==19){
        printf("\n......Stack Overflow......\n");
    }
    else{
        c->top1++;
        c->stk1[c->top1]=data;
    }
}

void StackDisplay2(struct stack1 *c){
    for(int i=c->top1;i>=0;i--){
        printf("\n\t%d",c->stk1[i]);
    }
}

void enqueue(struct queue *b,int data){
    if(b->front==-1){
        b->front=0;
    }
    b->rear=(b->rear+1)%10;
    b->que[b->rear]=data;
}

int dequeue(struct queue *b){
    int data=b->que[b->front];
    if(b->front==b->rear) {
      b->front = -1;
      b->rear = -1;
    }
    else {
      b->front=(b->front+1)%10;
    }
    return data;
}

void queueDisplay(struct queue *b){
    //for(int i=b->front;i!=b->rear;i=(i+1)%10){
    if(b->rear>=b->front){
        for(int i=b->front;i<=b->rear;i++){
            printf("\t%d",b->que[i]);
        }
    }
    else{
        for(int i=b->front;i<10;i++){
            printf("\t%d",b->que[i]);
        }
        for(int i=0;i<=b->rear;i++){
            printf("\t%d",b->que[i]);
        }
    }
}

void Stack1Data(){
    int userData;
    printf("\n.........LINKED-LIST-DATA.........\n");
    Display();
    printf("\n");
    printf("\nEnter The Data For PipeLine, press 00 to quit:- ");
    scanf("%d",&userData);
    if(userData==00 || userData==00){
        exit(1);
    }
    Insert(userData);
    int llData=Delete();
    int queData=dequeue(&q);
    enqueue(&q,llData);
    Push1(&s,queData);
    printf("\n.........STACK-1-DATA.........\n");
    StackDisplay1(&s);
    printf("\n");
    printf("\n.........QUEUE-DATA.........\n");
    queueDisplay(&q);
    printf("\n");
}

void Stack2Data(){
    int userData;
    printf("\n.........LINKED-LIST-DATA.........\n");
    Display();
    printf("\n");
    printf("\nEnter The Data For PipeLine, press 0 to quit:- ");
    scanf("%d",&userData);
    if(userData==0){
        exit(1);
    }
    Insert(userData);
    int llData=Delete();
    int queData=dequeue(&q);
    enqueue(&q,llData);
    Push2(&s1,queData);
    printf("\n.........STACK-2-DATA.........\n");
    StackDisplay2(&s1);
    printf("\n");
    printf("\n.........QUEUE-DATA.........\n");
    queueDisplay(&q);
    printf("\n");
}

void main(){
    int LinkListRange,count=1;
    char choice="p";
    init(&s,&q,&s1);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    enqueue(&q,70);
    enqueue(&q,80);
    enqueue(&q,90);
    enqueue(&q,100);
    printf("\n.........QUEUE-DATA.........\n");
    queueDisplay(&q);
    printf("\n");
    LinkListRange=Length();
    while(LinkListRange!=5){
        int data;
        printf("\nEnter Data To Insert Into LL:- ");
        scanf("%d",&data);
        Insert(data);
        LinkListRange=Length();
    }
    printf("\n");
    printf("\nPipeLine Begins.........");
    printf("\n");

    while(choice!="Q"){
        if(count%2==0){
            Stack1Data();
            count++;
        }
        else{
            Stack2Data();
            count++;
        }
    }
}


