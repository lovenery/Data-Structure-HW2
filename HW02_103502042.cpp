
#include <iostream>  //C++ IO
#include <cstdio>    //C   IO
#include <stdlib.h>

using namespace std;

//�ŧi��k: listNode *test === listPointer test
//�ϥΤ�k: ���c���ЦW��->���c�ܼƦ��� , test->value,next
typedef struct listNode *listPointer; //�Nstruct listNode�w�q�s���A���� = listPointer
typedef struct listNode{ //struct listNode�w�q�s���A
    int value;
    listPointer next;
};
void printall(listNode *p); // �L�X linklist ���Ҧ����e
listPointer addlistNode(listNode *p,int n); // �[�J�@�Ӹ`�I ���K�@Sorting �æ^��Update�᪺�Ĥ@��List node������
listPointer reverselist(listNode *p); // ����list �æ^�Ǥ���᪺�Ĥ@��List node������
listPointer combinelist(listNode *p1,listNode *p2); // ���X���List ���K�@���W�Ƨ�

int main() {

    //print list 1
    cout<<"List1:";
    int a[10]={0,9,8,8,6,3,2,1,5,4};
    listPointer start1=NULL;
    for(int i=0;i<10;i++){
        start1=addlistNode(start1,a[i]);
    }
    printall(start1);

    //����A����^��
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

    //���X
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

    //�W�[�@��node
    listPointer head; //�s�y�@�ӫ���
    head=(listPointer)malloc(sizeof(listNode)); //���L�@�ӪŶ�
    head->value=n; //���L���
    head->next=p; //���L���V��}
    p=head;  //return Start1(�}�Yhead)

    //bubble sort
    listPointer ptr1; //�s�y�@�ӫ���
    ptr1=(listPointer)malloc(sizeof(listNode)); //���L�@�ӪŶ�
    listPointer ptr2; //�s�y�@�ӫ���
    ptr2=(listPointer)malloc(sizeof(listNode)); //���L�@�ӪŶ�
    int temp; //�Ȧs��
    for(ptr1=p;ptr1!=NULL;ptr1=ptr1->next){
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
            if(ptr1->value > ptr2->value){
                    temp=ptr1->value;
                    ptr1->value=ptr2->value;
                    ptr2->value=temp;
            }
        }
    }

    //sort���^��head
    return p;
}
listPointer reverselist(listNode *p){
    listPointer prev=NULL; //�W�@��node,�̫���Vhead,�@�}�l������NULL
    listPointer current=p; //�ثe���V��node,�̫���VNULL
    listPointer next; //�U�@�ӭn�B�z��node,�̫���VNULL

    while(current!=NULL){
        next=current->next; //��next���U�@�ӭn�B�z��node
        current->next=prev; //���Ф�����V�e�@��

        prev=current; //�B�z�U�@���j��
        current=next; //�B�z�U�@���j��
    }
    return prev; //return head

}
listPointer combinelist(listNode *p1,listNode *p2){
    listPointer result=NULL;

    //�Np1�Ҧ���ƥ[�Jresult�ñƧ�
    while(p1!=NULL){
        result=addlistNode(result,p1->value);
        p1=p1->next;
    }

    //�Np2�Ҧ���ƥ[�Jresult�ñƧ�
    while(p2!=NULL){
        result=addlistNode(result,p2->value);
        p2=p2->next;
    }

    return result; //return head
}
