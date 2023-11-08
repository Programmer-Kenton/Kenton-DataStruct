/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/7 8:51
 * @version 1.0
 */

#include "stdio.h"

#define MaxSize 10
typedef int Element;
typedef struct{
    // 静态数组存放队列元素
    Element data[MaxSize];
    // 队头指针
    int front;
    // 队尾指针
    int rear;
    // 记录插入和删除size 插入+1 删除-1
    int size;
    // 记录插入和删除 插入tag = 1 删除tag = 0
    int tag;
}SqQueue;

// 初始化
void InitQueue(SqQueue &Q){
    Q.front = 0;
    Q.rear = MaxSize - 1;
}

// 判断队列是否为空
 bool QueueEmpty(SqQueue Q){
    if (Q.front == 0 && Q.rear == MaxSize -1){
        return true;
    } else{
        return false;
    }
}

// 入栈
bool EnQueue(SqQueue &Q,Element &x){
    // 牺牲一个存储单元 判断是否队满
    if (Q.rear + 2 == Q.front){
        return false;
    };
    // 用size判断是否队满
    if (Q.size == MaxSize){
        return false;
    }
    // 用tag判断是否队满
    if (Q.tag = 1 && Q.rear + 1 == Q.front){
        return false;
    }
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.data[Q.rear] = x;
    Q.size++;
    Q.tag = 1;
}