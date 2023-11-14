/**
 * @description: ˳����е�ʵ�ֺ�����
 * @author Kenton
 * @date 2023/11/14 9:38
 * @version 1.0
 */

#include <stdio.h>

#include <stdlib.h>


#define OK  1

#define ERROR  0

#define OVERFLOW -2

#define TRUE 1

#define FALSE 0

// �洢�ռ�ĳ�ʼ������
#define MaxSize 30

typedef int ElemType;

typedef int Status;

//----- ���е�˳��洢��ʾ -----



typedef struct {
    // ��̬�����Ŷ���Ԫ�� �����Ĵ洢�ռ��СMaxSize * sizeof(ElementType)
    ElemType *base;
    // ͷָ��
    int front;
    // βָ��
    int rear;
    // ���е�����
    int size;

} SqQueue;


// ����һ���ն��� Q
Status InitQueue(SqQueue &Q) {
    // ��̬����洢�ռ�
    Q.base = (ElemType *) malloc(MaxSize * sizeof(ElemType));
    // ��̬����ʧ��
    if (!Q.base) exit(OVERFLOW);
    // ��ʼ��ͷβָ�� ָ��0
    Q.front = Q.rear = 0;
    // ���ö��е��������
    Q.size = MaxSize;
    return OK;

}

// ���ٶ���
Status DestroyQueue(SqQueue *Q) {
    // �ͷŴ洢�ռ�
    if (Q->base) free(Q->base);
    free(Q);
    return OK;
}


//�ж����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q) {
    // ͷβָ����� �ӿ�
    if (Q.rear == Q.front) return TRUE;

    else return FALSE;

}




//��Ӻ���
Status EnQueue(SqQueue &Q, ElemType e) {
    // ��������
    if ((Q.rear + 1) % Q.size == Q.front) {
        return false;
    }

    // ��e���뵽��β
    Q.base[Q.rear] = e;
    // ��βָ��+1 ȡģ
    Q.rear = (Q.rear + 1) % Q.size;
    return OK;
}


//���Ӻ���
Status DeQueue(SqQueue &Q, ElemType &e) {
    // �ж϶ӿ�
    if (Q.rear == Q.front) {
        return false;
    }
    e = Q.base[Q.front];
    // ��ͷָ�����
    Q.front = (Q.front + 1) % Q.size;
    return OK;
}


//���ѭ�����к���
void OutQueue(SqQueue Q) {
    ElemType e;

    if (QueueEmpty(Q)) {

        printf("����һ���ն��У�");

    } else {

        while (!QueueEmpty(Q)) {

            DeQueue(Q, e);

            printf("%6d", e);

        }

        printf("\n");

    }

}

//������

int main() {
    SqQueue q;

    int cord;

    ElemType a;

    printf("��һ��ʹ�ñ����ʼ����\n");

    do {

        printf("\n ���˵� \n");

        printf(" 1 ��ʼ��ѭ������ ");

        printf(" 2 ����һ��Ԫ�� ");

        printf(" 3 ����һ��Ԫ�� ");

        printf(" 4 ������������ ");

        printf("\n------------------------------------------------------------------\n");

        printf("����������ѡ��( 1, 2, 3, 4)");

        scanf("%d", &cord);

        printf("\n");

        switch (cord) {

            case 1:

                InitQueue(q); //���ó�ʼ���㷨;

                OutQueue(q);

                break;

            case 2:

                printf("������Ҫ���������Ԫ�أ�a=");

                scanf("%d", &a);

                EnQueue(q, a); //���ý����㷨;

                printf("%d ����֮��Ķ��У�", a);

                OutQueue(q);

                break;

            case 3:

                DeQueue(q, a); //���ó����㷨;

                printf("��ͷԪ�� %d ����֮��Ķ��У�", a);

                OutQueue(q);

                break;

            case 4:

                exit(0);

        }

    } while (cord <= 4);

}