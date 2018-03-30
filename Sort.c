////
//// Created by 张俊鹏 on 2017/11/18.
////
//
//#include <stdio.h>
//#include <malloc.h>
//#include <time.h>
//
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;
//
//
//#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
//typedef struct {
//    int r[MAXSIZE + 1];    /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
//    int length;            /* 用于记录顺序表的长度 */
//
//    int count, swapCount;
//} SqList;
//
///* 交换L中数组r的下标为i和j的值 */
//void swap(SqList *L, int i, int j) {
//    int temp = L->r[i];
//    L->r[i] = L->r[j];
//    L->r[j] = temp;
//}
//
//void print(SqList L) {
//    printf("遍历次数：%d,移动次数：%d \n结果：", L.count, L.swapCount);
//    int i;
//    for (i = 1; i < L.length; i++)
//        printf("%d,", L.r[i]);
//    printf("%d", L.r[i]);
//    printf("\n\n");
//}
//
//void BubbleSort_stupid(SqList *L) {
//    L->count = L->swapCount = 0;
//    for (int i = 1; i < L->length; ++i) {
//        for (int j = i + 1; j <= L->length; ++j) {
//            L->count++;
//            if (L->r[i] > L->r[j]) {
//                L->swapCount++;
//                swap(L, i, j);/* 交换L->r[i]与L->r[j]的值 */
//            }
//        }
//    }
//}
//
//void BubbleSort_normal(SqList *L) {
//    L->count = L->swapCount = 0;
//    for (int i = 0; i < L->length; ++i) {
//        for (int j = L->length - 1; j > i; --j) {
//            L->count++;
//            if (L->r[j] > L->r[j + 1]) {
//                L->swapCount++;
//                swap(L, j, j + 1);
//            }
//        }
//    }
//}
//
//void BubbleSort_advanced(SqList *L) {
//    L->count = L->swapCount = 0;
//    Status flag = TRUE;
//    for (int i = 0; i < L->length && flag; ++i) {
//        flag = FALSE;
//        for (int j = L->length - 1; j > i; --j) {
//            L->count++;
//            if (L->r[j] > L->r[j + 1]) {
//                L->swapCount++;
//                swap(L, j, j + 1);
//                flag = TRUE;
//            }
//        }
//    }
//}
//
//void SelectSort(SqList *L) {
//    L->count = L->swapCount = 0;
//    for (int i = 1; i < L->length; ++i) {
//        L->r[0] = i;/*L->r[0]用于存储最小值*/
//        for (int j = i + 1; j <= L->length; ++j) {
//            L->count++;
//            if (L->r[L->r[0]] > L->r[j])
//                L->r[0] = j;
//        }
//        if (L->r[0] != i) {
//            L->swapCount++;
//            swap(L, i, L->r[0]);
//        }
//    }
//}
//
//void InsertSort(SqList *L) {
//    L->count = L->swapCount = 0;
//    for (int i = 2; i <= L->length; ++i) {
//        L->count++;
//        if (L->r[i] < L->r[i - 1]) {
//            L->r[0] = L->r[i];
//            int j;
//            for (j = i - 1; L->r[j] > L->r[0]; --j) {
//                L->swapCount++;
//                L->r[j + 1] = L->r[j];
//            }
//            L->r[j + 1] = L->r[0];
//        }
//    }
//}
//
//void ShellSort(SqList *L) {
////    L->count = L->swapCount = 0;
//    int gap = L->length;
//    do {
//        gap = gap % 2 + 1;
//        for (int i = gap + 1; i <= L->length; ++i) {
////            L->count++;
//            if (L->r[i] < L->r[i - gap]) {
//                L->r[0] = L->r[i];
//                int j;
//                for (j = i - gap; j > 0 && L->r[j] > L->r[0]; j -= gap) {/*此处需要专门保护不可访问区域*/
////                    L->swapCount++;
//                    L->r[j + gap] = L->r[j];
//                }
//                L->r[j + gap] = L->r[0];
//            }
//        }
//    } while (gap > 1);
//}
//
//void HeapAdjust(SqList *L, int s, int n) {
//    L->count++;
//    int i, tmp;
//    tmp = L->r[s];
//    for (i = 2 * s; i <= n; ++i) {
//        if (i < n && L->r[i] < L->r[i + 1])/*指向子节点中较大的位置*/
//            i++;
//        if (tmp >= L->r[i])
//            break;
//        L->r[s] = L->r[i];
//        s = i;
//    }
//    L->r[s] = tmp;
//}
//
//void HeapSort(SqList *L) {
//    L->count = L->swapCount = 0;
//
//    int i;
//    for (i = L->length / 2; i > 0; i--)
//        HeapAdjust(L, i, L->length);
//    for (i = L->length; i > 1; i--) {
//        L->swapCount++;
//        swap(L, 1, i);
//        HeapAdjust(L, 1, i - 1);
//    }
//}
//
//void Merging(int list1[], int list1_size, int list2[], int list2_size) {
//    int i, j, k;
//    i = j = k = 0;
//    int tmp[MAXSIZE];
//    while (i < list1_size && j < list2_size) {/*从小到大插入*/
//        if (list1[i] < list2[j])
//            tmp[k++] = list1[i++];
//        else
//            tmp[k++] = list2[j++];
//    }
//    while (i < list1_size) {
//        tmp[k++] = list1[i++];
//    }
//    while (j < list2_size) {
//        tmp[k++] = list2[j++];
//    }
//    for (i = 0; i < list1_size + list2_size; ++i) {
//        list1[i] = tmp[i];
//    }
//}
//
//void MSort(int *arr, int size) {
//    if (size > 1) {
//        int *list1 = arr;
//        int list1_size = size / 2;
//        int *list2 = arr + list1_size;
//        int list2_size = size - list1_size;
//
//        MSort(list1, list1_size);
//        MSort(list2, list2_size);
//
//        Merging(list1, list1_size, list2, list2_size);
//    }
//}
//
//void MergeSort(SqList *L) {
//    MSort(&(L->r[1]), L->length);
//}
//
//void MSort2(int arr[], int n) {
//    int *tmp = (int *) malloc(n * sizeof(int));/*临时数组，用于存储中间结果*/
//    int i, left_min, left_max, right_min, right_max;
//    for (i = 1; i < n; i *= 2) {/*此处的i用于逻辑划分*/
//        for (left_min = 0; left_min < n - 1; left_min = right_max) {
//            right_min = left_max = left_min + i;
//            right_max = right_min + i;
//            if (right_max > n)/*以防越界*/
//                right_max = n;
//
//            int next = 0;
//            while (left_min < left_max && right_min < right_max) {
//                if (arr[left_min] < arr[right_min])
//                    tmp[next++] = arr[left_min++];
//                else
//                    tmp[next++] = arr[right_min];
//            }
//            while (left_min < left_max)/*将剩余的最大元素放到数组最后*/
//                arr[--right_min] = arr[--left_max];
//            while (next > 0)/*将临时数组中的元素放回*/
//                arr[--right_min] = tmp[--next];
//        }
//    }
//}
//
//void MergeSort2(SqList *L) {
//    MSort2(&(L->r[1]), L->length);
//}
//
///*真正对数组排序的函数*/
//int Partition(SqList *L, int low, int high) {
//    int pivotKey = L->r[low];
//
//    while (low < high) {
//        while (low < high && L->r[high] > pivotKey)
//            high--;
//        swap(L, low, high);
//        while (low < high && L->r[low] < pivotKey)
//            low++;
//        swap(L, low, high);
//    }
//    return low;
//}
//
//void QSort(SqList *L, int low, int high) {
//    int pivot;
//    if (low < high) {
//        pivot = Partition(L, low, high);
//        QSort(L, low, pivot - 1);
//        QSort(L, pivot + 1, high);
//    }
//}
//
//void QuickSort(SqList *L) {
//    QSort(L, 1, L->length);
//}
//
///* **************************************** */
//
///* 改进后快速排序******************************** */
//int Partition1(SqList *L, int low, int high) {
//    /*为了防止中轴点选取过于不合理的值浪费性能，选取三个点中的中值作为中轴点*/
//    int m = low + (high - low) / 2;
//    if (L->r[low] > L->r[high])
//        swap(L, low, high);
//    if (L->r[m] > L->r[high])     /*此步为止，high为最大值*/
//        swap(L, m, high);
//    if (L->r[low] < L->r[m])      /*将low为止设置为中间值*/
//        swap(L, low, m);
//
//    int pivotKey = L->r[low];
//
//    while (low < high) {
//        while (low < high && L->r[high] > pivotKey)
//            high--;
//        L->r[low] = L->r[high];    /*可以直接替换，最后将元素赋值回去即可*/
//        while (low < high && L->r[low] < pivotKey)
//            low++;
//        L->r[high] = L->r[low];      /*可以直接替换，最后将元素赋值回去即可*/
//    }
//    L->r[low] = pivotKey;     /*将元素填回*/
//    return low;
//}
//
//#define MAX_LENGTH_INSERT_SORT 7
//
//void QSort1(SqList *L, int low, int high) {
//    int pivot;
//    if ((high - low) > MAX_LENGTH_INSERT_SORT) {  /*因为快速排序使用了递归，在小规模排序中使用插入排序*/
//        while (low < high) {
//            pivot = Partition(L, low, high);
//            QSort(L, low, pivot - 1);
////            QSort(L, pivot + 1, high);
//            low = pivot + 1;    /*尾递归的形式有利于节约栈空间*/
//        }
//    } else {
//        InsertSort(L);
//    }
//}
//
//void QuickSort1(SqList *L) {
//    QSort(L, 1, L->length);
//}
//
//#define N 9
//
//int main() {
//    int i;
//
//    /* int d[N]={9,1,5,8,3,7,4,6,2}; */
//    int d[N] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
//    /* int d[N]={9,8,7,6,5,4,3,2,1}; */
//
//    SqList l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
//
//    for (i = 0; i < N; i++)
//        l0.r[i + 1] = d[i];
//    l0.length = N;
//    l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l0;
//    printf("排序前:\n");
//    print(l0);
//
//    printf("初级冒泡排序:\n");
//    BubbleSort_stupid(&l0);
//    print(l0);
//
//    printf("冒泡排序:\n");
//    BubbleSort_normal(&l1);
//    print(l1);
//
//    printf("改进冒泡排序:\n");
//    BubbleSort_advanced(&l2);
//    print(l2);
//
//    printf("选择排序:\n");
//    SelectSort(&l3);
//    print(l3);
//
//    printf("直接插入排序:\n");
//    InsertSort(&l4);
//    print(l4);
//
//    printf("希尔排序:\n");
//    ShellSort(&l5);
//    print(l5);
//
//    printf("堆排序:\n");
//    HeapSort(&l6);
//    print(l6);
//
//    printf("归并排序（递归）:\n");
//    MergeSort(&l7);
//    print(l7);
//
////    printf("归并排序（非递归）:\n");
////    MergeSort2(&l8);
////    print(l8);
//
//    printf("快速排序:\n");
//    QuickSort(&l9);
//    print(l9);
//
//    printf("改进快速排序:\n");
//    QuickSort1(&l10);
//    print(l10);
//
//
//    /*大数据排序*/
//
//    srand((unsigned int) time(0));
//    int Max = 10000;
//    int D[10000];
//    SqList a;
//    for (i = 0; i < Max; i++)
//        D[i] = rand() % Max + 1;
//    for (i = 0; i < Max; i++)
//        a.r[i + 1] = D[i];
//    a.length = Max;
//    MergeSort(&a);
//    print(a);
//
//    return 0;
//}
