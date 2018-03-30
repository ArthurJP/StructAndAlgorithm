////
//// Created by �ſ��� on 2017/11/16.
////
//
//#include <malloc.h>
//#include <stdio.h>
//
//#define HASHSIZE 12
//#define NEWKEY -32768
//
//typedef struct {
//    int *elem;
//    int count;
//} HashTable;
//
//int InitHashTable(HashTable *H) {
//    H->count = HASHSIZE;
//    H->elem = (int *) malloc(sizeof(int));
//    if (!H->elem) {/*��ʼ��ʧ��*/
//        return -1;
//    }
//    for (int i = 0; i < HASHSIZE; ++i) {
//        H->elem[i] = NEWKEY;
//    }
//    return 0;
//}
//
//int Hash(int key) {
//    return key % HASHSIZE;
//}
//
//void InsertHash(HashTable *H, int key) {
//    int addr = Hash(key);
//    while (H->elem[addr] != NEWKEY) {/*���ֳ�ͻ*/
//        addr = (addr + 1) % HASHSIZE;
//    }
//    H->elem[addr] = key;
//}
//
//int SearchHash(HashTable H, int key, int *addr) {
//    *addr = Hash(key);
//
//    while (H.elem[*addr] != key) {
//        *addr = (*addr + 1) % HASHSIZE;
//        if (H.elem[*addr]==NEWKEY ||  *addr==Hash(key)){
//            return -1;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    int arr[HASHSIZE]={12,67,56,16,25,37,22,29,15,47,48,34};
//    int i,p,key,result;
//    HashTable H;
//
//    key=39;
//
//    InitHashTable(&H);
//    for(i=0;i<HASHSIZE;i++)
//        InsertHash(&H,arr[i]);
//
//    result=SearchHash(H,key,&p);
//    if (result)
//        printf("���� %d �ĵ�ַΪ��%d \n",key,p);
//    else
//        printf("���� %d ʧ�ܡ�\n",key);
//    printf("----------------\n");
//
//    for(i=0;i<HASHSIZE;i++)
//    {
//        key=arr[i];
//        result=SearchHash(H,key,&p);
//        if (result)
//            printf("���� %d �ĵ�ַΪ��%d \n",key,p);
//        else
//            printf("���� %d ʧ�ܡ�\n",key);
//    }
//
//    return 0;
//}
