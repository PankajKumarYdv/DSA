#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// #define TOP -1
#define MAX 5

int push(int arr[], int TOP){
    if(TOP == MAX){
        printf("\nStack is Overflow\n");
        getch();
        return TOP;
    }else{
        TOP++;
        printf("\nEnter %d Element : ",TOP);
        scanf("%d",&arr[TOP]);
        return TOP;
    }
}

// POP
int pop(int arr[], int TOP){
    if(TOP == -1){
        printf("Stack is Empty. \nCan't POP\n");
        getch();
        return TOP;
    }else{
        printf("\n %d is POPED", arr[TOP]);
        TOP--;
        return TOP;
    }
}

// PEEK
void peek(int arr[], int TOP){
    if(TOP == -1){
        printf("\nStack is Empty\n");
        getch();
    }else{
        printf("PEEK ELEMENT : %d", arr[TOP]);
    }
}

// display
void display(int arr[], int TOP){
    if(TOP == -1){
        printf("\nStack is Empty\n");
        getch();
    }else{
        for(int i = 0; i <= TOP; i++){
            printf("%d ", arr[i]);
        }
    }
}

void main(){
    int stack[MAX];
    int TOP = -1;
    int choice;
    while(1){
    system("cls");
    printf("\nEnter Your Choice : \n1. PUSH \n2. POP \n3. PEEK \n4. DISPLAY \n5. EXIT \n==> ");
    scanf("%d",&choice);
    // switch
        switch(choice){
        case 1:
            printf("\nPUSH OPERATION\n");
            TOP = push(stack, TOP);
            break;
        case 2:
            printf("\nPOP OPERATION\n");
            TOP = pop(stack, TOP);
            getch();
            break;
        case 3:
            printf("\nPEEK OPERATION\n");
            peek(stack, TOP);
            getch();
            break;
        case 4:
            printf("\nDISPLAY OPERATION\n");
            display(stack, TOP);
            getch();
            break;
        case 5:
            printf("\nEXIT.....");
            exit(0);
            break;
        default:
            printf("\nCHOOSE THE CORRECT OPTION\n");
            getch();
        }
    }

}
