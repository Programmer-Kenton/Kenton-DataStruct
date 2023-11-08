/**
 * @description: 共享栈顺序实现
 * @author Kenton
 * @date 2023/11/6 9:09
 * @version 1.0
 */

#include "stdio.h"

#define MaxSize 10
#define ElemType int

typedef struct{
    ElemType data[MaxSize];
    // 1号栈 栈顶指针
    int Top1 = -1;
    // 2号栈 栈顶指针
    int Top2 = MaxSize;
}shared_stack;

typedef shared_stack *sharedStack;

/**
 * 1号栈判空
 * @param S
 * @return 是否空
 */
bool StackOneEmpty(shared_stack &S){
    return (S.Top1 == -1);
}

/**
 * 2号栈判空
 * @param S
 * @return
 */
bool StackTwoEmpty(shared_stack &S){
    return (S.Top2 == MaxSize);
}

/**
 * 1号栈 新元素入栈 先存再+1
 * @param S
 * @param x
 * @return
 */
bool PushOne(shared_stack &S,ElemType x){
    if (S.Top1 + 1 == S.Top2){
        // 栈满报错
        return false;
    }
    S.data[++S.Top1] = x;
    return true;
}

/**
 * 2号栈 新元素入栈 先存再+1
 * @param S
 * @param x
 * @return
 */
bool PushTwo(shared_stack &S,ElemType x){
    if (S.Top1 + 1 == S.Top2){
        // 栈满 报错
        return false;
    }
    S.data[--S.Top2] = x;
    return true;
}

/**
 * 1号栈 栈顶元素出栈
 * @param S 栈
 * @param x 要出栈的元素
 * @return
 */
bool PopOne(shared_stack &S,ElemType &x){
    if (S.Top1 == -1){
        // 1号栈为空 报错
        return false;
    }
    x = S.data[S.Top1--];
    return true;
}

/**
 * 2号栈 栈顶元素出栈
 * @param S 栈
 * @param x 出栈元素
 * @return
 */
bool PopTwo(shared_stack &S,ElemType &x){
    if (S.Top2 == MaxSize){
        // 2号栈为空 报错
    }
    x = S.data[S.Top2++];
}

/**
 * 读取1号栈 栈顶元素
 * @param S 栈
 * @param x 存放栈顶元素
 * @return
 */
bool GetTopOne(shared_stack S,ElemType &x){
    if (S.Top1 == -1){
        return false;
    }
    x = S.data[S.Top1];
    return true;
}

bool GetTwo(shared_stack S,ElemType &x){
    if (S.Top2 == MaxSize){
        // 2号栈空 报错
        return false;
    }
    x = S.data[S.Top2];
}


