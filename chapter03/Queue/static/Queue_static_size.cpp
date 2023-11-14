/**
 * @description: 队列的顺序存储实现 用size记录队列长度
 * @author Kenton
 * @date 2023/11/13 8:47
 * @version 1.0
 */

#include "stdio.h"
#define MaxSize 10

typedef int Elment;

typedef struct {
    Elment data[MaxSize];
    int front;
    int rear;
    // 记录队列长度
    int size;
}SqQueue_size;

// 初始化队列
bool InitQueue(SqQueue_size &Q){
    Q.rear = Q.front = Q.size = 0;
}


// 判断队列是否为空
bool QueueEmpty(SqQueue_size &Q){
    // 队空条件
    if (Q.size == 0){
        return true;
    } else{
        return false;
    }
}

// 入队
bool EnQueue(SqQueue_size &Q,Elment e){
    // 队满报错
    if (Q.size == MaxSize){
        return false;
    }
    Q.data[Q.rear] = e;
    // 队尾+1
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue_size &Q,Elment &e){
    // 判断队空
    if (Q.size == 0){
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
}

// 获取队头元素
bool GetHead(SqQueue_size Q,Elment &e){
    if (Q.size == 0){
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

// 计算队列元素个数
int total(SqQueue_size Q){
    // (队头指针-队头指针+存储容量) Mod 存储容量
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}