/**
 * @description: 单链表的链式存储 带头结点
 * @author Kenton
 * @date 2023/11/13 9:48
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;

// 定义单链表结点类型
typedef struct LNode {
    // 每个结点存放一个数据元素
    Element data;
    // 指针指向下一个结点
    struct LNode *next;
} LNode, *LinkList;


// 初始化一个空的链表 带头结点
bool InitList(LinkList &L) {
    // 分配一个头结点
    L = (LNode *) malloc(sizeof(LNode));
    // 内存分配失败
    if (L == NULL) {
        return false;
    }
    // 头结点之后暂时没有结点
    L->next = NULL;
    return true;
}

// 判断带头结点的单链表是否为空
bool EmptyLink(LinkList L) {
    if (L->next == NULL) {
        return true;
    } else {
        return false;
    }
}

//前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode *p, Element e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
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
bool InsertNextNode(LNode *p, Element e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    // 用结点s保存数据元素e
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


// 按位查找 返回第i个元素 不带头结点
LNode *GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    // 指针p指向当前扫描的结点
    LNode *p;
    // 指针p指向的是第几个结点
    int j = 0;
    // L指向头结点 头结点就是第0个结点 不存数据
    p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 在第i个位置插入元素e 带头结点
bool ListInsert(LinkList &L, int i, Element e) {
    // 第0个结点是头结点
    if (i < 1) {
        return false;
    }

    /*  // 指针p指向当前扫描到的结点
      LNode *p;
      // 当前p指向的是第几个结点
      int j = 0;
      // L指向头结点 头结点是第0个结点 不存数据
      p = L;
      // 循环找到i-1个结点
      while (p != NULL && j <i -1){
          p = p->next;
          j++;
      }*/

    LNode *p = GetElem(L, i - 1);
    /* // while循环结束 p指针存放 i-1位置结点的地址 如果为NULL程序报错
     if (p == NULL){
         return false;
     }
     // 生成一个节点
     LNode *s = (LNode*) malloc(sizeof(LNode));
     s->data = e;
     s->next = p->next;
     // 将结点s连接到p之后
     p->next = s;
     // 插入成功
     return true;*/
    return InsertNextNode(p, e);
}


// 按位序删除 带头结点
bool ListDelete(LinkList &L, int i, Element &e) {
    // 第0个结点是头结点 不可删
    if (i < 1) {
        return false;
    }

    /*// 指针p指向当前扫描到的结点
    LNode *p;
    // 当前p指向的是第几个结点
    int j = 0;
    // L指向头结点 头结点是第0个结点
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }*/

    LNode *p = GetElem(L,i-1);
    // i值不合法
    if (p == NULL) {
        return false;
    }
    if (p->next == NULL) {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}


/**
 * 删除指定结点p
 * @param L 传入链表的指针
 * @param p 指定结点p
 * @return
 */
bool DeleteNode(LinkList &L, LNode *p) {
    // 判断链表是否为空
    if (L == NULL) {
        return false;
    }
    // 如果要删除的结点是头结点
    if (p == L) {
        // 将头结点的指针指向下一个结点
        L = L->next;
        // 释放被删除结点的内存空间
        free(p);
        return true;
    }

    // 头结点地址赋值给指针*pre
    LNode *pre = L;
    // 遍历找到要删除结点的前一个结点
    while (pre->next != NULL && pre->next != p) {
        pre = pre->next;
    }
    // 如果找不到前一个结点或者前一个结点已经到达链表末尾
    if (pre->next == NULL) {
        return false;
    }
}

// 按值查找 找到数据域e的结点
LNode * LocateElem(LinkList L,Element e){
    LNode *p = L->next;
    // 从第1个结点开始查找数据域位e的结点
    while (p != NULL && p->data != e){
        p = p->next;
    }
    // 找到后返回该结点的指针 否则返回NULL
    return p;
}