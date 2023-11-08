/**
 * @description: 栈的链式存储
 * @author Kenton
 * @date 2023/11/6 10:34
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"
#define MaxSize 10

typedef int Element;
typedef struct LinkNode{
    // 数据域
    Element data;
    // 指针域
    struct LinkNode *next;
}*LiStack; // 栈类型定义

/**
 * 初始化链栈
 * @param s
 */
void Init_LinkStack(LiStack &s){
    s = (LinkNode *) malloc(sizeof(LinkNode));
    s->next = NULL;
}

/**
 * 头插法入栈
 * @param s 链表
 * @param e 入栈元素
 */
void Push(LiStack &s,Element e){
    LinkNode *p;
    p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = e;
    p->next = s;
    s = p;
}

/**
 * 栈链出栈操作 栈顶指针是头指针的下一个 所以将其往后挪一位就可
 * @param s
 * @return
 */
bool Pop(LiStack &s){
    LinkNode *p;
    if (s == NULL){
        printf("栈空\n");
        return false;
    } else{
        p = s;
        // 往后挪一位
        s = p->next;
        free(p);
        return true;
    }
}

/**
 * 查看栈顶元素
 * @param s
 * @return
 */
bool GetTop(LiStack &s,Element &e){
    if (s == NULL){
        printf("栈空\n");
        return false;
    } else{
        e = s->data;
        printf("%d",e);
        return true;
    }
}

/**
 * 打印链表
 * @param s
 */
void show_LinkStack(LiStack &s){
    LinkNode *p;
    p = s;

    while (p->next != NULL){
        printf("%6d\n",p->data);
        p = p->next;
    }
}