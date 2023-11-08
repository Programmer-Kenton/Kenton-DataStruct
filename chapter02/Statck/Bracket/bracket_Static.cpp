/**
 * @description: 括号配对
 * @author 2350513316 李成鑫
 * @date 2023/11/7 15:29
 * @version 1.0
 */

#include "stdio.h"

#define MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
}SqStack;

/**
 * 初始化栈
 * @param s
 */
void InitStack(SqStack &S){
    // 初始化栈顶指针
    S.top = -1;
}

/**
 * 判断是否栈空
 * @param S
 * @return
 */
bool StackEmpty(SqStack S){
    if (S.top == -1){
        // 栈空
        return true;
    } else{
        // 非空
        return false;
    }
}

/**
 * 新元素入栈
 * @param S
 * @param x
 * @return
 */
bool Push(SqStack &S,char x){
    if (S.top == MaxSize - 1){
        // 栈满 报错
        return false;
    }
    // 指针先加1
    S.top += 1;
    // 新元素入栈
    S.data[S.top] = x;
    return true;
}

/**
 * 栈顶元素出栈
 * @param S
 * @param x
 * @return
 */
bool Pop(SqStack &S,char &x){
    if (S.top == -1){
        // 栈空报错
        return false;
    }
    // 栈顶元素先出栈
    x = S.data[S.top];
    S.top -= 1;
    return true;
}


/**
 * 括号配对算法
 * @param str 存放括号的数组
 * @param length 数组长度
 * @return
 */
bool bracketCheck(char str[],int length){
    SqStack S;
    // 初始化一个栈
    InitStack(S);
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            // 扫描到左括号入栈
            Push(S,str[i]);
        } else{
            // 扫描到右括号 且当前栈空
            if (StackEmpty(S)){
                // 匹配失败
                return false;
            }
            char topEleml;
            // 栈顶元素出栈
            Pop(S,topEleml);
            if (str[i] == ')' && topEleml != '('){
                return false;
            }
            if (str[i] == ']' && topEleml != '['){
                return false;
            }
            if (str[i] == '}' && topEleml != '{'){
                return false;
            }
        }
        // 检索完全部括号后 栈空说明匹配成功
        return StackEmpty(S);
    }
}