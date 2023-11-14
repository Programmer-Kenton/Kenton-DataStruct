/**
 * @description: 顺序表实现队列 牺牲一个存储单元
 * @author Kenton
 * @date 2023/11/13 8:25
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
}SqQueue;

// 初始化队列
bool InitQueue(SqQueue &Q){
    // 初始化时 队头和队尾指针指向0
    Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue Q){
    // 队空条件
    if (Q.rear == Q.front){
        return true;
    } else{
        return false;
    }
}

// 入队
bool EnQueue(SqQueue &Q,Element e){
    // 队满报错
    if ((Q.rear + 1) % MaxSize == Q.front){
        return false;
    }
    // 将e插入队尾
    Q.data[Q.rear] = e;
    // 队尾指针+1取模
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q,Element &e){
    // 判断队空
    if (Q.rear == Q.front){
        return false;
    }
    e = Q.data[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue Q,Element &e){
    if (Q.rear == Q.front){
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

// 计算队列元素个数
int total(SqQueue Q){
    // (尾指针-头指针+存储容量) Mod 存储容量
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}