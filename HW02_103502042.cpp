
#include <iostream>  //C++ IO
#include <cstdio>    //C   IO
#include <stdlib.h>

using namespace std;

//宣告方法: listNode *test === listPointer test
//使用方法: 結構指標名稱->結構變數成員 , test->value,next
typedef struct listNode *listPointer; //將struct listNode定義新型態指標 = listPointer
typedef struct listNode{ //struct listNode定義新型態
    int value;
    listPointer next;
};
void printall(listNode *p); // 印出 linklist 的所有內容
listPointer addlistNode(listNode *p,int n); // 加入一個節點 順便作Sorting 並回傳Update後的第一個List node的指標
listPointer reverselist(listNode *p); // 反轉list 並回傳反轉後的第一個List node的指標
listPointer combinelist(listNode *p1,listNode *p2); // 結合兩個List 順便作遞增排序

int main() {

    //print list 1
    cout<<"List1:";
    int a[10]={0,9,8,8,6,3,2,1,5,4};
    listPointer start1=NULL;
    for(int i=0;i<10;i++){
        start1=addlistNode(start1,a[i]);
    }
    printall(start1);

    //反轉再反轉回來
    cout<<"Reverse list1:";
    start1=reverselist(start1);
    printall(start1);
    cout<<"Reverse again:";
    start1=reverselist(start1);
    printall(start1);

    //print list 2
    cout<<"List2:";
    int b[10]={3,7,0,4,6,9,1,2,5,7};
    listPointer start2=NULL;
    for(int i=0;i<10;i++){
        start2=addlistNode(start2,b[i]);
    }
    printall(start2);

    //結合
    cout<<"After combining:";
    listPointer result=NULL;
    result=combinelist(start1,start2);
    printall(result);

    return 0;
}

void printall(listNode *p){
    for(int i=0;p!=NULL;i++){
        cout<<p->value<<" ";
        p = p->next;
    }
    cout<<endl;
}
listPointer addlistNode(listNode *p,int n){

    //增加一個node
    listPointer head; //製造一個指標
    head=(listPointer)malloc(sizeof(listNode)); //給他一個空間
    head->value=n; //給他資料
    head->next=p; //給他指向位址
    p=head;  //return Start1(開頭head)

    //bubble sort
    listPointer ptr1; //製造一個指標
    ptr1=(listPointer)malloc(sizeof(listNode)); //給他一個空間
    listPointer ptr2; //製造一個指標
    ptr2=(listPointer)malloc(sizeof(listNode)); //給他一個空間
    int temp; //暫存值
    for(ptr1=p;ptr1!=NULL;ptr1=ptr1->next){
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
            if(ptr1->value > ptr2->value){
                    temp=ptr1->value;
                    ptr1->value=ptr2->value;
                    ptr2->value=temp;
            }
        }
    }

    //sort完回傳head
    return p;
}
listPointer reverselist(listNode *p){
    listPointer prev=NULL; //上一個node,最後指向head,一開始必須為NULL
    listPointer current=p; //目前指向的node,最後指向NULL
    listPointer next; //下一個要處理的node,最後指向NULL

    while(current!=NULL){
        next=current->next; //讓next為下一個要處理的node
        current->next=prev; //指標反轉指向前一個

        prev=current; //處理下一次迴圈
        current=next; //處理下一次迴圈
    }
    return prev; //return head

}
listPointer combinelist(listNode *p1,listNode *p2){
    listPointer result=NULL;

    //將p1所有資料加入result並排序
    while(p1!=NULL){
        result=addlistNode(result,p1->value);
        p1=p1->next;
    }

    //將p2所有資料加入result並排序
    while(p2!=NULL){
        result=addlistNode(result,p2->value);
        p2=p2->next;
    }

    return result; //return head
}
