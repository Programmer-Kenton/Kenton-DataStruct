/**
 * @description: 栈的链式存储 不带头结点
 * @author Kenton
 * @date 2023/11/12 0:30
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"


typedef int Element;

// 定义链表结点结构体
typedef struct LinkNode{
    // 数据域
    Element data;
    // 指针域
    struct LinkNode *next;
}LinkNode,*LiStack;

// 不带头结点初始化链栈
bool InitStack(LiStack &S){
    // 头指针指向NULL
    S = NULL;
    return true;
}

// 判断栈是否空
bool StackEmpty(LiStack S){
    if (S == NULL){
        return true;
    } else{
        return false;
    }
}

// 入栈
bool Push(LiStack &S, Element e){
    // 头插法入栈
    LinkNode *p = (LinkNode*) malloc(sizeof(LinkNode));
    if (!p){
        return false;
    }
    p->data = e;
    // 新生成的结点指向L
    p->next = S;
    // 将p赋值给头指针
    S = p;
    return true;
}

// 出栈
bool Pop(LiStack &S,Element &e){
    if (S == NULL){
        return false;
    }
    e = S->data;
    LinkNode *q;
    q = S;
    S = S->next;
    free(q);
    return true;
}

// 读取栈顶元素
bool GetTop(LiStack S,Element &e){
    if (S == NULL){
        return false;
    }
    e = S->data;
    return true;
}

int main(){
    Element e = -1;
    LiStack S;
    InitStack(S);
    Push(S,6);
    GetTop(S,e);
    printf("%d\n",e);
    if (StackEmpty(S)){
        printf("栈为空\n");
    } else{
        printf("栈非空\n");
    }
}

