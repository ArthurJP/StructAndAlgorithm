////
//// Created by �ſ��� on 2017/6/30.
////
//
//#include <stdio.h>
//#include <malloc.h>
//#include <time.h>
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
//
//Status visit(ElemType c) {
//    printf("%d ", c);
//    return OK;
//}
//
///*
// * Ϊ�˱�֤���в�����һ���ԣ����ͷ��㣬ͷָ��ָ��ͷ���
// * ͷ���û��ʵ�����壬�������ڱ�������ĳ���
// * ͷ��㲻������ı�ҪԪ�أ�ɾ������Ҫ�ܶ�λ���жϣ��ð�����ѡ��ʹ�ÿռ任ʱ��
// */
//typedef struct Node {
//    ElemType data;  //������
//    struct Node *next;//ָ����
//} Node;
//
//typedef struct Node *LinkList;//����ָ�����ͽ��
//
///* ��ʼ��˳�����Ա� */
//Status InitList(LinkList *L) {
//    *L = (LinkList) malloc(sizeof(Node));
//    if (!(*L))
//        return ERROR;
//    (*L)->next = NULL;
//
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//Status ListEmpty(LinkList L) {
//    if (L->next)
//        return FALSE;
//    else
//        return TRUE;
//}
//
///*
// * �����������ɾ�� ˼·:
// * 1���������p��q��
// * 2������һ����㸳ֵ��p��
// * 3��LOOP
// *      ����һ����㸳ֵ��q��
// *      �ͷ�p��
// *      ��q��ֵ��p��
// */
//Status ClearList(LinkList *L) {
//    LinkList p, q;
//    p = (*L)->next;
//    while (p) {
//        q = p->next;
//        free(p);
//        p = q;
//    }
//    (*L)->next = NULL;
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//int ListLength(LinkList L) {
//    int i = 0;
//    LinkList p = L->next;/*ָ��ͷ���*/
//    while (p) {
//        i++;
//        p = p->next;
//    }
//    return i;
//}
//
///*
// * ��ȡ��i��������Ԫ��  ˼·��
// * 1������һ�����pָ�������һ����㣬��ʼ��j��1��ʼ
// * 2����j<iʱ���ͱ���������p��ָ�벻������ƣ�����ָ����һ����㣬j�ۼ�1
// * 3����j���������β����˵����i��Ԫ�ز����ڣ�����ERROR
// * 4�������ҳɹ������ؽ��p������
// */
///* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
///* �����������e����L�е�i������Ԫ�ص�ֵ */
//Status GetElem(LinkList list, int i, ElemType *e) {//�˴�list����Ҫ�޸ģ�������һ��ָ����ʽ����
//    int j = 1;//��ǵ�ǰָ��λ��
//    LinkList p = list->next;//��ÿ��ƶ�ָ�룬����ԭͷָ��λ��
//    while (p && j < i) {//�����ǰ�����ڣ�������δ����iλ��
//        p = p->next;
//        j++;
//    }
//    if (!p || j > i)//���p��㲻���ڣ�����i�����ֵС��1
//        return ERROR;
//    *e = p->data;/*��������ݷ���*/
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
///* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
//int LocateElem(LinkList L,ElemType e){
//    int i=0;
//    LinkList p=L->next;
//    while(p){
//        i++;
//        if (p->data==e)
//            return i;
//        p=p->next;
//    }
//    return 0;
//}
//
///*
// * �������i�����ݲ����� ˼·��
// * 1������һ�����pָ��������ʼ��j��1��ʼ��
// * 2����j<iʱ���ͱ���������p��ָ������ƶ�������ָ����һ����㣬j�ۼ�1��
// * 3����������ĩβpΪnull��˵����i��Ԫ�ز����ڣ�
// * 4������˵�����ҳɹ�����ϵͳ������һ���սڵ�s��
// * 5��������Ԫ��e��ֵ��s->data��
// * 6��������Ĳ����׼���s->next=p->next; p->next=s;
// * 7�����سɹ���
// */
///* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
///* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
//Status ListInsert(LinkList *L, int i, ElemType e) {//���ڴ˴���Ҫ�޸�ԭ��������ݣ�ʹ�ö���ָ�봫�룻һ��ͬ��
//    int j = 1;
//    LinkList p = *L;//�����ǵ�i�����λ�ò��룬����Ҫͣ��i-1���λ��
//    LinkList s;
//    while (p && j < i) {
//        p = p->next;
//        j++;
//    }
//    if (!p || j > i)/*���p��㲻����,����i�����ֵС��1*/
//        return ERROR;
//    s = (LinkList) malloc(sizeof(Node));//����ע�⣺Node���ǽṹ�����ͣ�С������ΪLinkList��ָ�����ͣ�Ĭ�ϰ�λ��
//    s->data = e;
//    s->next = p->next;  /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
//    p->next = s;    /* ��s��ֵ��p�ĺ�� */
//    return OK;
//}
//
///*
// * ������ɾ����i����� ˼·��
// * 1������һ�����pָ��������ʼ��j��1��ʼ(��ΪҪ�����ɾ������ǰ�����)��
// * 2����j<iʱ���ͱ���������p��ָ������ƶ�������ָ����һ����㣬j�ۼ�1��
// * 3����������ĩβpΪ�գ���˵����i��Ԫ�ز����ڣ�
// * 4��������ҳɹ�����p->next�ĵ�ַ������q�У��Ա����ֳ�����ֹp->����޷����ʵĽ��ȴ�޷����գ�
// * 5���������ɾ��ָ�p->next=q->next��
// * 6����q�е����ݸ�ֵ��e����Ϊ����ֵ��
// * 7���ͷ�q��㣻
// * 8�����سɹ���
// */
//Status ListDelete(LinkList *L, int i, ElemType *e) {
//    int j = 1;
//    LinkList p, q;//�˴�����typedef�����LinkList������p,q��Ϊָ������
//    p = *L;
//    while (p && j < i) {//����Ѱ�ҵ�i�����
//        p = p->next;
//        j++;
//    }
//    if (!(p->next) || j > i)/*���p��㲻���ڣ�����i�����ֵС��1*/
//        return ERROR;
//    q = p->next;
//    p->next = q->next;//��q�ĺ�̸�ֵ��p�ĺ��
//    *e = q->data;//����q������ݣ�����Ϊ���Է�ִ��ʧ�ܣ�֧�ֻع�����
//    free(q);//������������
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* ������������ζ�L��ÿ������Ԫ����� */
//Status ListTraverse(LinkList L){
//    LinkList p=L->next;
//    while(p){
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return OK;
//}
//
///*
// * ������������ ˼·1��ͷ�巨
// * 1������һ�����p�ͼ���������i��
// * 2����ʼ���Կ�����L��
// * 3����L��ͷ����ָ��ָ��NULL��������һ����ͷ���ĵ�����
// * 4��LOOP:
// *      ����һ���½�㸳ֵ��p��
// *      �������һ�����ָ�ֵ��p��������p->data;
// *      ��p���뵽ͷ�����ǰһ�½��֮��
// */
//void CreateListHead(LinkList *L, int n) {
//    LinkList p;
//    srand((unsigned int) time(0));
//    *L = (LinkList) malloc(sizeof(Node));//LΪ����ָ�룬*p���Ի�ȡLinkList��ͷָ��
//    (*L)->next = NULL;//��ͷָ��ĺ��ָ��NULL���Է��ڴ����
//    for (int i = 0; i < n; ++i) {
//        p = (LinkList) malloc(sizeof(Node));
//        p->data = rand() % 100 + 1;
//        p->next = (*L)->next;
//        (*L)->next = p;//���뵽��ͷ
//    }
//}
//
///*
// * ������������ ˼·2��β�巨
// * �����ͷ�巨��β�巨��Ҫ����ͷָ�룻��ʹ��һ����ʱָ��r���ƶ�������
// */
//void CreateListTail(LinkList *L, int n) {
//    LinkList p, r;
//    srand((unsigned int) time(0));
//    *L = (LinkList) malloc(sizeof(Node));
//    r = *L;
//    for (int i = 0; i < n; ++i) {
//        p = (LinkList) malloc(sizeof(Node));
//        p->data = rand() % 100 + 1;
//        r->next = p;
//        r = p;
//    }
//    r->next = NULL;
//}
//
//
//int main() {
//    LinkList L;
//    ElemType e;
//    Status i;
//    int j, k;
//    i = InitList(&L);
//    printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
//    for (j = 1; j <= 5; j++)
//        i = ListInsert(&L, 1, j);
//    printf("��L�ı�ͷ���β���1��5��L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//    i = ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    i = ClearList(&L);
//    printf("���L��ListLength(L)=%d\n", ListLength(L));
//    i = ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    for (j = 1; j <= 10; j++)
//        ListInsert(&L, j, j);
//    printf("��L�ı�β���β���1��10��L.data=");
//    ListTraverse(L);
//
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    ListInsert(&L, 1, 0);
//    printf("��L�ı�ͷ����0��L.data=");
//    ListTraverse(L);
//    printf("ListLength(L)=%d \n", ListLength(L));
//
//    GetElem(L, 5, &e);
//    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
//    for (j = 3; j <= 4; j++) {
//        k = LocateElem(L, j);
//        if (k)
//            printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
//        else
//            printf("û��ֵΪ%d��Ԫ��\n", j);
//    }
//
//
//    k = ListLength(L); /* kΪ�� */
//    for (j = k + 1; j >= k; j--) {
//        i = ListDelete(&L, j, &e); /* ɾ����j������ */
//        if (i == ERROR)
//            printf("ɾ����%d������ʧ��\n", j);
//        else
//            printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//    }
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    j = 5;
//    ListDelete(&L, j, &e); /* ɾ����5������ */
//    printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\n���L��ListLength(L)=%d\n", ListLength(L));
//    CreateListHead(&L, 20);
//    printf("���崴��L��Ԫ��(ͷ�巨)��");
//    ListTraverse(L);
//
//    i = ClearList(&L);
//    printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
//    CreateListTail(&L, 20);
//    printf("���崴��L��Ԫ��(β�巨)��");
//    ListTraverse(L);
//
//
//    return 0;
//}
