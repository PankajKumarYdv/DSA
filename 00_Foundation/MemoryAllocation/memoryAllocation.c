#include <stdio.h> 
#include <stdlib.h> 

/*
 malloc() -> return address| Store garbage values | 
 calloc()  -> | Store 0 |
 realloc()
 free() 
*/

int main(){
    printf("Memory Allocation Method "); 

    int n; 
    printf("\nEnter size : "); 
    scanf("%d", &n); 

    // Memory allocation 
    // sntx :  ptr = (type*) malloc(size_in_bytes); 
    /*
        Malloc 
        malloc(5); Only 5 byte allocate krega. 
        malloc(5*sizeof(int)); toh 5*4(int size 4 bytes) = 20

        // Size 
        int -> 4 bytes 
        float -> 4 bytes
        double -> 8 bytes 
        char -> 1 bytes 
    */

    int *ptr = (int*) malloc(n*sizeof(int));  

    printf("\n size of created memory : %d", sizeof(*ptr)); 


    // Storing value in that memory 
    for(int i = 0; i < n; i++){
        ptr[i] = i+1; 
    }

    for(int i = 0; i < n; i++){
        printf("\n%d", ptr[i]);
    }

    // Free memory
    free(ptr); 
    ptr = NULL; 

}