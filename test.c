#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node* next;
}Node;

Node* insertFirst(Node* head, element data){
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = head;
	head = node;
	return head;
}
Node* deleteFirst(Node* head){
	if (head == NULL) return NULL;
	Node* removed = head;
	Node* newhead = head -> next;
	free(removed);
	removed = NULL;
   return newhead;
}
void printList(Node* head){
	Node* p = head;
	while(p!=NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
int main(){
	Node* head = NULL;
	for(int i = 0; i<5; i++){
		head = insertFirst(head, i);
		printList(head);
	}
	for(int i = 0; i<5; i++){
		head = deleteFirst(head);
		printList(head);
	}
	return 0;
}