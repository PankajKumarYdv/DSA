#include <stdio.h>
#include <math.h>
#define POST_INF  INFINITY
#define NEG_INF -INFINITY

int main(){
    int smallest = POST_INF;
    int secondSmallest = POST_INF;

    int biggest = NEG_INF;
    int secondBiggest = NEG_INF;

    // Getting array ;
    int arr[] = {1,2,4,7,7,5};
    int lenOfArray = sizeof(arr) / sizeof(arr[0]); // 6


    // logic
    for(int i = 0; i < lenOfArray; i++){
        // smallest
        if(arr[i] < secondSmallest && arr[i] != secondSmallest && arr[i] != smallest){
            if(arr[i] < smallest){
                secondSmallest = smallest;
                smallest = arr[i];
            }else{
                secondSmallest = arr[i];
            }
        }



        // biggest
        if(arr[i] > secondBiggest && arr[i] != biggest && arr[i] != secondBiggest){
            if(arr[i] > biggest){
                secondBiggest = biggest;
                biggest = arr[i];
            }else{
                secondBiggest = arr[i];
            }
        }
    }

    // result

    printf("Biggets Element : %d \nSecond biggest element : %d\n", biggest, secondBiggest);
    printf("Smallest Element : %d \nSecond smallest element : %d", smallest, secondSmallest);

}
