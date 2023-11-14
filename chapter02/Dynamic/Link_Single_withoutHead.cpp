/**
 * @description: 单链表的链式存储 不带头结点
 * @author Kenton
 * @date 2023/11/13 9:41
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;

// 定义单链表结点类型
typedef struct LNode{
    // 每个结点存放一个数据元素
    Element data;
    // 指针指向下一个结点
    struct LNode *next;
}LNode,*LinkList;

// 初始化一个空的单链表 不带头结点
bool InitList(LinkList &L){
    // 空表 暂时没有任何结点
    L = NULL;
    return true;
}

// 判断单链表是否为空
bool EmptyLink(LinkList L){
    // 指针置为空
    if (L == NULL){
        return true;
    } else{
        return false;
    }
}


//前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode *p,Element e){
    if (p == NULL){
        return false;
    }
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if (s == NULL){
        return false;
    }
    s->next = p->next;
    p->next = s;
    // p中元素复制到s
    s->data = p->data;
    // e覆盖p中元素 实现在p之前插入元素e
    p->data = e;
    return true;
}

// 后插操作:在p结点之后插入元素e
bool InsertNextNode(LNode *p,Element e){
    if (p == NULL){
        return false;
    }
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if (s == NULL){
        return false;
    }
    // 用结点s保存数据元素e
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头结点链表 在第i个位置插入
bool ListInsert(LinkList &L,int i,Element e){
    // 没有第0个结点 只有第一个
    if (i < 1){
        return false;
    }
    // 第一个结点的插入操作与其他结点不同
    if (i == 1){
        LNode *s = (LNode*) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        // 头指针指向新结点
        L = s;
        return true;
    }
    // 指针p指向扫描到的结点
    LNode *p;
    // 当前p指向的是第几个结点
    int j = 1;
    p = L;
    // 循环找到第i-1个结点
    while (p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    return InsertNextNode(p,e);
}


/**
 * 按位序删除不带头结点的单链表中的第i个结点
 * @param L 单链表的头指针
 * @param i 要删除的结点的位置
 * @param e 被删除的结点的值
 * @return bool 删除成功返回true，否则返回false
 */
bool ListDelete(LinkList &L,int i,Element &e){
    if (L == NULL){
        return false;
    }
    if (i < 0){
        return false;
    }
    // 查找被删除的结点
    LNode *p = L;
    LNode *q = NULL;
    int count = 1;
    while(p != NULL && count < i){
        q = p;
        p = p->next;
        count++;
    }

    // 如果位置超出列表末尾
    if (p == NULL){
        return false;
    }

    // 删除结点
    q->next = p->next;
    free(p);
    return true;
}


/**
 * 删除指定节点p
 * @param L 单链表的头指针
 * @param p 要删除的节点
 * @return bool 删除成功返回true，否则返回false
 */
bool DeleteNode(LinkList &L, LNode *p){
    if (L == NULL){
        return false;
    }
    // 找到前一个节点
    LNode *pre = L;
    while (pre->next != NULL && pre->next != p){
        pre = pre->next;
    }
    if (pre->next == NULL){
        return false;
    }
    // 释放被删除节点的内存空间
    free(p);
    // 将前一个节点的指针指向下一个节点
    pre->next = p->next;
    return true;
}