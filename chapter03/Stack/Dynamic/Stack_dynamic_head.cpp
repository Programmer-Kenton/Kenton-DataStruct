/**
 * @description: 链栈带头结点
 * @author Kenton
 * @date 2023/11/12 1:37
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;


// 定义链表结构体
typedef struct LinkNode {
    // 数据域
    Element data;
    // 指向下一个结点的指针域
    struct LinkNode *next;
}LinkNode,*LiStack;


// 初始化带头结点的链栈
bool InitStack(LiStack &S){
    S = (LinkNode*) malloc(sizeof(LinkNode));
    if (S == NULL){
        return false;
    }
    S->next = NULL;
    return true;
}

// 判断栈是否空
bool StackEmpty(LiStack S){
    if (S->next == NULL){
        return true;
    } else{
        return false;
    }
}

// 带头结点 入栈
bool Push(LiStack &S,Element e){
    // 头插法
    LinkNode *p = (LinkNode*) malloc(sizeof(LinkNode));
    if (!p){
        return false;
    }
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}


// 带头结点栈的出栈
bool Pop(LiStack &S,Element &e){
    if (StackEmpty(S)){
        return false;
    }
    LinkNode *q = S->next;
    e = q->data;
    S->next = q->next;
    free(q);
}

// 读取栈顶元素
bool GetTop(LiStack S,Element e){
    if (StackEmpty(S)){
        return false;
    }
    e = S->next->data;
    return true;
}

int main() {
    LiStack S;
    Element e;
    InitStack(S); // 初始化栈
    Push(S, 1); // 入栈
    Push(S, 2);
    Push(S, 3);
    GetTop(S, e); // 读取栈顶元素
    printf("栈顶元素为：%d\n", e);
    Pop(S, e); // 出栈
    Pop(S, e);
    if (StackEmpty(S)){
        printf("栈为空");
    }
    return 0;
}
