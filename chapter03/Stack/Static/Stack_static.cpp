/**
 * @description: 顺序栈的静态实现
 * @author Kenton
 * @date 2023/11/11 23:33
 * @version 1.0
 */

#include "stdio.h"
// 定义栈中元素的最大个数
#define MaxSize 10

typedef int Element;

typedef struct{
    // 静态数组存放栈中元素
    Element data[MaxSize];
    // 栈顶指针
    int top;
}SqStack;

// 初始化栈
void InitStack(SqStack &S){
    // 初始化栈顶指针
    S.top = -1;
}

// 判断栈空
bool StackEmpty(SqStack S){
    if (S.top == -1){
        return true;
    } else{
        return false;
    }
}

// 判断栈满
bool StackFull(SqStack S){
    if (S.top == MaxSize - 1){
        return true;
    } else{
        return false;
    }
}

// 新元素入栈
bool Push(SqStack &S,Element e){
    // 栈满 报错
    if (StackEmpty(S)){
        return false;
    } else{
        // 指针先+1 再入栈
        S.data[++S.top] = e;
    }
}

// 出栈操作
bool Pop(SqStack &S,Element &e){
    if (StackEmpty(S)){
        return false;
    } else{
        e = S.data[S.top--];
        return true;
    }
}

// 读取栈元素
bool GetTop(SqStack &S,Element &e){
    if (StackEmpty(S)){
        return false;
    } else{
        e = S.data[S.top];
        return true;
    }
}

