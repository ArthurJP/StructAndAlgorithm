//
// Created by 张俊鹏 on 2017/11/16.
//



#include <stdio.h>

#define MAXSIZE 100 /* 存储空间初始分配量 */
int F[MAXSIZE];

/* 无哨兵顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 */
int Sequential_Search(int *a, int n, int key) {
    for (int i = 1; i < n; ++i) {
        if (key == a[i])
            return i;
    }
    return 0;
}

int Sequential_Search2(int *a, int n, int key) {
    int i = n;
    a[0] = key;
    while (a[i] != key)
        i--;
    return i;
}

int Binary_Search(int *a, int n, int key) {
    int low, mid, high;
    low = 1;
    high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid])
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

int Interpolation_Search(int *a, int n, int key) {
    int low, mid, high;
    low = 1;
    high = n;
    while (low <= high) {
        mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
        if (key < a[mid])
            high = mid - 1;
        else if (key > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

int Fibonacci_Search(int *a, int n, int key) {
    int low, mid, high, i, k = 0;
    low = 1;
    high = n;
    while (n > F[k] - 1)/*此处减一是为了和数组从0开始的特性符合，下同*/
        k++;
    for (i = n; i < F[k] - 1; ++i)
        a[i] = a[n];

    while (low <= high) {
        mid = low + F[k - 1] - 1;
        if (key < a[mid]) {
            high = mid - 1;
            k = k - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
            k = k - 2;
        } else {
            if (mid <= n)/*此处是为了防止返回结果越界，存在可能：匹配到了拓展的区域*/
                return mid;
            else
                return n;
        }
    }
    return 0;
}


int main(void) {

    int a[MAXSIZE + 1], i, result;
    int arr[MAXSIZE] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};

    for (i = 0; i <= MAXSIZE; i++) {
        a[i] = i;
    }
    result = Sequential_Search(a, MAXSIZE, 62);
    printf("Sequential_Search:%d \n", result);
    result = Sequential_Search2(a, MAXSIZE, 62);
    printf("Sequential_Search2:%d \n", result);

    result = Binary_Search(arr, 10, 62);
    printf("Binary_Search:%d \n", result);

    result = Interpolation_Search(arr, 10, 62);
    printf("Interpolation_Search:%d \n", result);


    F[0] = 0;
    F[1] = 1;
    for (i = 2; i < 100; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    result = Fibonacci_Search(arr, 10, 62);
    printf("Fibonacci_Search:%d \n", result);

    return 0;
}

