#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// 用链表来模拟，每次对最大的值进行拆分，拆分后插入新的拆分后的值
// TLE了，哭泣
struct node{
    int diff;
    struct node *next;
};


node *head;

void creatList(int N)
{
    int n,num1,num2;
    struct node *newnode, *temp;
    //temp = NULL;

    scanf("%d", &num1);
    for(n=2; n<=N; n++)
    {
        scanf("%d", &num2);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->diff = num2-num1;
        newnode->next = NULL;
        if(head==NULL)
        {
            head = newnode;    
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        num1 = num2;
    }
}

void insert()
{
    int max_value = 0;
    struct node *temp;
    struct node *newnode;
    temp = head;
    if(temp!=NULL)
    {
        for(temp=head; temp!=NULL; temp=temp->next)
        {
            if(temp->diff>max_value)
            {
                max_value = temp->diff;
            }
        }
    }
    else
    {
        printf("The list is empty!");
    }
    //printf("max_value is %d\n", max_value);

    // 找出最大值后，更改最大值节点的值，并增加一个新的节点
    temp = head;
    if(temp!=NULL)
    {
        for(temp=head; temp!=NULL; temp=temp->next)
        {
            //printf("temp->diff is %d\n", temp->diff);
            if(temp->diff == max_value)
            {
                //printf("Find it!\n");
                temp->diff = int(max_value/2);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->diff = max_value - temp->diff;
                newnode->next = temp->next;
                temp->next = newnode;
                max_value = 0;
                break;
            }
        }
    }
    else
    {
        printf("The list is empty!");
    }
}


int display()
{
    struct node *temp;
    int max_value = 0;
    temp = head;
    if(temp!=NULL)
    {
        for(temp=head; temp!=NULL; temp=temp->next)
        {
            if(temp->diff > max_value)
            {
                max_value = temp->diff;
            }
            /* printf("%d ", temp->diff); */
        }
    }
    else
    {
        printf("The list is empty!");
    }
    /* printf("\n"); */
    return max(1,max_value);
}

void distoryList()
{
    struct node *temp;
    while(head!=NULL)
    {
        temp=head->next;
        free(head);
        head = temp;
    }
}

int main()
{
    int T,t,N,n,K,k;
    head = NULL;
    scanf("%d", &T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d", &N, &K);
        creatList(N);
        for(k=1; k<=K; k++)
        {
            insert();
            display();
        }
        printf("Case #%d: %d\n", t, display());
        //清空链表，释放指针
        distoryList();
    }
}


