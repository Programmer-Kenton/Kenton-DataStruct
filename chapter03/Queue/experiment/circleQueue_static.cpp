/**
 * @description: 顺序队列的实现和运算
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

// 存储空间的初始分配量
#define MaxSize 30

typedef int ElemType;

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
    Q.base = (ElemType *) malloc(MaxSize * sizeof(ElemType));
    // 动态分配失败
    if (!Q.base) exit(OVERFLOW);
    // 初始化头尾指针 指向0
    Q.front = Q.rear = 0;
    // 设置队列的最大容量
    Q.size = MaxSize;
    return OK;

}

// 销毁队列
Status DestroyQueue(SqQueue *Q) {
    // 释放存储空间
    if (Q->base) free(Q->base);
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

        while (!QueueEmpty(Q)) {

            DeQueue(Q, e);

            printf("%6d", e);

        }

        printf("\n");

    }

}

//主函数

int main() {
    SqQueue q;

    int cord;

    ElemType a;

    printf("第一次使用必须初始化！\n");

    do {

        printf("\n 主菜单 \n");

        printf(" 1 初始化循环队列 ");

        printf(" 2 进队一个元素 ");

        printf(" 3 出队一个元素 ");

        printf(" 4 结束程序运行 ");

        printf("\n------------------------------------------------------------------\n");

        printf("请输入您的选择( 1, 2, 3, 4)");

        scanf("%d", &cord);

        printf("\n");

        switch (cord) {

            case 1:

                InitQueue(q); //调用初始化算法;

                OutQueue(q);

                break;

            case 2:

                printf("请输入要插入的数据元素：a=");

                scanf("%d", &a);

                EnQueue(q, a); //调用进队算法;

                printf("%d 进队之后的队列：", a);

                OutQueue(q);

                break;

            case 3:

                DeQueue(q, a); //调用出队算法;

                printf("队头元素 %d 出队之后的队列：", a);

                OutQueue(q);

                break;

            case 4:

                exit(0);

        }

    } while (cord <= 4);

}