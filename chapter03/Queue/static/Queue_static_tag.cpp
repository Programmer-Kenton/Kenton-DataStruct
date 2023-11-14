/**
 * @description: 队列的顺序实现 tag记录队列执行删除or插入操作
 * @author Kenton
 * @date 2023/11/13 9:03
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
    // 只有插入操作队满 只有删除操作导致队空
    // 插入成功tag=1 删除成功tag=0
    int tag;
}SqQueue_tag;

// 初始化队列
bool InitQueue(SqQueue_tag &Q){
    // 初始化时 队头和队尾指针指向0 tag初始化为0
    Q.rear = Q.front = Q.tag = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue_tag Q){
    // 队空条件
    if (Q.rear == Q.front && Q.tag == 0){
        return true;
    } else{
        return false;
    }
}

// 入队
bool EnQueue(SqQueue_tag &Q,Element e){
    // 队满报错
    if (Q.front == Q.rear && Q.tag == 1){
        return false;
    }
    // 将e插入队尾
    Q.data[Q.rear] = e;
    // 队尾指针+1取模
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}

// 出队
bool DeQueue(SqQueue_tag &Q,Element &e){
    // 判断队空
    if (Q.rear == Q.front && Q.tag == 0){
        return false;
    }
    e = Q.data[Q.front];
    // 队头指针后移
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}

// 获取队头元素
bool GetHead(SqQueue_tag Q,Element &e){
    if (Q.rear == Q.front && Q.tag == 0){
        return false;
    }
    e = Q.data[Q.front];
    return true;
}

// 计算队列元素个数
int total(SqQueue_tag Q){
    // (尾指针-头指针+存储容量) Mod 存储容量
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}