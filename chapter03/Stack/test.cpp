#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE  1
#define FALSE  0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef struct {
    ElemType *base;
    int top;
    int size;
    int increment; // 扩容时，增加的存储容量
} SqStack;

// 构造一个空栈 S
Status InitStack(SqStack &S) {
    S.base = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = 0;
    S.size = STACK_INIT_SIZE;
    S.increment = STACKINCREMENT;
    return OK;
}

// 判栈 S 是否为空栈
Status StackEmpty(SqStack S) {
    if (S.top == 0) return TRUE;
    else return FALSE;
}

//入栈函数
Status Push(SqStack &S, ElemType e) {
    if (S.top >= S.size) { // 如果栈满，则进行扩容
        S.base = (ElemType *) realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
        if (!S.base) exit(OVERFLOW); // 如果内存分配失败，则退出程序
        S.size += S.increment; // 增加栈的容量
    }
    S.base[S.top++] = e; // 入栈操作，并将top指针后移
    return OK;
}

//出栈函数
Status Pop(SqStack &S, ElemType &e) {
    if (S.top == 0) return ERROR; // 如果栈空，则返回错误
    e = S.base[--S.top]; // 出栈操作，并将top指针前移
    return OK;
}


//十进制转任意进制函数
Status DecToAnyBase(ElemType dec, ElemType base, ElemType *anyBase) {
    SqStack S;
    int i = 0;

    InitStack(S); // 初始化栈

    while (dec != 0) { // 当十进制数不为0时，进行转换操作
        int remainder = dec % base; // 取余数操作，得到每一位上的数字
        Push(S, remainder); // 入栈
        dec /= base; // 除以进制数，继续转换下一位
    }

    while (!StackEmpty(S)) { // 当栈不为空时，弹出栈顶元素并输出，即得到了转换后的任意进制数
        Pop(S, anyBase[i]);
        printf("%d", anyBase[i]);
        i++;
    }

    return OK;
}


int main() {
    ElemType anyBase[STACK_INIT_SIZE];
    int number = 10;
    int system = 2;
    DecToAnyBase(number, system, anyBase);
    printf("\n");
    return 0;
}
