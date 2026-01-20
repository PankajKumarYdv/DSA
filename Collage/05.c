#include <stdio.h>
int main(){
	int lenOfArray = 0;

	// Getting
	printf("Enter length of array : ");
	scanf("%d",&lenOfArray)

	// Inserting element in array
	int arr[lenOfArray];
	printf("Enter elements : \n");
	for(int i = 0; i < lenOfArray; i++){
		printf("%dth ==> ",i);
		scanf("%d",&arr[i]);
	}

    int d = arr[1] - arr[0];
    for(int i = 0; i < lenOfArray; i++){
        if((arr[i] + d) == arr[i+1])
    }

}
