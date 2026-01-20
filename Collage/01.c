#include <stdio.h>
int main(){
	int lenOfArray = 0, even = 0, odd = 0;
	printf("Enter length of array : ");
	scanf("%d",&lenOfArray);

	int arr[lenOfArray];
	printf("Enter elements : \n");
	for(int i = 0; i < lenOfArray; i++){
		printf("%dth ==> ",i);
		scanf("%d",&arr[i]);
	}

	for(int i = 0; i < lenOfArray; i++){
		if(arr[i] % 2 == 0) even++;
		else odd++;
	}

	// output
	printf("Result is : \n");
	printf("Even : %d \nOdd : %d ", even, odd);
	return 0;


}


