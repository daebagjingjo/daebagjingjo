#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int cnt = 0;
int total[100], aver[100];

typedef struct {
	char name[10];
    int kor, eng, math;
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

    total[cnt] += node->data.eng + node->data.kor + node->data.math;
    aver[cnt] += total[cnt]/3;
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


 void total_jung(){
    quicksort(total,0,cnt);
    for(int i = 1; i<=cnt; i++){
        printf("총점 : %d ",total[i]);
    }
}

 void aver_jung(){
    quicksort(aver,0,cnt);
    for(int i = 1; i<=cnt; i++){
        printf("총점 : %d ",aver[i]);
    }
}


int main(){

    Node *head  = NULL;
    element data;
    for(int i = 0; i<6; i++){
		head = insert(head);
	}
	total_jung();
    aver_jung();
}
