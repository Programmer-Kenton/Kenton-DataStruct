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
    int increment; // ����ʱ�����ӵĴ洢����
} SqStack;

// ����һ����ջ S
Status InitStack(SqStack &S) {
    S.base = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = 0;
    S.size = STACK_INIT_SIZE;
    S.increment = STACKINCREMENT;
    return OK;
}

// ��ջ S �Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S) {
    if (S.top == 0) return TRUE;
    else return FALSE;
}

//��ջ����
Status Push(SqStack &S, ElemType e) {
    if (S.top >= S.size) { // ���ջ�������������
        S.base = (ElemType *) realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
        if (!S.base) exit(OVERFLOW); // ����ڴ����ʧ�ܣ����˳�����
        S.size += S.increment; // ����ջ������
    }
    S.base[S.top++] = e; // ��ջ����������topָ�����
    return OK;
}

//��ջ����
Status Pop(SqStack &S, ElemType &e) {
    if (S.top == 0) return ERROR; // ���ջ�գ��򷵻ش���
    e = S.base[--S.top]; // ��ջ����������topָ��ǰ��
    return OK;
}


//ʮ����ת������ƺ���
Status DecToAnyBase(ElemType dec, ElemType base, ElemType *anyBase) {
    SqStack S;
    int i = 0;

    InitStack(S); // ��ʼ��ջ

    while (dec != 0) { // ��ʮ��������Ϊ0ʱ������ת������
        int remainder = dec % base; // ȡ�����������õ�ÿһλ�ϵ�����
        Push(S, remainder); // ��ջ
        dec /= base; // ���Խ�����������ת����һλ
    }

    while (!StackEmpty(S)) { // ��ջ��Ϊ��ʱ������ջ��Ԫ�ز���������õ���ת��������������
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
