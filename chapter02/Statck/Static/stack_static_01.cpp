/**
 * @description: ˳��ջ ��ʼջ���ָ��-1
 * @author Kenton
 * @date 2023/11/6 8:46
 * @version 1.0
 */

#include "stdio.h"
// ����ջ��Ԫ�ص�������
#define MaxSize 10
#define ElemType int

typedef struct {
    // ��̬������ջ��Ԫ��
    ElemType data[MaxSize];
    // ջ��ָ��
    int top;
}SqStack; // sequence ˳��

/**
* ˳��洢:����������Ԫ�ط��������Ĵ洢�ռ� ��СΪ:MaxSize * sizeof(ElemType)
*/

/**
 * ��ʼ��ջ
 * @param S
 */
void InitStack(SqStack &S){
    // ��ʼ��ջ��ָ��
    S.top = -1;
}

/**
 * �ж��Ƿ�ջ��
 * @param S
 * @return
 */
bool StackEmpty(SqStack S){
    if (S.top == -1){
        // ջ��
        return true;
    } else{
        // �ǿ�
        return false;
    }
}

/**
 * ��Ԫ����ջ
 * @param S ջ
 * @param x ��ջ����Ԫ��
 * @return
 */
bool Push(SqStack &S,ElemType x){
    if (S.top == MaxSize - 1){
        // ջ�� ����
        return false;
    }
    // ָ���ȼ�1
    S.top += 1;
    // ��Ԫ����ջ
    S.data[S.top] = x;
    return true;
}

/**
 * ��ջ����
 * @param S ջ
 * @param x ��ջ��Ԫ��
 * @return
 */
bool Pop(SqStack &S,ElemType &x){
    if (S.top == -1){
        // ջ�ձ���
        return false;
    }
    // ջ��Ԫ���ȳ�ջ
    x = S.data[S.top];
    S.top -= 1;
    return true;
}

/**
 * ��ȡջԪ��
 * @param S ջ
 * @param x �鿴��ջԪ��
 * @return
 */
bool GetTop(SqStack S,ElemType &x){
    if (S.top == -1 ){
        // ջ��
        return false;
    }
    x = S.data[S.top];
    return true;
}


int main(int argc,char  *const atgv[]){
    // ��ջ����
    SqStack s;
    int a = 10;
    printf("%d\n", Push(s,a));

    // ��ջ����
    int temp;
    Pop(s,temp);
    printf("��ջ�ɹ�\n");
    printf("temp=%d\n",temp);
}