////
//// Created by �ſ��� on 2017/11/18.
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
//#define MAXSIZE 10000  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
//typedef struct {
//    int r[MAXSIZE + 1];    /* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
//    int length;            /* ���ڼ�¼˳���ĳ��� */
//
//    int count, swapCount;
//} SqList;
//
///* ����L������r���±�Ϊi��j��ֵ */
//void swap(SqList *L, int i, int j) {
//    int temp = L->r[i];
//    L->r[i] = L->r[j];
//    L->r[j] = temp;
//}
//
//void print(SqList L) {
//    printf("����������%d,�ƶ�������%d \n�����", L.count, L.swapCount);
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
//                swap(L, i, j);/* ����L->r[i]��L->r[j]��ֵ */
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
//        L->r[0] = i;/*L->r[0]���ڴ洢��Сֵ*/
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
//                for (j = i - gap; j > 0 && L->r[j] > L->r[0]; j -= gap) {/*�˴���Ҫר�ű������ɷ�������*/
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
//        if (i < n && L->r[i] < L->r[i + 1])/*ָ���ӽڵ��нϴ��λ��*/
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
//    while (i < list1_size && j < list2_size) {/*��С�������*/
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
//    int *tmp = (int *) malloc(n * sizeof(int));/*��ʱ���飬���ڴ洢�м���*/
//    int i, left_min, left_max, right_min, right_max;
//    for (i = 1; i < n; i *= 2) {/*�˴���i�����߼�����*/
//        for (left_min = 0; left_min < n - 1; left_min = right_max) {
//            right_min = left_max = left_min + i;
//            right_max = right_min + i;
//            if (right_max > n)/*�Է�Խ��*/
//                right_max = n;
//
//            int next = 0;
//            while (left_min < left_max && right_min < right_max) {
//                if (arr[left_min] < arr[right_min])
//                    tmp[next++] = arr[left_min++];
//                else
//                    tmp[next++] = arr[right_min];
//            }
//            while (left_min < left_max)/*��ʣ������Ԫ�طŵ��������*/
//                arr[--right_min] = arr[--left_max];
//            while (next > 0)/*����ʱ�����е�Ԫ�طŻ�*/
//                arr[--right_min] = tmp[--next];
//        }
//    }
//}
//
//void MergeSort2(SqList *L) {
//    MSort2(&(L->r[1]), L->length);
//}
//
///*��������������ĺ���*/
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
///* �Ľ����������******************************** */
//int Partition1(SqList *L, int low, int high) {
//    /*Ϊ�˷�ֹ�����ѡȡ���ڲ������ֵ�˷����ܣ�ѡȡ�������е���ֵ��Ϊ�����*/
//    int m = low + (high - low) / 2;
//    if (L->r[low] > L->r[high])
//        swap(L, low, high);
//    if (L->r[m] > L->r[high])     /*�˲�Ϊֹ��highΪ���ֵ*/
//        swap(L, m, high);
//    if (L->r[low] < L->r[m])      /*��lowΪֹ����Ϊ�м�ֵ*/
//        swap(L, low, m);
//
//    int pivotKey = L->r[low];
//
//    while (low < high) {
//        while (low < high && L->r[high] > pivotKey)
//            high--;
//        L->r[low] = L->r[high];    /*����ֱ���滻�����Ԫ�ظ�ֵ��ȥ����*/
//        while (low < high && L->r[low] < pivotKey)
//            low++;
//        L->r[high] = L->r[low];      /*����ֱ���滻�����Ԫ�ظ�ֵ��ȥ����*/
//    }
//    L->r[low] = pivotKey;     /*��Ԫ�����*/
//    return low;
//}
//
//#define MAX_LENGTH_INSERT_SORT 7
//
//void QSort1(SqList *L, int low, int high) {
//    int pivot;
//    if ((high - low) > MAX_LENGTH_INSERT_SORT) {  /*��Ϊ��������ʹ���˵ݹ飬��С��ģ������ʹ�ò�������*/
//        while (low < high) {
//            pivot = Partition(L, low, high);
//            QSort(L, low, pivot - 1);
////            QSort(L, pivot + 1, high);
//            low = pivot + 1;    /*β�ݹ����ʽ�����ڽ�Լջ�ռ�*/
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
//    printf("����ǰ:\n");
//    print(l0);
//
//    printf("����ð������:\n");
//    BubbleSort_stupid(&l0);
//    print(l0);
//
//    printf("ð������:\n");
//    BubbleSort_normal(&l1);
//    print(l1);
//
//    printf("�Ľ�ð������:\n");
//    BubbleSort_advanced(&l2);
//    print(l2);
//
//    printf("ѡ������:\n");
//    SelectSort(&l3);
//    print(l3);
//
//    printf("ֱ�Ӳ�������:\n");
//    InsertSort(&l4);
//    print(l4);
//
//    printf("ϣ������:\n");
//    ShellSort(&l5);
//    print(l5);
//
//    printf("������:\n");
//    HeapSort(&l6);
//    print(l6);
//
//    printf("�鲢���򣨵ݹ飩:\n");
//    MergeSort(&l7);
//    print(l7);
//
////    printf("�鲢���򣨷ǵݹ飩:\n");
////    MergeSort2(&l8);
////    print(l8);
//
//    printf("��������:\n");
//    QuickSort(&l9);
//    print(l9);
//
//    printf("�Ľ���������:\n");
//    QuickSort1(&l10);
//    print(l10);
//
//
//    /*����������*/
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
