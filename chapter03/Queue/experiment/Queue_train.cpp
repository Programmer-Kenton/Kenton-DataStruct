/**
 * @description: ���ö���ʵ�ֳ���������⡣
 * @author Kenton
 * @date 2023/11/14 9:15
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
#define MAXQSIZE 30

typedef char ElemType;

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
    Q.base = (ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
    // ��̬����ʧ��
    if (!Q.base) exit(OVERFLOW);
    // ��ʼ��ͷβָ�� ָ��0
    Q.front = Q.rear = 0;
    // ���ö��е��������
    Q.size = MAXQSIZE;
    return OK;

}


// ���ٶ���
Status DestroyQueue(SqQueue *Q) {
    // �ͷŴ洢�ռ�
    free(Q->base);
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
        while (QueueEmpty(Q) == FALSE) {

            DeQueue(Q, e);
            printf("%6c", e);

        }

        printf("\n");

    }

}

void Arrange(SqQueue A, SqQueue &B, SqQueue &C) {
    ElemType e;
    int i = 0;
    // �����ն���B��C
    InitQueue(B);
    InitQueue(C);
    // ��A�е�Ԫ�ذ�����ֱ����B��C��
    for (i = 0; i < A.rear; i++) {
        if (A.base[i] == 'S') {
            EnQueue(B, A.base[i]);
        } else if (A.base[i] == 'H'){
            EnQueue(C, A.base[i]);
        }
    }
}


//������
int main() {
    SqQueue A, B, C;

    ElemType e;

    InitQueue(A);

    printf("����������S��Ӳ��H��һ����ϳ���:");

    for (scanf("%c", &e); e != '\n';) {

        EnQueue(A, e);

        scanf("%c", &e);

    }

    Arrange(A, B, C);

    printf("Ӳ������:");

    OutQueue(B);

    printf("���Գ���:");

    OutQueue(C);

    // ���ٶ���A
    DestroyQueue(&A);

    // ���ٶ���B
    DestroyQueue(&B);

    // ���ٶ���C
    DestroyQueue(&C);
}

