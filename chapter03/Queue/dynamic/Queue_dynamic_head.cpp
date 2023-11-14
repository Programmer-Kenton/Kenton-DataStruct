/**
 * @description: 队列的链式实现 带头结点
 * @author Kenton
 * @date 2023/11/14 8:08
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;

// 链式队列结点
typedef struct LinkNode{
    Element data;
    struct LinkNode *next;
}LinkNode;

// 链式队列
typedef struct{
    LinkNode *front;
    LinkNode *rear;
}LinkQueue;

// 初始化队列 带头结点
void InitQueue(LinkQueue &Q){
    // 初始化时 front rear 都指向头结点 头结点再指向NULL
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    // Q.rear->next = NULL; 也可以
    Q.front->next = NULL;
}

// 判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if (Q.front == Q.rear){
        return true;
    } else{
        return false;
    }
}

// 带头结点 入队
void EnQueue(LinkQueue &Q,Element e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    // 新节点插入到rear之后
    Q.rear->next = s;
    // 修改表尾指针
    Q.rear = s;
}

// 出队 带头结点
bool DeQueue(LinkQueue &Q,Element &e){
    // 空队
    if (Q.front == Q.rear){
        return false;
    }
    // 取出队头元素
    e = Q.front->next->data;
    // 头结点指向下一个节点
    Q.front->next = Q.front->next->next;
    // 释放空间
    free(Q.front->next);
    return true;
}