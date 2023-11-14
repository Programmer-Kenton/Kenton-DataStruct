/**
 * @description: ջ����ʽ�洢 ����ͷ���
 * @author Kenton
 * @date 2023/11/12 0:30
 * @version 1.0
 */

#include "stdio.h"
#include "stdlib.h"


typedef int Element;

// ����������ṹ��
typedef struct LinkNode{
    // ������
    Element data;
    // ָ����
    struct LinkNode *next;
}LinkNode,*LiStack;

// ����ͷ����ʼ����ջ
bool InitStack(LiStack &S){
    // ͷָ��ָ��NULL
    S = NULL;
    return true;
}

// �ж�ջ�Ƿ��
bool StackEmpty(LiStack S){
    if (S == NULL){
        return true;
    } else{
        return false;
    }
}

// ��ջ
bool Push(LiStack &S, Element e){
    // ͷ�巨��ջ
    LinkNode *p = (LinkNode*) malloc(sizeof(LinkNode));
    if (!p){
        return false;
    }
    p->data = e;
    // �����ɵĽ��ָ��L
    p->next = S;
    // ��p��ֵ��ͷָ��
    S = p;
    return true;
}

// ��ջ
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

// ��ȡջ��Ԫ��
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
        printf("ջΪ��\n");
    } else{
        printf("ջ�ǿ�\n");
    }
}

