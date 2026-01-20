#include <stdio.h>
int main(){
	int lenOfArray = 0;
	// getting
	printf("Enter length of array : ");
	scanf("%d",&lenOfArray);

	// array
	int arr[lenOfArray];
    int pos[lenOfArray];
    int neg[lenOfArray];

    // array pointer
    int posp = 0, negp = 0;

	// inserting element in array
	printf("Enter elements : \n");
	for(int i = 0; i < lenOfArray; i++){
		printf("%dth ==> ",i);
		scanf("%d",&arr[i]);
	}


	// logic
	for(int i = 0; i < lenOfArray; i++){
        if(arr[i] > 0) {
            pos[posp] = arr[i];
            posp++;
        }else if (arr[i] < 0){
            neg[negp] = arr[i];
            negp++;
        }else {
            continue;
        }
	}

	// printing data;
	printf("\nPositive number : ");
    for(int i = 0; i < posp; i++){
        printf("%d ", pos[i]);
    }

    printf("\nNegative number : ");
    for(int i = 0; i < negp; i++){
        printf("%d ", neg[i]);
    }

    printf("\nzero number : ");
    for(int i = 0; i < lenOfArray - (posp+negp); i++){
        printf("0 ");
    }
}
