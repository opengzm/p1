#include <stdio.h>
#define null 0
#include <iostream>
using namespace std;

struct node
{
    /* data */
    int data;
    node *next;
};

#include <memory>
typedef  std::shared_ptr<int> INTPTRS;
#include <pthread.h>


node* reverseList(node* head) 
{
    if(head == null || head->next == null)
        return head;
    node* last = reverseList(head->next);
    head->next->next = head;
    head->next = null;
    printf("last %d.\n",head->data);
    return last;
}

void doCal()
{
    node *head = new node;
    head->data = 0;
    head->next = null;
    node *p = head;

    for(int i= 1;i< 10;i++)
    {
        printf("%d.",head->data);
        node *tmp = new node;
        tmp->data = i;
        tmp->next = null;
        head->next = tmp;
        head = tmp;
    }
    //reverseList(p);

    head->next = p;
    p = p->next->next;//起始位置

    while(p != p->next)
    {
        p->next->next = p->next->next->next;
        p = p->next->next;
    }
    printf("\n %d.",p->data);
}

int main()
{
    INTPTRS iptr =  std::make_shared<int>(42);
    printf("hello world! %d. \n",*iptr);
    doCal();
    return 1;
}