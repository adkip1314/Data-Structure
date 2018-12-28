#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int value;
	struct N *next;
}node;

node *top = NULL;


void push(int val){
	node *newnode = (node*)malloc(sizeof(node));
	
	newnode->value = val;
	newnode->next = top;
	
	top = newnode;
	
	printf("push %d on the stack\n",val); 
	
	return;
}

int pop(void){
	if(top == NULL){
		printf("The top of the stack is NULL\n");
		return -1;
	}
	
	node *ToBeDeleted = top;
	int dval = top->value;
	
	top = top->next;
	
	free(ToBeDeleted);
	
	printf("delete %d\n",dval);
	
	return  dval;
}

void shownode(void){
	int u = 1 ;
	node* traveler = top;
	
	while(traveler != NULL){
		printf("%d.%d \n",u++,traveler->value);
		traveler = traveler->next; 
	}
	
	return;
}

void expectnode(void){
	int u = 0 ;
	node* traveler = top;
	
	while(traveler != NULL){
		u++;
		traveler = traveler->next; 
	}
	
	printf("stack plate = %d\n",u);
	
	return;
}

void isempty(void){
	if(top == NULL){
		printf("stack is empty, shit,you need input the fucking num\n");
	}
	else{
		printf("stack have some shit\n");
	}
	return;
}

void insertnode(void){
	
}
int main(void){
	int i,j;
	printf("please input operation number (9 for help; 0 for end)\n");
	scanf("%d", &i);
	while(1){
		switch(i){
			case 0:
				break;
			case 1:
				printf("input a number into stack: ");
				scanf("%d",&j);
				push(j);
				break;
			case 2:
				printf("pop the top \n");
				pop();
				break;
			case 3:
				printf("show stack \n");
				shownode();
				break;
			case 4:
				printf("is the stack empty? \n");
				isempty();
				break;
			case 5:
				printf("count the stack plate. \n");
				expectnode();
				break;
			case 9:
				printf("To push is number 1\nTo pop is number 2\nTo show stack is number 3\nTo exmine stack empty is number 4\nTo count the plates of stack is number 5 \n");
				break;
			default:
				printf("wrong input\n");
		}
		if(i == 0){
			break;
		}
		else{
			printf("\nplease input operation number (9 for help; 0 for end)\n");
			scanf("%d", &i);
		}
				
	}
	return 0;	
} 
