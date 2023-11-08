/**
 * @description: ����ջʵ�ֽ���֮���ת��
 * @author 2350513316 �����
 * @date 2023/11/8 14:43
 * @version 1.0
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef int Element;

// ʹ���������ʽ ʵ��ջ
typedef struct Stack{
    // ջ��ָ��
    int top;
    // ջ���������
    int MaxSize;
    // ջ����ָ��
    int *array;
}*LinkStack;

/**
 * ����ջ
 * @param MaxSize ջ���������
 * @return ������ջ��ָ��
 */
LinkStack createStack(int MaxSize){
    // ����ջ�ڴ�ռ�
    LinkStack L = (Stack*) malloc(sizeof(Stack));
    // ����ջ���������
    L->MaxSize = MaxSize;
    // ��ʼ��ջ��ָ�� -1��ʾջΪ��
    L->top = -1;
    // ����ջ�����ڴ�ռ�
    L->array = (int*) malloc(L->MaxSize * sizeof(int));
    // ����ջָ��
    return L;
}

/**
 * Ԫ����ջ
 * @param L ����������
 * @param e ��ջ��Ԫ��
 * @return �Ƿ���ջ�ɹ�
 */
bool Push(LinkStack &L,Element e){
    // �ж��Ƿ�ջ��
    if (L->top == L->MaxSize){
        return false;
    }
    // ��Ԫ��ѹ��ջ�� ͬʱջ��ָ��+1
    L->array[++L->top] = e;
    return true;
}

/**
 * ջ������Ԫ��
 * @param L ����������
 * @param e ���յ���ջ��Ԫ��ֵ
 * @return �Ƿ񵯳��ɹ�
 */
Element Pop(LinkStack &L,char &e){
    // �ж��Ƿ�ջ��
    if (L->top == -1){
        return false;
    }
    // ջ������Ԫ�� ͬʱջ��ָ���Լ�
    e = (char)L->array[L->top--];
}

/**
 * �ж�ջ�Ƿ��
 * @param L
 * @return
 */
bool isEmpty(LinkStack &L){
    if (L->top == -1){
        return false;
    }
}

void destoryStack(LinkStack &L){
    // �ͷ�ջ�������ڴ�
    free(L->array);
    // �ͷ�ջ�ڴ�ռ�
    free(L);
}



/**
 *
 * @param decimal ��ת��������
 * @param base ת���ɼ�����
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
    printf("����Ҫת��������:\n");
    scanf("%d",&decimal);
    printf("����Ҫת���Ļ���:\n");
    scanf("%d",&base);
    decimal_to_base(L,decimal,base);
}