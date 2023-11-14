/**
 * @description: 链式队列实现 双端队列
 * @author Kenton
 * @date 2023/11/14 8:49
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>


// 定义双端队列结构体
typedef struct {
    // 队列元素数组
    int *arr;
    // 队头指针
    int front;
    // 队尾指针
    int rear;
    // 队列大小
    int size;
} DoubleEndQueue;

// 创建双端队列
DoubleEndQueue *createDEQueue(int size) {
    // 分配内存空间
    DoubleEndQueue *deq = (DoubleEndQueue *)malloc(sizeof(DoubleEndQueue));
    // 分配数组内存空间
    deq->arr = (int *)malloc(sizeof(int) * size);
    // 初始化队头指针
    deq->front = -1;
    // 初始化队尾指针
    deq->rear = -1;
    // 初始化队列大小
    deq->size = size;
    return deq;
}

// 销毁双端队列
void destroyDEQueue(DoubleEndQueue *deq) {
    // 释放数组内存空间
    free(deq->arr);
    // 释放内存空间
    free(deq);
}

// 判断双端队列是否为空
int isDEQueueEmpty(DoubleEndQueue *deq) {
    // 如果队尾指针等于-1，表示队列为空
    return deq->rear == -1;
}

// 判断双端队列是否已满
int isDEQueueFull(DoubleEndQueue *deq) {
    // 如果队尾指针加1后与队头指针相等（同余），表示队列已满
    return (deq->rear + 1) % deq->size == deq->front;
}

// 在双端队列尾部添加元素
void enqueueDEQueue(DoubleEndQueue *deq, int item) {
    // 如果队列已满，则打印错误信息并返回
    if (isDEQueueFull(deq)) {
        printf("Error: Double End Queue is full.\n");
        return;
    }
    // 如果队列为空，则将队头指针指向数组第一个位置
    if (deq->rear == -1) {
        deq->front = 0;
    }
    // 队尾指针向后移动一位（同余运算）
    deq->rear = (deq->rear + 1) % deq->size;
    // 在移动后的位置存储元素
    deq->arr[deq->rear] = item;
    // 打印添加成功信息
    printf("%d Enqueued at Rear.\n", item);
}

// 从双端队列头部删除元素
int dequeueDEQueue(DoubleEndQueue *deq) {
    // 如果队列为空，则打印错误信息并返回-1
    if (isDEQueueEmpty(deq)) {
        printf("Error: Double End Queue is empty.\n");
        return -1;
    }
    // 获取队头元素
    int item = deq->arr[deq->front];
    // 如果队头指针等于队尾指针，表示队列中只有一个元素
    if (deq->rear == deq->front) {
        // 更新队头和队尾指针为-1（空队列）
        deq->front = deq->rear = -1;
    } else {
        // 队头指针向后移动一位（同余运算）
        deq->front = (deq->front + 1) % deq->size;
    }
    // 打印删除成功信息
    printf("%d Dequeued from Front.\n", item);
    // 返回删除的元素
    return item;
}

// 显示双端队列中的元素
void displayDEQueue(DoubleEndQueue *deq) {
    // 如果队列为空，则打印提示信息
    if (isDEQueueEmpty(deq)) {
        printf("Double End Queue is empty.\n");
        return;
    }
    // 打印标题信息
    printf("Elements in Double End Queue: ");
    // 如果队头指针等于队尾指针，表示队列中只有一个元素
    if (deq->front == deq->rear) {
        // 直接打印该元素
        printf("%d\n", deq->arr[deq->front]);
    } else {
        // 计算需要打印的起始位置（同余运算）
        int start = (deq->front + deq->size - 1) % deq->size;
        for (int i = start; i != deq->rear; i = (i + deq->size - 1) % deq->size) {
            // 依次打印队列中的元素
            printf("%d ", deq->arr[i]);
        }
        // 打印队列中的最后一个元素
        printf("%d\n", deq->arr[deq->rear]);
    }
}

int main() {
    // 创建双端队列
    DoubleEndQueue *deq = createDEQueue(5);
    // 在队列尾部添加元素1
    enqueueDEQueue(deq, 1);
    // 在队列尾部添加元素2
    enqueueDEQueue(deq, 2);
    // 在队列尾部添加元素3
    enqueueDEQueue(deq, 3);
    // 在队列尾部添加元素4
    enqueueDEQueue(deq, 4);
    // 在队列尾部添加元素5
    enqueueDEQueue(deq, 5);
    // 显示队列中的元素
    displayDEQueue(deq);
    // 从队列头部删除元素并打印
    printf("%d dequeued from front.\n", dequeueDEQueue(deq));
    // 从队列尾部删除元素并打印
    printf("%d dequeued from rear.\n", dequeueDEQueue(deq));
    // 从队列头部删除元素并打印
    printf("%d dequeued from front.\n", dequeueDEQueue(deq));
    // 从队列尾部删除元素并打印
    printf("%d dequeued from rear.\n", dequeueDEQueue(deq));
    // 显示队列中的元素
    displayDEQueue(deq);
    return 0;
}
