/**
 * @description: 顺序栈的实现和运算
 * @author 2350513316 李成鑫
 * @date 2023/11/8 19:07
 * @version 1.0
 */

#include <stdio.h>

#include <stdlib.h>

// 定义一个宏 操作成功 值为1
#define OK  1
// 定义一个宏 操作失败 值为0
#define ERROR  0
// 定义一个宏，表示逻辑真，值为1。
#define TRUE 1
// 定义一个宏，表示逻辑假，值为0。
#define FALSE 0
// 定义一个宏，表示内存溢出，值为-2。
#define OVERFLOW  -2

typedef int ElemType;

typedef int Status;

//----- 栈的顺序存储表示 -----

// 存储空间的初始分配量
#define STACK_INIT_SIZE 10
// 存储空间的分配增量
#define STACKINCREMENT 5
// 定义两个宏，分别表示栈的初始大小和每次增长的增量

typedef struct {
    // 栈顶指针
    int top;
    // 存储空间的原始地址
    ElemType *array;
    // 栈的大小
    int size;
    // 扩容时，增加的存储容量
    int increment;
} SqStack;


/**
 * 构造一个空栈 S 初始化
 * @param S
 * @return
 */
Status InitStack(SqStack &S) {

    // 给栈数组分配空间 如果分配失败退出程序
    S.array = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    //
    if (!S.array) {
        // 使用malloc函数分配内存空间，并将分配的内存空间的首地址赋值给array指针变量。
        // 如果分配失败（即返回NULL），则调用exit函数结束程序运行，并返回错误代码OVERFLOW。
        exit(OVERFLOW);
    }

    // 栈顶指针置为0 表示空栈
    S.top = 0;
    // 将栈的大小置为初始值
    S.size = STACK_INIT_SIZE;
    // 将每次扩容的增量置为给定值
    S.increment = STACKINCREMENT;
    // 返回成功状态码OK
    return OK;

}

/**
 * 判断栈S是否为空，如果栈顶指针为0则返回TRUE（真），否则返回FALSE（假）
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
 * 入栈函数
 * @param S 栈
 * @param e 压栈的数
 * @return
 */
Status Push(SqStack &S, ElemType e) {
    // 定义指针 用来记录新申请的空间
    ElemType *newBase;
    // 若栈顶指针已经等于栈数组的容量 则进行扩容
    if (S.top >= S.size){
        // 数组申请空间最好用realloc
        newBase = (ElemType*) realloc(S.array, (S.size + S.increment) * sizeof(ElemType));
        // 如果没有申请到内存 realloc函数返回NULL给newBase
        if (NULL == newBase){
            return OVERFLOW;
        }
        // 将新生成的空间地址传递给array
        S.array = newBase;
        // 更新栈的大小
        S.size += S.increment;
        // 释放空间
        free(newBase);
    }

    // e入栈 栈顶指针+1
    S.array[S.top++] = e;
}


/**
 * 出栈
 * @param S 栈
 * @param e 接收出栈的元素值
 * @return
 */
Status Pop(SqStack &S, ElemType &e) {
    // 判断是否栈空
    if (S.top == 0){
        // 操作失败
        return ERROR;
    }
    // 取出栈顶元素给e 同时栈顶指针自减
    e = S.array[S.top--];
}

//输出顺序栈函数

void OutStack(SqStack S) {
    ElemType e;

    if (TRUE == StackEmpty(S)) {

        printf("这是一个空栈！");

    } else

        while (FALSE == StackEmpty(S)) {

            Pop(S, e);

            printf("%6d", e);

        }

    printf("\n");

}

//主函数

int main() {
    SqStack s;

    int cord;
    ElemType a;

    printf("第一次使用必须初始化！\n");

    do {

        printf("\n 主菜单 \n");

        printf(" 1 初始化顺序栈 ");

        printf(" 2 插入一个元素 ");

        printf(" 3 删除栈顶元素 ");

        printf(" 4 结束程序运行 ");

        printf("\n-------------------------------------------------------------------\n");

        printf("请输入您的选择( 1, 2, 3, 4)\n");

        scanf("%d", &cord);

        printf("\n");

        switch (cord) {
            case 1:

                InitStack(s);

                OutStack(s);

                break;

            case 2:

                printf("请输入要插入的数据元素：a=");

                scanf("%d", &a);

                Push(s, a);

                printf("%d 进栈之后的栈：", a);

                OutStack(s);

                break;

            case 3:

                Pop(s, a);

                printf("栈顶元素 %d 出栈之后的栈：", a);

                OutStack(s);

                break;

            case 4:

                exit(0);

        }

    } while (cord <= 4);

}



