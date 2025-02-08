#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node* next;
  int data;
};

struct Node* createNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void push(struct Node **top, int data){
  struct Node* newNode = createNode(data);
  newNode->next = *top;
  *top = newNode;
}

int pop(struct Node **top){
  if(*top == NULL){
    printf("Stack Underflow!!");
    return -1;
  }
  struct Node* temp = *top;
  int popped = (*top)->data;
  *top = (*top)->next;
  free(temp);
  return popped;
}

void display(struct Node *top){
  struct Node* temp = top;
  while(temp != NULL){ 
    printf("\n%d",temp->data);
    temp = temp->next;
  }
}

void moveElement(struct Node** src, struct Node** dest){
  if(*src == NULL){
    printf("Invalid move: Source stack is empty.\n");
    return;
  }

  if(*dest == NULL || (*src)->data < (*dest)->data){
    int popped = pop(src);
    push(dest, popped);
    printf("Element moved successfully.\n");
  } else{
    printf("Element moving unsuccessful!!.\n");
  }
}   
  
int main(){
  printf("********TOWER OF HANOI********\n");
  int n, stk_choice;
  struct Node *A = NULL;
  struct Node *B = NULL;
  struct Node *C = NULL;
  
  printf("Enter the number of Elements:\n");
  scanf("%d", &n);
 
  for(int i=n; i>=1; i--){
    push(&A, i);
  }

  while(1){

    printf("\nCurrent Stacks:\n");
    printf("\nStack A: ");
    display(A);
    printf("\nStack B: ");
    display(B);
    printf("\nStack C: ");
    display(C);

    printf("\nChoose a move:\n");
    printf("Enter source stack\n1.A\n2.B\n3.C\n");
    int srcStack, destStack;
    scanf("%d", &srcStack);
    printf("Enter destination stack\n1.A\n2.B\n3.C\n");
    scanf("%d", &destStack);
    switch(srcStack){
      case 1: 
      if(destStack == 2)
        moveElement(&A, &B);
      else if(destStack == 3)
        moveElement(&A, &C);
      else
        printf("Invalid move selection.\n");
      break;

      case 2: 
      if(destStack == 1)
        moveElement(&B, &A);
      else if(destStack == 3)
        moveElement(&B, &C);
      else
        printf("Invalid move selection.\n");
      break;

      case 3: 
      if(destStack == 1)
        moveElement(&C, &A);
      else if(destStack == 2)
        moveElement(&C, &B);
      else
        printf("Invalid move selection.\n");
      break;  

      default: printf("Invalid source stack input!!");
    }

    if(A==NULL && B==NULL && C != NULL){
      printf("*********************\n");
      printf("****** YOU WON ******\n");
      printf("*********************\n");
      break;
    }
  }
  
  return 0;
}
