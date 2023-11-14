/**
 * @description: 顺序栈 尾指针的位置在队尾
 * @author Kenton
 * @date 2023/11/13 9:15
 * @version 1.0
 */

#include "stdio.h"

#define MaxSize 10

typedef int Element;

typedef struct {
    // 静态数组存放队列元素 连续的存储空间 大小MaxSize * sizeof(ElementType)
    Element data[MaxSize];
    // 头指针
    int front;
    // 尾指针
    int rear;
    // 记录元素个数
    int total;
}SqQueue_tailRear;

// 初始化队列
bool InitQueue(SqQueue_tailRear &Q){
    // 初始化时 队头指向0
    Q.front = Q.total = 0;
    // 队尾指针 指向队尾末端
    Q.rear = MaxSize - 1;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue_tailRear Q){
    // 队空条件
    if ((Q.rear + 1) % MaxSize == Q.front){
        return true;
    } else{
        return false;
    }
}

// 入队
bool EnQueue(SqQueue_tailRear &Q,Element e){
    // 队满报错
    if ((Q.rear + 2) % MaxSize == Q.front){
        return false;
    }
    // 将e插入队尾
    Q.data[Q.rear] = e;
    // 队尾指针+1取模
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.total +=1;
    return true;
}

// 出队
bool DeQueue(SqQueue_tailRear &Q,Element &e){
    // 判断队空
    if ((Q.rear + 1) % MaxSize == Q.front){
        return false;
    }
    e = Q.data[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % MaxSize;
    Q.total -=1;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue_tailRear Q,Element &e){
    if ((Q.rear + 1) % MaxSize == Q.front){
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

// 计算队列元素个数
int total(SqQueue_tailRear Q){
    return Q.total;
}