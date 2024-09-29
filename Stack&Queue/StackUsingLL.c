#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;

};
struct Node * createNode(int data){
    struct Node * newNode = (struct Node * )malloc (sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed \n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct Node* push( struct Node * top, int data){
    struct Node * newNode= createNode(data);
    newNode->next=top;
    return newNode;

}
struct Node * pop(struct Node* top){
    if(top==NULL){
        printf("Stack is empty!! Cannot Pop \n ");
        return NULL;
    }
    struct Node* temp = top;
    top= top->next;
    free(temp);
    return top;

}
void display(struct Node* top){
    if (top==NULL){
        printf("Stack is empty!! \n ");
        return;
    }
    printf("STACK : ");
    struct Node* current= top;
    while (current!=NULL)
    {
        printf("%d  " , current->data);
        current=current->next;

    }
}
int main(){
    struct Node* top=NULL;
    int choice , data;
    printf(" HARSHITA SINGH \n Roll no. 58 ");
    while (1)
    {
        printf(" \n  STACK MENU : \n  1. Push \n  2. Pop \n  3. Display \n  4. Quit \n");
        printf("Enter your Choice: ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push : ");
            scanf("%d", &data);
            top= push (top,data);
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            while (top!=NULL)
            {
                struct Node * temp= top;
                top= top->next;
                free(temp);
            }
            exit(0);
            break;

        default:
        printf("INVALID CHOICE! \n Please try again ");
            break;
        }
    }
    return 0;
}