//
////
//// Created by �ſ��� on 2017/7/11.
////
//#include <stdio.h>
//#include <mem.h>
//#include <stdlib.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 10 /* �洢�ռ��ʼ������ */
//
//typedef int Status;        /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int ElemType;    /* ElemType���͸���ʵ������������������Ϊint */
//
//typedef char String[MAXSIZE + 1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
//
///*����һ����ֵ����chars�Ĵ�T*/
//Status StrAssign(String T, char *chars) {
//    if (strlen(chars) > MAXSIZE)
//        return ERROR;
//    else {
//        T[0] = strlen(chars);
//        for (int i = 0; i < T[0]; ++i)
//            T[i + 1] = *(chars + i);
//        return OK;
//    }
//}
//
///*�ɴ�S��ֵ�ô�T*/
//Status StrCopy(String T, String S) {
//    for (int i = 0; i <= S[0]; ++i)
//        T[i] = S[i];
//    return OK;
//}
//
///*�жϴ��Ƿ�Ϊ��*/
//Status StrEmpty(String S) {
//    if (S[0] == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///*  ��ʼ����: ��S��T���� */
///*  �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
//int StrCompare(String S, String T) {
//    for (int i = 0; i <= S[0] && i <= T[0]; ++i) {
//        if (S[i] != T[i])
//            return S[i] - T[i];
//    }
//    return S[0] - T[0];
//}
//
///* ���ش���Ԫ�ظ��� */
//int StrLength(String S) {
//    return S[0];
//}
//
///* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
//Status ClearString(String S) {
//    S[0] = 0;/*  ���Ϊ�� */
//    return OK;
//}
//
///* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
//Status Concat(String T, String S1, String S2) {
//    int i;
//    if (S1[0] + S2[0] <= MAXSIZE) {
//        for (i = 1; i <= S1[0]; ++i)
//            T[i] = S1[i];
//        for (i = 1; i <= S2[0]; i++)
//            T[S1[0] + i] = S2[i];
//        T[0] = S1[0] + S2[0];
//        return TRUE;
//    } else {
//        for (i = 1; i <= S1[0]; i++)
//            T[i] = S1[i];
//        for (i = 1; i <= MAXSIZE - S1[0]; i++)
//            T[S1[0] + i] = S2[i];
//        T[0] = MAXSIZE;
//        return FALSE;
//    }
//}
//
///* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
//Status SubString(String Sub, String S, int pos, int len) {
//    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
//        return ERROR;
//    for (int i = 1; i <= len; ++i)
//        Sub[i] = S[pos + i - 1];
//    Sub[0] = len;
//    return OK;
//}
//
///* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
///* ����,T�ǿ�,1��pos��StrLength(S)�� */
//int Index(String S, String T, int pos) {
//    int i = pos;    /*i��������S�е�ǰλ���±꣬��pos��Ϊ1�����posλ�ÿ�ʼƥ��*/
//    int j = 1;  /*j�����Ӵ�T�е�ǰλ�õ��±�*/
//    while (i <= S[0] && j <= T[0]) {    /*��iС��S�ĳ�����С��T�ĳ��ȣ���ѭ��*/
//        if (S[i] == T[j]) {/* ����ĸ�������� */
//            i++;
//            j++;
//        } else {/* ָ��������¿�ʼƥ�� */
//            i = i - j + 2;/* i�˻ص��ϴ�ƥ����λ����һλ */
//            /*�����ֵ��Ҫ+1���ټ���������λ�����������鳤�ȣ�����+2*/
//            j = 1;/* j�˻ص��Ӵ�T����λ */
//        }
//    }
//    if (j > T[0])/*�������T��Ԫ����ƥ�䣬��j���T�ĳ��ȴ�1*/
//        return i - T[0];/*���ص����߼�λ��*/
//    else
//        return 0;
//}
//
///*  TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ��� */
///*  �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 */
//int Index2(String S, String T, int pos) {
//    int n, m, i;
//    String sub;
//    if (pos > 0) {
//        n = StrLength(S);
//        m = StrLength(T);
//        i = pos;
//        while (i <= n - m + 1) {
//            SubString(sub, S, i, m);   /*�������е�i��λ��ȡ��m���ַ�*/
//            if (StrCompare(sub, T) != 0)   /*������Ӵ������*/
//                ++i;
//            else
//                return i;
//        }
//    }
//    return 0;
//}
//
///*  ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
///*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
//Status StrInsert(String S, int pos, String T) {
//    int i;
//    if (pos < 1 || pos > S[0] + 1)
//        return ERROR;
//    if (S[0] + T[0] <= MAXSIZE) {    /*��ȫ����*/
//        for (i = S[0]; i >= pos; i--)   /*��posλ�ü��Ժ��Ԫ������ƶ�T[0]��λ��*/
//            S[i + T[0]] = S[i];
//        for (i = pos; i < pos + T[0]; i++)  /*���ƶ�����T[0]��λ����T�е�Ԫ��*/
//            S[i] = T[i - pos + 1];
//        S[0] = S[0] + T[0];
//        return TRUE;
//    } else {
//        for (i = MAXSIZE; i >= pos+T[0]; i--)    /*��posλ�õ��ļ�ĩβ��Ԫ���ƶ�*/
//            S[i] = S[i - T[0]];
//        for (i=1;i<=T[0];i++)
//            S[pos+i-1]=T[i];
//        S[0] = MAXSIZE;
//        return FALSE;
//    }
//}
//
///*  ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
///*  �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
//Status StrDelete(String S, int pos, int len) {
//    int i;
//    if (pos < 1 || pos > S[0] - len + 1 || len < 0)
//        return ERROR;
//    for (i = pos + len; i <= S[0]; i++)  /*������м��ȡ���򽫺�ߵ��ַ����ƶ���Ҫɾ����λ��*/
//        S[i - len] = S[i];
//    S[0] -= len;
//    return OK;
//}
//
///*  ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
///*  �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
//Status Replace(String S, String T, String V) {
//    if (StrEmpty(T))
//        return ERROR;
//    int i = 1;    /*�Ӵ�S�ĵ�һ���ַ������Ҵ�T*/
//    do {
//        i = Index(S, T, i); /*  ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
//        if (i) {
//            StrDelete(S, i, StrLength(T));
//            StrInsert(S, i, V);
//            i += StrLength(V);    /*�ڲ���Ĵ�V����������Ҵ�T*/
//        }
//    } while (i);
//    return OK;
//}
//
//void StrPrint(String T) {
//    int i;
//    for (i = 1; i <= T[0]; i++)
//        printf("%c", T[i]);
//    printf("\n");
//}
//
//int main() {
//
//    int i, j;
//    Status k;
//    char s;
//    String t, s1, s2;
//    printf("�����봮s1: ");
//
//    k = StrAssign(s1, "abcd");
//    StrPrint(s1);
//    if (!k) {
//        printf("��������MAXSIZE(=%d)\n", MAXSIZE);
//        exit(0);
//    }
//    printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n", StrLength(s1), StrEmpty(s1));
//    StrCopy(s2, s1);
//    printf("����s1���ɵĴ�Ϊ: ");
//    StrPrint(s2);
//    printf("�����봮s2: ");
//
//    k = StrAssign(s2, "efghijk");
//    StrPrint(s2);
//
//    if (!k) {
//        printf("��������MAXSIZE(%d)\n", MAXSIZE);
//        exit(0);
//    }
//    i = StrCompare(s1, s2);
//    if (i < 0)
//        s = '<';
//    else if (i == 0)
//        s = '=';
//    else
//        s = '>';
//    printf("��s1%c��s2\n", s);
//    k = Concat(t, s1, s2);
//    printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
//    StrPrint(t);
//    printf("%d\n", k);
//    if (k == FALSE)
//        printf("��t�нض�\n");
//    ClearString(s1);
//    printf("��Ϊ�մ���,��s1Ϊ: ");
//    StrPrint(s1);
//    printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n", StrLength(s1), StrEmpty(s1));
//    printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");
//
//    i = 2;
//    j = 3;
//    printf("%d,%d \n", i, j);
//
//    k = SubString(s2, t, i, j);
//    if (k) {
//        printf("�Ӵ�s2Ϊ: ");
//        StrPrint(s2);
//    }
//    printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
//
//    i = 4;
//    j = 2;
//    printf("%d,%d \n", i, j);
//
//
//    StrDelete(t, i, j);
//    printf("ɾ����Ĵ�tΪ: ");
//    StrPrint(t);
//    i = StrLength(s2) / 2;
//    StrInsert(s2, i, t);
//    printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n", i);
//    StrPrint(s2);
//    i = Index(s2, t, 1);
//    printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n", i);
//    SubString(t, s2, 1, 1);
//    printf("��tΪ��");
//    StrPrint(t);
//    Concat(s1, t, t);
//    printf("��s1Ϊ��");
//    StrPrint(s1);
//    Replace(s2, t, s1);
//    printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
//    StrPrint(s2);
//
//
//    return 0;
//}
//
//
