/**
 * @description: 顺序栈 初始top指针 指向栈的序号0
 * @author Kenton
 * @date 2023/11/6 9:03
 * @version 1.0
 */

#include "stdio.h"

// 定义栈中元素的最大个数
#define MaxSize 10
#define ElemType int

typedef struct {
    // 静态数组存放栈中元素
    ElemType data[MaxSize];
    // 栈顶指针
    int top;
}SqStack; // sequence 顺序

/**
* 顺序存储:给各个数据元素分配连续的存储空间 大小为:MaxSize * sizeof(ElemType)
*/

/**
 * 初始化栈
 * @param S
 */
void InitStack(SqStack &S){
    // 初始化栈顶指针
    S.top = 0;
}

/**
 * 判断是否栈空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S){
    if (S.top == 0){
        // 栈空
        return true;
    } else{
        // 非空
        return false;
    }
}

/**
 * 新元素入栈
 * @param S 栈
 * @param x 入栈的新元素
 * @return
 */
bool Push(SqStack &S,ElemType x){
    if (S.top == MaxSize){
        // 栈满 报错
        return false;
    }
    // 新元素入栈
    S.data[S.top] = x;
    // 指针先加1
    S.top += 1;
    return true;
}

/**
 * 出栈操作
 * @param S 栈
 * @param x 出栈的元素
 * @return
 */
bool Pop(SqStack &S,ElemType &x){
    if (S.top == 0){
        // 栈空报错
        return false;
    }
    // 栈顶元素先出栈
    S.top -= 1;
    x = S.data[S.top];
    return true;
}

/**
 * 读取栈元素
 * @param S 栈
 * @param x 查看的栈元素
 * @return
 */
bool GetTop(SqStack S,ElemType &x){
    if (S.top == 0){
        // 栈空
        return false;
    }
    x = S.data[S.top];
    return true;
}