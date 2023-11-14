/**
 * @description: ��ջ��ͷ���
 * @author Kenton
 * @date 2023/11/12 1:37
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"

typedef int Element;


// ��������ṹ��
typedef struct LinkNode {
    // ������
    Element data;
    // ָ����һ������ָ����
    struct LinkNode *next;
}LinkNode,*LiStack;


// ��ʼ����ͷ������ջ
bool InitStack(LiStack &S){
    S = (LinkNode*) malloc(sizeof(LinkNode));
    if (S == NULL){
        return false;
    }
    S->next = NULL;
    return true;
}

// �ж�ջ�Ƿ��
bool StackEmpty(LiStack S){
    if (S->next == NULL){
        return true;
    } else{
        return false;
    }
}

// ��ͷ��� ��ջ
bool Push(LiStack &S,Element e){
    // ͷ�巨
    LinkNode *p = (LinkNode*) malloc(sizeof(LinkNode));
    if (!p){
        return false;
    }
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}


// ��ͷ���ջ�ĳ�ջ
bool Pop(LiStack &S,Element &e){
    if (StackEmpty(S)){
        return false;
    }
    LinkNode *q = S->next;
    e = q->data;
    S->next = q->next;
    free(q);
}

// ��ȡջ��Ԫ��
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
    InitStack(S); // ��ʼ��ջ
    Push(S, 1); // ��ջ
    Push(S, 2);
    Push(S, 3);
    GetTop(S, e); // ��ȡջ��Ԫ��
    printf("ջ��Ԫ��Ϊ��%d\n", e);
    Pop(S, e); // ��ջ
    Pop(S, e);
    if (StackEmpty(S)){
        printf("ջΪ��");
    }
    return 0;
}
