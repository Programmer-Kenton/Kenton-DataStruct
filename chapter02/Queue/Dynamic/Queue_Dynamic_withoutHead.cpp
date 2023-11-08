/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/6 19:35
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
    // 记录队列的长度
    int length;
}LinkQueue;

/**
 * 初始化队列 不带头结点
 * @param Q
 */
void InitQueue(LinkQueue &Q){
    // 初始时 front、rear都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
    Q.length = 0;
}

/**
 * 判断队列是否为空 不带头结点
 * @param Q
 * @return
 */
bool isEmpty(LinkQueue Q){
    if (Q.front == NULL){
        return true;
    } else{
        return false;
    }
}

/**
 * 新元素入队 不带头结点
 * @param Q
 * @param x
 */
void EnQueue(LinkQueue &Q,Element x){
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    // 在空队列中插入第一个元素
    if (Q.front == NULL){
        // 修改队头尾指针
        Q.front = s;
        Q.rear = s;
    } else{
        // 新节点插入到rear结点之后
        Q.rear->next = s;
        // 修改rear指针
        Q.rear = s;
    }
    Q.length++;
}


// 出队 不带头结点
bool DeQueue(LinkQueue &Q,Element &x){
    if (Q.front == NULL){
        // 空队
        return false;
    }
    // p指向此次出队的结点
    LinkNode *p = Q.front;
    // 用变量x返回队头元素
    x = p->data;
    // 修改front指针
    Q.front = p->next;
    // 此次是最后一个结点出队
    if (Q.rear == p){
        // front指向NULL
        Q.front = NULL;
        // rear指向NULL
        Q.rear = NULL;
    }
    Q.length--;
    // 释放结点空间
    free(p);
    return true;
}