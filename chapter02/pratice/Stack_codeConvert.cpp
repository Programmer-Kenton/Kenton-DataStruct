/**
 * @description: ����ת��
 * @author 2350513316 �����
 * @date 2023/11/8 19:54
 * @version 1.0
 */

#include <stdio.h>

#include <stdlib.h>

// ����һ���� �����ɹ� ֵΪ1
#define OK 1
// ����һ���� ����ʧ�� ֵΪ0
#define ERROR 0
// ����һ���꣬��ʾ�߼��棬ֵΪ1��
#define TRUE 1
// ����һ���꣬��ʾ�߼��٣�ֵΪ0��
#define FALSE 0
// ����һ���꣬��ʾ�ڴ������ֵΪ-2��
#define OVERFLOW -2

typedef int ElemType;

typedef int Status;

// �洢�ռ�ĳ�ʼ������
#define STACK_INIT_SIZE 10
// �洢�ռ�ķ�������
#define STACKINCREMENT 5
// ���������꣬�ֱ��ʾջ�ĳ�ʼ��С��ÿ������������

typedef struct {
    // �洢�ռ��ԭʼ��ַ
    ElemType *array;
    // ջ��ָ��
    int top;
    // ջ�Ĵ�С
    int size;
    // ����ʱ�����ӵĴ洢����
    int increment;
} SqStack;


/**
 * ����һ����ջ S ��ʼ��
 * @param S
 * @return �Ƿ��ʼ�����
 */
Status InitStack(SqStack &S) {

    // ��ջ�������ռ� �������ʧ���˳�����
    S.array = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    //
    if (!S.array) {
        // ʹ��malloc���������ڴ�ռ䣬����������ڴ�ռ���׵�ַ��ֵ��arrayָ�������
        // �������ʧ�ܣ�������NULL���������exit���������������У������ش������OVERFLOW��
        exit(OVERFLOW);
    }

    // ջ��ָ����Ϊ0 ��ʾ��ջ
    S.top = 0;
    // ��ջ�Ĵ�С��Ϊ��ʼֵ
    S.size = STACK_INIT_SIZE;
    // ��ÿ�����ݵ�������Ϊ����ֵ
    S.increment = STACKINCREMENT;
    // ���سɹ�״̬��OK
    return OK;

}

/**
 * �ж�ջS�Ƿ�Ϊ�գ����ջ��ָ��Ϊ0�򷵻�TRUE���棩�����򷵻�FALSE���٣�
 * @param S
 * @return �Ƿ�Ϊ��ջ
 */
Status StackEmpty(SqStack S) {
    if (S.top == 0){
        return TRUE;
    } else{
        return FALSE;
    }

}


/**
 * ��ջ����
 * @param S ջ
 * @param e ѹջ����
 * @return
 */
Status Push(SqStack &S, ElemType e) {
    // ����ָ�� ������¼������Ŀռ�
    ElemType *newBase;
    // ��ջ��ָ���Ѿ�����ջ��������� ���������
    if (S.top >= S.size){
        // ��������ռ������realloc
        newBase = (ElemType*) realloc(S.array, (S.size + S.increment) * sizeof(ElemType));
        // ���û�����뵽�ڴ� realloc��������NULL��newBase
        if (NULL == newBase){
            return OVERFLOW;
        }
        // �������ɵĿռ��ַ���ݸ�array
        S.array = newBase;
        // ����ջ�Ĵ�С
        S.size += S.increment;
        // �ͷſռ�
        free(newBase);
    }

    // e��ջ ջ��ָ��+1
    S.array[S.top++] = e;
}


/**
 * ��ջ
 * @param S ջ
 * @param e ���ճ�ջ��Ԫ��ֵ
 * @return
 */
Status Pop(SqStack &S, ElemType &e) {
    // �ж��Ƿ�ջ��
    if (S.top == 0){
        // ����ʧ��
        return ERROR;
    }
    // ȡ��ջ��Ԫ�ظ�e ͬʱջ��ָ���Լ�
    e = S.array[S.top--];
}

//ʮ����ת�˽��ƺ���

void conversion(int number) {
    SqStack S;
    InitStack(S);
    // ���յ�����Ԫ��
    ElemType e;
    while (number != 0){
        Push(S,number % 8);
        number /= 8;
    }
    while (FALSE == StackEmpty(S)){
        Pop(S,e);
        printf("%d",e);
    }


}

int main() {
    int number = 0;

    printf("��������Ҫת���ɰ˽��Ƶ�����:\n");

    scanf("%d",&number);


    printf("100");
    conversion(number);


}