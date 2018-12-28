#include <stdio.h>
#include <stdlib.h>

typedef struct linknode{
	int val;
	struct linknode *next; //疑問 :為何 "struct linknode *next = NULL;" 並沒使任何一個 NEXT為 NULL? 
}node;


node* get_new_node(void){
	node *newnode = (node*)malloc(sizeof(node));
	if(newnode == NULL){
		printf("OOM (out of memory)\n");
	}
	newnode->next = NULL;
	return newnode;
}

node *head = NULL;


node* insertnode(node *tailnode,int value){
	node *newnode = get_new_node();
	
	if(head == NULL){
		head = newnode;
		newnode->val = value;
	}
	else{
		newnode->val = value;
		tailnode->next = newnode;
	}

	return newnode; //新的tailnode 
}

//顯示節點 
void shownode(void){
	node *current = head; 
	current = head;
	while(current != NULL){
		printf("*********\n");
		printf("*       *\n*   %d   *\n*       *\n",current->val);
		printf("*********\n\n");
	
		current = current->next; 
	}	
}


node* get_tail(void){ 					 
	node *searcher = head->next;
	
	while(searcher->next != NULL){
		searcher = searcher->next;
	}
	printf("\n%d",searcher->val);
	return searcher;
}


int main(void){
	int data;
	printf("Please input linked list value and input 0 to stop: \n");
	scanf("%d", &data);
	node *tail = head;
	while(data != 0){
		tail = insertnode(tail,data);
		scanf("%d",&data);
	}
	printf("\n\nThe Linked-List： \n\n");
	shownode();
	printf("head value = %d\ntail value = %d\n",head->val,tail->val);

	system("Pause");
	return 0;
}
