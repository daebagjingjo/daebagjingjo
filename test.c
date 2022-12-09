#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char name[10];
	int score;
}element;

typedef struct Node{
	element data;
	struct Node* next;
}Node;

Node* insert(Node* head){
	Node* node = (Node *)malloc(sizeof(Node));
	fgets(node->data.name, 100, stdin);
	node->next = head;
	head = node;
	return head;
}

void print_list(Node* head){
	for (Node* p = head; p != NULL; p = p->next){
		if(p->next == NULL){
            printf("%s", p->data.name);
		}else{
            printf("%s->", p->data.name);
		}
	}
	printf("\n");
}

int main(){

    Node *head  = NULL;
    element data;
    for(int i = 0; i<5; i++){
		head = insert(head);
	}
    print_list(head);

}