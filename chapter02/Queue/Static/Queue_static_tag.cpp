/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/6 18:49
 * @version 1.0
 */

#include "stdio.h"
#define MaxSize 10

typedef int Element;
typedef struct {
    // 静态数组存放元素
    Element data[MaxSize];
    // 头指针
    int front;
    // 尾指针
    int rear;
    // 最近进行的是删除/插入 +1为插入 -1为删除
    int tag;
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
    if (Q.front == Q.rear && Q.tag == 0){
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
    if (Q.front == Q.rear && Q.tag == 1){
        // 队列满 无法插入
        return false;
    }
    // 将x插入队尾
    Q.data[Q.rear] = x;
    // 队尾指针后移 循环队列
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}

/**
 * 出队 删除一个队头元素 用x存储并返回
 * @param Q
 * @param x
 * @return
 */
bool DeQueue(SqQueue &Q,Element &x){
    if (Q.front == Q.rear && Q.tag == 0){
        // 判断队空
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}