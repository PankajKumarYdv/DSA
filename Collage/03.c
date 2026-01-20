#include <stdio.h>
int main(){
    //variable
	int lenOfArray = 0;

	// Getting
	printf("Enter length of array : ");
	scanf("%d",&lenOfArray);

    // array pointer
    int lp = 0;
	int ep = lenOfArray-1;

	// Inserting element in array
	int arr[lenOfArray];
	printf("Enter elements : \n");
	for(int i = 0; i < lenOfArray; i++){
		printf("%dth ==> ",i);
		scanf("%d",&arr[i]);
	}

	//logic
    while(lp < ep){
        arr[lp] = arr[lp] ^ arr[ep];
        arr[ep] = arr[lp] ^ arr[ep];
        arr[lp] = arr[lp] ^ arr[ep];

        // increment
        lp++;
        ep--;
    }

    // swaped array;
    for(int i = 0; i < lenOfArray; i++){
        printf("%d ",arr[i]);
    }

}
