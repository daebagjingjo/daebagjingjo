#include<stdio.h>
#include<stdlib.h>

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

int main(){

    Node *head  = NULL;
    element data;
    for(int i = 0; i<5; i++){
		head = insert(head);
	}
    print_list(head);

    printf("평균 : %.21f\n", avg);
    printf("총점 : %d\n", sum);

}
