////
//// Created by 张俊鹏 on 2017/7/19.
////
//
//
//#include <mem.h>
//#include <stdio.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXSIZE 100 /* 存储空间初始分配量 */
//
//typedef int Status;        /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//
//typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */
//
//void get_next(String T, int *next) {
//    int pre = 0, end = 1;/*用于指向下标，初始化的时候设置为 0，1*/
//    next[1] = 0;
//    while (end < T[0]) {    /*当end索引指向最后一个元素的时候，next数组已经生成*/
//        if (0 == pre || T[pre] == T[end]) {   /*如果pre和end索引指向的元素相同的时候，说明可以跳过该循环*/
//            pre++;
//            end++;
//            if (T[pre] != T[end]) {
//                next[end] = pre;    /*下一个元素如果匹配失败跳转的位置*/
//            }else{
//                next[end]=next[pre];    /*此处用于防止出现大量连续重复元素的T串，如:"aaaaaab"*/
//            }
//        } else    /*如果指向的两个元素不相同，说明应该在往回找到上一个相同的前索引pre*/
//            pre = next[pre];    /*将pre指向上一个匹配失败的索引，再次判断时候指向的元素是否相同，该操作可能执行多次*/
//    }
//}
//
///*返回子串T在主串S pos个字符之后的位置，若不存在则返回0*/
//int index_KMP(String S, String T, int pos) {
//    int i = pos;
//    int j = 1;
//    int next[255];  /*因为char类型最多存储255个字节*/
//
//    get_next(T, next);
//    while (i <= S[0] && j <= T[0]) {
//        if (0 == j || S[i] == T[j]) {   /*万一出现j跑到0位置的情况，则让主串向后移一位*/
//            i++;
//            j++;
//        } else {    /*如果匹配不成功，则将子串转移相应的位置*/
//            j = next[j];
//        }
//    }
//    if (j > T[0])
//        return i - T[0];
//    else
//        return 0;
//}
//
//void main() {
//    String S = " this is a test,for the god sake,let it pass!";
//    int a = strlen(S);
//    S[0] = a - 1;
//    String T = " god";
//    T[0] = 3;
//
//    a = index_KMP(S, T, 1);
//    printf("%d", a);
//}