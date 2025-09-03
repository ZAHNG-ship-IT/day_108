#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>//包含bool的头文件
//这里创建的是两个，第一个是结构体u，内部放置了一个数值，一个该类型的指针变量
//结构体栈是放置了两个节点指针类型的指针变量，解引用就是两个节点类型的结构体。
typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;//STACK 指的是 structStack
//栈的创建

void init(PSTACK);
void push(PSTACK,int val);
void traverse(PSTACK);
int main()
{
    STACK S;
    init(&S);
    push(&S,1);
    push(&S,2);
    traverse(&S);

}
void init(PSTACK pS)
{
    pS ->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("分配失败");
    }
    else
    {
        pS -> pBottom = pS ->pTop;
        pS -> pTop-> pNext = NULL;
    }


}

void push(PSTACK pS,int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data =val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;

    return ;

}