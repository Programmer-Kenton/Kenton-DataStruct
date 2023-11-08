/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/6 18:57
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
typedef struct {
    // 队列的头指针
    LinkNode *front;
    // 队列的尾指针
    LinkNode *rear;
}LinkQueue;

/**
 * 初始化带头结点链表
 * @param Q
 */
void InitQueue(LinkQueue &Q){
    // 初始化 front rear都指向头结点
    Q.front = Q.rear = (LinkNode*) malloc(sizeof(LinkNode));
    // 头结点下一个节点指向NULL
    Q.front->next = NULL;
}

/**
 * 判断头结点是否为空
 * @param Q
 * @return
 */
bool isEmpty(LinkQueue Q){
    if (Q.front == Q.rear or Q.front->next == NULL){
        return true;
    } else{
        return false;
    }


}

/**
 * 新元素入队 带头结点
 * @param Q
 * @param x
 */
void EnQueue(LinkQueue &Q,Element x){
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    // 新节点插入到rear之后
    Q.rear->next = s;
    // 修改表尾指针
    Q.rear = s;
}

/**
 * 队头元素出队 带头结点
 * @param Q
 * @param x
 * @return
 */
bool Dequeue(LinkQueue &Q,Element &x){
    if (Q.front == Q.rear){
        // 空队
        return false;
    }
    LinkNode *p = Q.front->next;
    // 用变量x返回队头元素
    x = p->data;
    // 修改头结点的next指针
    Q.front->next = p->next;
    // 此次是最后一个结点出队
    if (Q.rear == p){
        // 修改rear指针
        Q.rear = Q.front;
    }
    // 释放结点空间
    free(p);
    return true;
}