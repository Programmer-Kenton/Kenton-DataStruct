/**
 * @description: 利用栈实现进制之间的转换
 * @author 2350513316 李成鑫
 * @date 2023/11/8 14:43
 * @version 1.0
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef int Element;

// 使用链表的形式 实现栈
typedef struct Stack{
    // 栈顶指针
    int top;
    // 栈的最大容量
    int MaxSize;
    // 栈数组指针
    int *array;
}*LinkStack;

/**
 * 创建栈
 * @param MaxSize 栈的最大容量
 * @return 创建的栈的指针
 */
LinkStack createStack(int MaxSize){
    // 分配栈内存空间
    LinkStack L = (Stack*) malloc(sizeof(Stack));
    // 设置栈的最大容量
    L->MaxSize = MaxSize;
    // 初始化栈顶指针 -1表示栈为空
    L->top = -1;
    // 分配栈数组内存空间
    L->array = (int*) malloc(L->MaxSize * sizeof(int));
    // 返回栈指针
    return L;
}

/**
 * 元素入栈
 * @param L 操作的链表
 * @param e 入栈的元素
 * @return 是否入栈成功
 */
bool Push(LinkStack &L,Element e){
    // 判断是否栈满
    if (L->top == L->MaxSize){
        return false;
    }
    // 将元素压入栈顶 同时栈顶指针+1
    L->array[++L->top] = e;
    return true;
}

/**
 * 栈顶弹出元素
 * @param L 操作的链表
 * @param e 接收弹出栈的元素值
 * @return 是否弹出成功
 */
Element Pop(LinkStack &L,char &e){
    // 判断是否栈空
    if (L->top == -1){
        return false;
    }
    // 栈顶弹出元素 同时栈顶指针自减
    e = (char)L->array[L->top--];
}

/**
 * 判断栈是否空
 * @param L
 * @return
 */
bool isEmpty(LinkStack &L){
    if (L->top == -1){
        return false;
    }
}

void destoryStack(LinkStack &L){
    // 释放栈内数组内存
    free(L->array);
    // 释放栈内存空间
    free(L);
}



/**
 *
 * @param decimal 被转换的数字
 * @param base 转换成几进制
 */
void decimal_to_base(LinkStack &L, int decimal, int base) {
    char e;
    L->top = -1;
    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            Push(L, remainder + '0');
        } else {
            Push(L, remainder - 10 + 'A');
        }
        decimal /= base;
    }
    while (L->top != -1) {
        printf("%c", Pop(L,e));
    }
}

int main(int argc,char *const argv[]){
    int MaxSize = 64;
    LinkStack L = createStack(MaxSize);
    int decimal,base = 0;
    printf("输入要转换的数字:\n");
    scanf("%d",&decimal);
    printf("输入要转换的机制:\n");
    scanf("%d",&base);
    decimal_to_base(L,decimal,base);
}