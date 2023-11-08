/**
 * @description: 顺序表的静态实现
 * @author Kenton
 * @date 2023/11/2 8:21
 * @version 1.0
 */

// 定义顺序表的最大长度
#define Maxsize 10

// 将顺序表元素类型别名为ELemType
typedef int ELemType;

typedef struct {
    // 静态数组存放数据 即给定的长度 固定分配的内存空间
    ELemType date[Maxsize];
    // 顺序表的当前长度
    int length;
}SqList;

/**
 * 初始化静态顺序表
 * @param L 传入的顺序表
 */
void InitList(SqList &L){
    for (int i = 0; i < Maxsize; ++i) {
        // 所有元素设置为默认0 因为顺序表空间是向内存申请的 如果没有设置默认值 可能内存留有脏数据
        L.date[i] = 0;
    }
    // 初始化长度为0
    L.length = 0;
}

 /**
  *
  * 顺序表L的i位置插入元素element
  * @param L 顺序表
  * @param i 插入的位置
  * @param element 插入的元素
  * @return 判断是否插入成功
  */
bool ListInsert(SqList &L,int i,int element){
     // 判断i的范围是否有效 插入位置i-1为下标 即i-1<0显然是不合法的
     if (i < 1 || i > L.length + 1){
         return false;
     }
     // 当前存储空间已经满 不能插入
     if (L.length >= Maxsize){
         return false;
     }
    /**
     * 插入实现原理:
     * 原顺序表的长度为length 数组下标从0开始存储即 最后一个元素下标为j-1
     * 插入一个元素 即新数组最后一个元素下标为j 同时j <= Maxsize
     * 利用for循环把j下标之前的元素往后面放 直到第i的位置
     * 到最后把i-1位置的值复制到i
     * 循环结束 我们在i位置插入元素 即在i-1的下标赋值 L.date[i-1] = element
     * 最后 自增结构体记录顺序表长度的length 即完成插入 长度+1
     */

     /**
      * 最好情况:新元素插入到表尾 不需要移动元素 i = n + 1 循环0次 最好复杂度为=O(1)
      * 最坏情况:新元素插入到表头 需要将原来的n个元素全部后移 i = 1 循环n次 最坏复杂度=O(n)
      */
    for (int j = L.length;j >= i;--j) {
        L.date[j] = L.date[j-1];
    }
    L.date[i-1] = element;
    L.length++;
    return true;
}

/**
 * 顺序表删除元素
 * @param L
 * @param i
 * @param element
 * @return
 */
bool ListDelete(SqList &L,int i,int &element){
    // 判断i的范围是否有效 插入位置i-1为下标 即i-1<0显然是不合法的
    if (i < 1 || i > L.length){
        return false;
    }
    // 将被删除的元素赋值给element
    element = L.date[i-1];
    // 将第i个位置后面的元素迁前移

    /**
     * 最好情况:删除表尾元素 不需要移动元素 复杂度为O(1)
     * 最坏情况:删除表头元素 后面n-1个元素全都前移 复杂度为O(n)
     */
    for (int j = i; j < L.length; ++j) {
        L.date[j-1] = L.date[j];
    }
    // 线性表长度-1
    L.length--;
    return true;
}

/**
 * 按位查找 返回第i个位置的元素值
 * @param L
 * @param i
 * @return
 */
ELemType GetElem(SqList L,int i){
    // 判断i的范围是否有效

    /**
     * 最好复杂度 循环1次 O(1)
     * 最坏复杂度 循环n O(n)
     */
    if (i < 1 || i > L.length){
        return false;
    }
    return L.date[i-1];
}


int main(int argc,char *const argv[]){
    // 声明动态顺序表
    SqList(L);
    // 初始化动静态顺序表
    InitList(L);
    //
}