/**
 * @description: ˳��ջ��ʵ�ֺ�����
 * @author 2350513316 �����
 * @date 2023/11/8 19:07
 * @version 1.0
 */

#include <stdio.h>

#include <stdlib.h>

// ����һ���� �����ɹ� ֵΪ1
#define OK  1
// ����һ���� ����ʧ�� ֵΪ0
#define ERROR  0
// ����һ���꣬��ʾ�߼��棬ֵΪ1��
#define TRUE 1
// ����һ���꣬��ʾ�߼��٣�ֵΪ0��
#define FALSE 0
// ����һ���꣬��ʾ�ڴ������ֵΪ-2��
#define OVERFLOW  -2

typedef int ElemType;

typedef int Status;

//----- ջ��˳��洢��ʾ -----

// �洢�ռ�ĳ�ʼ������
#define STACK_INIT_SIZE 10
// �洢�ռ�ķ�������
#define STACKINCREMENT 5
// ���������꣬�ֱ��ʾջ�ĳ�ʼ��С��ÿ������������

typedef struct {
    // ջ��ָ��
    int top;
    // �洢�ռ��ԭʼ��ַ
    ElemType *array;
    // ջ�Ĵ�С
    int size;
    // ����ʱ�����ӵĴ洢����
    int increment;
} SqStack;


/**
 * ����һ����ջ S ��ʼ��
 * @param S
 * @return
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
 * @return
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

//���˳��ջ����

void OutStack(SqStack S) {
    ElemType e;

    if (TRUE == StackEmpty(S)) {

        printf("����һ����ջ��");

    } else

        while (FALSE == StackEmpty(S)) {

            Pop(S, e);

            printf("%6d", e);

        }

    printf("\n");

}

//������

int main() {
    SqStack s;

    int cord;
    ElemType a;

    printf("��һ��ʹ�ñ����ʼ����\n");

    do {

        printf("\n ���˵� \n");

        printf(" 1 ��ʼ��˳��ջ ");

        printf(" 2 ����һ��Ԫ�� ");

        printf(" 3 ɾ��ջ��Ԫ�� ");

        printf(" 4 ������������ ");

        printf("\n-------------------------------------------------------------------\n");

        printf("����������ѡ��( 1, 2, 3, 4)\n");

        scanf("%d", &cord);

        printf("\n");

        switch (cord) {
            case 1:

                InitStack(s);

                OutStack(s);

                break;

            case 2:

                printf("������Ҫ���������Ԫ�أ�a=");

                scanf("%d", &a);

                Push(s, a);

                printf("%d ��ջ֮���ջ��", a);

                OutStack(s);

                break;

            case 3:

                Pop(s, a);

                printf("ջ��Ԫ�� %d ��ջ֮���ջ��", a);

                OutStack(s);

                break;

            case 4:

                exit(0);

        }

    } while (cord <= 4);

}



