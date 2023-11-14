/**
 * @description: 顺序栈实现共享栈
 * @author Kenton
 * @date 2023/11/11 23:50
 * @version 1.0
 */


#include "stdio.h"

#define MaxSize 10
typedef int Element;

typedef struct {
    // 一号栈顶指针
    int top0;
    // 二号栈顶指针
    int top1;
    // 栈的存储容量
    Element data[MaxSize];
}SqStack_Share;

// 初始化栈
bool InitStack(SqStack_Share &S){
    S.top0 = -1;
    S.top1 = MaxSize;
    return true;
}

// 判断1号栈是否栈空
bool isEmptyStack0(SqStack_Share &S){
    if(S.top0 == -1){
        return true;
    } else{
        return false;
    }
}

// 判断2号栈是否栈空
bool isEmptyStack1(SqStack_Share S){
    if (S.top1 == MaxSize){
        return true;
    } else{
        return false;
    }
}

// 判断整个栈是否栈满
bool isStackFull(SqStack_Share S){
    if (S.top0 + 1 == S.top1){
        return true;
    } else{
        return false;
    }
}

// 1号栈入栈
bool Push0(SqStack_Share &S,Element e){
    // 栈满
    if (isStackFull(S)){
        return false;
    }
    S.data[++S.top0] = e;
    return true;
}

// 2号栈入栈
bool Push1(SqStack_Share &S,Element e){
    // 栈满
    if (isStackFull(S)){
        return false;
    }
    S.data[--S.top1] = e;
    return true;
}

// 1号栈出栈
bool Pop0(SqStack_Share &S,Element &e){
    if (isEmptyStack0(S)){
        return false;
    } else{
        e = S.data[S.top0--];
        return true;
    }
}

// 2号栈出栈
bool Pop1(SqStack_Share &S,Element &e){
    if (isEmptyStack1(S)){
        return false;
    } else{
        e = S.data[S.top1++];
        return true;
    }
}

int main(){
    SqStack_Share S; InitStack(S);
    for (int i = 0; i < MaxSize; ++i) {
        if (!Push0(S, i)) {
            break;
        }
        if (!Push1(S, i)) {
            break;
        }
    }

    while (!isEmptyStack0(S)) {
        Element e;
        Pop0(S, e);
        printf("%d ", e);
    }

    while (!isEmptyStack1(S)) {
        Element e;
        Pop1(S, e);
        printf("%d ", e);
    }
}
