/**
 * @description: 队列的链式实现 不头结点
 * @author Kenton
 * @date 2023/11/14 8:08
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;

// 链式队列结点
typedef struct LinkNode {
    Element data;
    struct LinkNode *next;
} LinkNode;

// 链式队列
typedef struct {
    LinkNode *front;
    LinkNode *rear;
} LinkQueue;


// 不带头结点的链式队列初始化
void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = NULL;
}

// 判断队列是否为空
bool isEmpty(LinkQueue Q) {
    if (Q.front == NULL) {
        return true;
    } else {
        return false;
    }
}

// 不带头结点 入队
void EnQueue(LinkQueue &Q, Element e) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    // 在空队列中插入第一个元素
    if (Q.front == NULL) {
        // 修改队头队尾指针
        Q.front =Q.rear = s;
    } else{
        // 新节点插入到rear结点之后
        Q.rear->next = s;
        // 修改rear指针
        Q.rear = s;
    }
}

// 不带头结点 出队
bool DeQueue(LinkQueue &Q, Element &e){
    // 空队列
    if (Q.front == NULL) {
        return false;
    } else {
        // p指向此次出队的结点
        LinkNode *p = Q.front;
        e = p->data;
        // 头指针后移
        Q.front = p->next;
        // 尾指针指向p 最后一个结点出栈
        if (Q.rear == p){
            Q.rear = NULL;
            Q.front = NULL;
        }
        free(p);
        return true;
    }
}