/**
 * @description: 利用队列出队问题
 * @author Kenton
 * @date 2023/11/14 9:15
 * @version 1.0
 */


#include "stdio.h"
#include "stdlib.h"

// 定义队列最大容量
#define MaxSize 10

typedef int Element;

typedef struct peopleQue {
    // 队列元素
    Element *base;
    // 队头指针
    int front;
    // 队尾指针
    int rear;
    // 队列容量
    int size;
} peopleQue;


// 初始化队列
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

// 销毁队列
void DestroyQueue(peopleQue *Q) {
    free(Q->base);
    free(Q);
}


// 判断队列是否为空
bool isEmpty(peopleQue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
}


// 判断队列是否满
bool isFull(peopleQue Q) {
    if ((Q.rear + 1) % MaxSize == Q.front) {
        return true;
    }
}

// 栈入队
bool EnQueue(peopleQue &Q, Element e) {
    if (isFull(Q)) {
        return false;
    }
    // 将e插入到队尾
    Q.base[Q.rear] = e;
    // 队尾指针+1 取模
    Q.rear = (Q.rear + 1) % Q.size;
    return true;
}

// 栈出队
bool DeQueue(peopleQue &Q, Element &e) {
    // 判断队空
    if (isEmpty(Q)) {
        return false;
    }
    e = Q.base[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % Q.size;
    return true;
}

void OutPrint(peopleQue &ManQ, peopleQue &WomanQ, Element man[], Element woman[]) {
    // 初始化男生队列
    InitQueue(ManQ);
    // 初始化女升队列
    InitQueue(WomanQ);
    // 接收男生出队列元素
    Element manElement;
    // 接收女生出队列元素
    Element womanElement;
    // 统计男生编号个数
    Element size_man = (sizeof(man) / sizeof(man[0]));
    // 统计女生编号个数
    Element size_woman = (sizeof(woman) / sizeof(woman[0]));

    // 男生编号入队
    for (int i = 0; i < size_man; ++i) {
        EnQueue(ManQ, man[i]);
    }

    // 女生编号入队
    for (int i = 0; i < size_woman; ++i) {
        EnQueue(WomanQ, woman[i]);
    }

    // 取男女生 编号个数 最大的数
    Element max = size_man > size_woman ? size_man : size_woman;
    // 取男女生 编号个数 最小的数
    Element min = size_man < size_woman ? size_man : size_woman;

    // 交流的论数
    int num = 0;
    printf("请输入交流的轮数:\n");
    scanf("%d", &num);
    for (int i = 1; i <= min; ++i) {
        printf("第%d组配对交流:\n", i);
        DeQueue(ManQ, manElement);
        EnQueue(ManQ, manElement);
        DeQueue(WomanQ, womanElement);
        EnQueue(WomanQ, womanElement);
        printf("<%d,%d>", manElement, womanElement);
    }
    for (int i = 1; i <= max - min; ++i) {
        printf("第%d组配对交流:\n", min + i);
        DeQueue(ManQ, manElement);
        EnQueue(ManQ, manElement);
        DeQueue(WomanQ, womanElement);
        EnQueue(WomanQ, womanElement);
        printf("<%d,%d>", manElement, womanElement);
    }
}

int main() {
    // 男生队列
    peopleQue ManQ;
    // 女生队列
    peopleQue WomanQ;

    // 男生编号个数
    Element manTotal;
    // 女生编号个数
    Element womanTotal;

    printf("请输入男生编号个数:\n");
    scanf("%d", &manTotal);

    printf("请输入女生编号个数:\n");
    scanf("%d", &womanTotal);

    // 存放男生编号的数组
    int man[manTotal];
    // 存放女生编号的数组
    int woman[womanTotal];

    // 用于接收存入的编号值
    Element e;
    printf("请输入男生的编号:\n");

    for (int i = 0; i < manTotal; i++) {
        scanf("%d", &e);
        man[i] = e;
    }

    printf("请输入女生的编号:\n");

    for (int j = 0; j < womanTotal; j++) {
        scanf("%d", &e);
        woman[j] = e;
    }

    OutPrint(ManQ, WomanQ, man, woman);

    // 销毁男生队列
    DestroyQueue(&ManQ);
    // 销毁女生队列
    DestroyQueue(&WomanQ);
}