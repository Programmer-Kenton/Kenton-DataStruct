/**
 * @description: ���ö��г�������
 * @author Kenton
 * @date 2023/11/14 9:15
 * @version 1.0
 */


#include "stdio.h"
#include "stdlib.h"

// ��������������
#define MaxSize 10

typedef int Element;

typedef struct peopleQue {
    // ����Ԫ��
    Element *base;
    // ��ͷָ��
    int front;
    // ��βָ��
    int rear;
    // ��������
    int size;
} peopleQue;


// ��ʼ������
bool InitQueue(peopleQue &Q) {
    Q.base = (Element *) malloc(MaxSize * sizeof(Element));
    if (Q.base == NULL) {
        return false;
    }
    Q.front = 0;
    Q.rear = 0;
    Q.size = MaxSize;
    return true;
}

// ���ٶ���
void DestroyQueue(peopleQue *Q) {
    free(Q->base);
    free(Q);
}


// �ж϶����Ƿ�Ϊ��
bool isEmpty(peopleQue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
}


// �ж϶����Ƿ���
bool isFull(peopleQue Q) {
    if ((Q.rear + 1) % MaxSize == Q.front) {
        return true;
    }
}

// ջ���
bool EnQueue(peopleQue &Q, Element e) {
    if (isFull(Q)) {
        return false;
    }
    // ��e���뵽��β
    Q.base[Q.rear] = e;
    // ��βָ��+1 ȡģ
    Q.rear = (Q.rear + 1) % Q.size;
    return true;
}

// ջ����
bool DeQueue(peopleQue &Q, Element &e) {
    // �ж϶ӿ�
    if (isEmpty(Q)) {
        return false;
    }
    e = Q.base[Q.front];
    // ��ͷָ�����
    Q.front = (Q.front + 1) % Q.size;
    return true;
}

void OutPrint(peopleQue &ManQ, peopleQue &WomanQ, Element man[], Element woman[]) {
    // ��ʼ����������
    InitQueue(ManQ);
    // ��ʼ��Ů������
    InitQueue(WomanQ);
    // ��������������Ԫ��
    Element manElement;
    // ����Ů��������Ԫ��
    Element womanElement;
    // ͳ��������Ÿ���
    Element size_man = (sizeof(man) / sizeof(man[0]));
    // ͳ��Ů����Ÿ���
    Element size_woman = (sizeof(woman) / sizeof(woman[0]));

    // ����������
    for (int i = 0; i < size_man; ++i) {
        EnQueue(ManQ, man[i]);
    }

    // Ů��������
    for (int i = 0; i < size_woman; ++i) {
        EnQueue(WomanQ, woman[i]);
    }

    // ȡ��Ů�� ��Ÿ��� ������
    Element max = size_man > size_woman ? size_man : size_woman;
    // ȡ��Ů�� ��Ÿ��� ��С����
    Element min = size_man < size_woman ? size_man : size_woman;

    // ����������
    int num = 0;
    printf("�����뽻��������:\n");
    scanf("%d", &num);
    for (int i = 1; i <= min; ++i) {
        printf("��%d����Խ���:\n", i);
        DeQueue(ManQ, manElement);
        EnQueue(ManQ, manElement);
        DeQueue(WomanQ, womanElement);
        EnQueue(WomanQ, womanElement);
        printf("<%d,%d>", manElement, womanElement);
    }
    for (int i = 1; i <= max - min; ++i) {
        printf("��%d����Խ���:\n", min + i);
        DeQueue(ManQ, manElement);
        EnQueue(ManQ, manElement);
        DeQueue(WomanQ, womanElement);
        EnQueue(WomanQ, womanElement);
        printf("<%d,%d>", manElement, womanElement);
    }
}

int main() {
    // ��������
    peopleQue ManQ;
    // Ů������
    peopleQue WomanQ;

    // ������Ÿ���
    Element manTotal;
    // Ů����Ÿ���
    Element womanTotal;

    printf("������������Ÿ���:\n");
    scanf("%d", &manTotal);

    printf("������Ů����Ÿ���:\n");
    scanf("%d", &womanTotal);

    // ���������ŵ�����
    int man[manTotal];
    // ���Ů����ŵ�����
    int woman[womanTotal];

    // ���ڽ��մ���ı��ֵ
    Element e;
    printf("�����������ı��:\n");

    for (int i = 0; i < manTotal; i++) {
        scanf("%d", &e);
        man[i] = e;
    }

    printf("������Ů���ı��:\n");

    for (int j = 0; j < womanTotal; j++) {
        scanf("%d", &e);
        woman[j] = e;
    }

    OutPrint(ManQ, WomanQ, man, woman);

    // ������������
    DestroyQueue(&ManQ);
    // ����Ů������
    DestroyQueue(&WomanQ);
}