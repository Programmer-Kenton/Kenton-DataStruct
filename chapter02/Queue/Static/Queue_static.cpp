/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/6 11:16
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
}SqQueue;

/**
 * 初始化队列
 * @param Q
 */
void InitQueue(SqQueue &Q){
    // 初始化时 队头、队尾指针指向0
    Q.rear = Q.front = 0;
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
bool QueueEmpty(SqQueue Q){
    if (Q.rear == Q.front){
        return true;
    } else{
        return false;
    }
}

/**
 * 入栈
 * @param Q
 * @param x
 * @return
 */
bool EnQueue(SqQueue &Q,Element x){
    if ((Q.rear+1) % MaxSize == Q.front){
        // 队列满 无法插入
        return false;
    }
    // 将x插入队尾
    Q.data[Q.rear] = x;
    // 队尾指针后移 循环队列
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
    }

/**
 * 出队 删除一个队头元素 用x存储并返回
 * @param Q
 * @param x
 * @return
 */
bool DeQueue(SqQueue &Q,Element &x){
    if (Q.rear == Q.front){
        // 判断队空
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}


/**
 * 获得队头元素的值 用x返回
 * @param Q
 * @param x
 * @return
 */
bool GetHead(SqQueue Q,Element &x){
    if (Q.rear == Q.front){
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

/**
 * 返回队列元素总数
 * @param Q
 * @return
 */
int totalNum(SqQueue Q){
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}
