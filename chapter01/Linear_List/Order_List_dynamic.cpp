/**
 * @description: 顺序表的静态动态实现
 * @author Kenton
 * @date 2023/11/2 9:08
 * @version 1.0
 */

#include "stdio.h"
#include "malloc.h"

// 顺序表的初始长度
#define InitSize 10

typedef int Element;

typedef struct {
    // 动态分配数组的指针
    Element *data;
    // 顺序表的最大容量
    int MaxSize;
    // 当前顺序表的长度
    int length;
}SeqList;

/**
 * 初始化动态分配顺序表
 * @param L
 */
void InitList(SeqList &L){
    // 动态分配内存空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    // 初始没有元素 长度为0
    L.length = 0;
    // 最大容量为当前申请到的空间
    L.MaxSize = InitSize;
}

/**
 * 增加动态数组的容量
 * 静态分组的原理就是申请新的空间 将原来的空间的值复制到新空间 并将原空间内存释放
 * @param L
 * @param len
 */
void IncreaseSize(SeqList &L,int len){
    // 用指针p记录原来链表记录数组的指针的地址
    int *p = L.data;
    // 在原来容量的条件下额外加上新增的容量 申请一段新的空间
    L.data = (int *) malloc((L.MaxSize+len) * sizeof(Element));
    for (int i = 0; i < L.length; ++i) {
        // 把原来的数据从头到尾复制到新申请的空间
        L.data[i] = p[i];
    }
    // 顺序表最大长度增加len
    L.MaxSize += len;
    // 释放原来存储元素的空间
    free(p);
}

/**
 * 动态顺序表删除第i个
 * @param L
 * @param i
 * @param element
 * @return
 */
bool SeqListDelete (SeqList &L,int i,int &element){
    // 判断i的范围是否有效 插入位置i-1为下标 即i-1<0显然是不合法的
    if (i < 1 || i > L.length){
        return false;
    }
    // 将被删除的元素赋值给element
    element = L.data[i-1];
    // 将第i个位置后面的元素迁前移

    /**
     * 最好情况:删除表尾元素 不需要移动元素 复杂度为O(1)
     * 最坏情况:删除表头元素 后面n-1个元素全都前移 复杂度为O(n)
     */
    for (int j = i; j < L.length; ++j) {
        L.data[j-1] = L.data[j];
    }
    // 线性表长度-1
    L.length--;
    return true;
}

/**
 * 在顺序表中查找第一个元素值为element的元素 并返回是第几个元素
 * @param L 顺序表
 * @param element 被查的元素值
 * @return 返回第几个元素
 */
int LocateElem(SeqList L, Element element){
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == element){
            return i+1;
        }
    }
}


int main(int argc,char *const argv[]){
    // 声明动态顺序表
    SeqList L;
    // 初始化动态顺序表
    InitList(L);
    //
}