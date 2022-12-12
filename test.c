#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int cnt = 0;
int total[100], aver[100];

typedef struct {
   char name[10];
    int kor, eng, math;
    double aver, total;
}element;

typedef struct Node{
   element data;
   struct Node* next;
}Node;

Node* insert(Node* head){
   Node* node = (Node *)malloc(sizeof(Node));
    int sub;
    char name[10];

    printf("학생 이름: \n");
    scanf("%s", &name);
    strcpy(node->data.name, name);

    printf("국어: \n");
    scanf("%d", &sub);
    node->data.kor = sub;
    printf("영어: \n");
    scanf("%d", &sub);
    node->data.eng = sub;
    printf("수학: \n");
    scanf("%d", &sub);
    node->data.math = sub;

    node->data.total += node->data.eng + node->data.kor + node->data.math;
    total[cnt] = node->data.total;
    node->data.aver += node->data.total/3;
    aver[cnt] = node->data.aver;
    cnt++;

   node->next = head;
   head = node;

   return head;
}

void print_list(Node* head){
   for (Node* p = head; p != NULL; p = p->next){
        printf("학생 : %s\n", p->data.name);
        printf("국어 : %d 영어 : %d 수학 : %d\n", p->data.kor, p->data.eng, p->data.math);
   }
}

int partition(int list[], int left,int right)
{
    int pivot,temp,low,high;
    low = left;
    high= right+1;
    pivot=list[left];
    do
    {
        do
        {
            low++;
        }while(list[low]<pivot && low<=right);
        do
        {
            high--;
        }while(list[high]>pivot);

        if(low<high)
        {
            swap(list[low],list[high],temp);
        }
    }while(low<high);
    swap(list[left],list[high],temp);
    return high;
}

void quicksort(int list[], int left,int right)
{
    if(left<right)
    {
        int q=partition(list, left, right);
        quicksort(list,left,q-1);
        quicksort(list,q+1,right);
    }
}


 void total_jung(Node* head){

    quicksort(total,0,cnt);

    for(int i = cnt; i>=1; i--){
        printf("%d:", cnt-i);
        for(Node* p = head; p != NULL; p = p->next){
            if(p->data.total == total[i]) printf("%s \t", p->data.name);
        }
        printf("총점 : %d \n", total[i]);
    }
}

 void aver_jung(Node* head){

    quicksort(aver,0,cnt);

    for(int i = cnt; i>=1; i--){
        printf("%d:", cnt-i);
        for(Node* p = head; p != NULL; p = p->next){
            if(p->data.aver == aver[i]) printf("%s \t", p->data.name);
        }
        printf("평균 : %d \n", aver[i]);

    }
}

int main(){

    Node *head  = NULL;
    element data;
    int sw=100;
    while(sw != 0){
        printf("1: 학생 정보 입력 2:학생 정보 출력 3:성적 총점 순위 4:성적 평균 순위 0:종료\n");
        scanf("%d", &sw);
        if(sw == 1) head = insert(head);
        else if(sw == 2) print_list(head);
        else if(sw == 3) total_jung(head);
        else if(sw == 4) aver_jung(head);
        else break;
    }
}