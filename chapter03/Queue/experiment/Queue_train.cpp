/**
 * @description: 利用队列实现车厢编组问题。
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

// 存储空间的初始分配量
#define MAXQSIZE 30

typedef char ElemType;

typedef int Status;

//----- 队列的顺序存储表示 -----


typedef struct {
    // 动态数组存放队列元素 连续的存储空间大小MaxSize * sizeof(ElementType)
    ElemType *base;
    // 头指针
    int front;
    // 尾指针
    int rear;
    // 队列的容量
    int size;

} SqQueue;


// 构造一个空队列 Q
Status InitQueue(SqQueue &Q) {
    // 动态分配存储空间
    Q.base = (ElemType *) malloc(MAXQSIZE * sizeof(ElemType));
    // 动态分配失败
    if (!Q.base) exit(OVERFLOW);
    // 初始化头尾指针 指向0
    Q.front = Q.rear = 0;
    // 设置队列的最大容量
    Q.size = MAXQSIZE;
    return OK;

}


// 销毁队列
Status DestroyQueue(SqQueue *Q) {
    // 释放存储空间
    free(Q->base);
    free(Q);
    return OK;
}


//判队列是否为空
Status QueueEmpty(SqQueue Q) {
    // 头尾指针相等 队空
    if (Q.rear == Q.front) return TRUE;

    else return FALSE;

}

//入队函数
Status EnQueue(SqQueue &Q, ElemType e) {
    // 队满爆错
    if ((Q.rear + 1) % Q.size == Q.front) {
        return false;
    }

    // 将e插入到队尾
    Q.base[Q.rear] = e;
    // 队尾指针+1 取模
    Q.rear = (Q.rear + 1) % Q.size;
    return OK;
}


//出队函数
Status DeQueue(SqQueue &Q, ElemType &e) {
    // 判断队空
    if (Q.rear == Q.front) {
        return false;
    }
    e = Q.base[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % Q.size;
    return OK;
}


//输出循环队列函数
void OutQueue(SqQueue Q) {
    ElemType e;

    if (QueueEmpty(Q)) {

        printf("这是一个空队列！");

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
    // 创建空队列B和C
    InitQueue(B);
    InitQueue(C);
    // 将A中的元素按规则分别放入B和C中
    for (i = 0; i < A.rear; i++) {
        if (A.base[i] == 'S') {
            EnQueue(B, A.base[i]);
        } else if (A.base[i] == 'H'){
            EnQueue(C, A.base[i]);
        }
    }
}


//主函数
int main() {
    SqQueue A, B, C;

    ElemType e;

    InitQueue(A);

    printf("请输入软卧S和硬座H的一个组合车组:");

    for (scanf("%c", &e); e != '\n';) {

        EnQueue(A, e);

        scanf("%c", &e);

    }

    Arrange(A, B, C);

    printf("硬座车组:");

    OutQueue(B);

    printf("软卧车组:");

    OutQueue(C);

    // 销毁队列A
    DestroyQueue(&A);

    // 销毁队列B
    DestroyQueue(&B);

    // 销毁队列C
    DestroyQueue(&C);
}

