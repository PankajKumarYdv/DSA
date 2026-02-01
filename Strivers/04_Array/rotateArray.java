public class rotateArray{
    /*  // Brute force approach 
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5}; 
        int d = 2; 

        // logic 
        for(int i = 1; i <= d; i++){
            for(int j = 0; j < (arr.length-1); j++){
                arr[j+1] = arr[j+1] ^ arr[j]; 
                arr[j] = arr[j+1] ^ arr[j]; 
                arr[j+1] = arr[j+1] ^ arr[j];
            }
        }
        

        // array 
        for(int ele : arr){
            System.out.print(ele); 
        }
    }*/


   // Optimal 
   public static void main(String[] args){
    int[] arr = {1,2,3,4,5}; 
    int d = 2; 
    
    // logic 
    reverse(arr,0,d-1); 
    reverse(arr,d,arr.length-1); 
    reverse(arr,0,arr.length-1); 

    // printing 
    for(int ele : arr){
        System.out.print(ele); 
    }
   }

   // reverse
   public static void reverse(int[] arr,int l,int r){
    while(l<=r){
        if(l==r) break; 
        arr[l] = arr[l] ^ arr[r]; 
        arr[r] = arr[l] ^ arr[r]; 
        arr[l] = arr[l] ^ arr[r]; 
        l++; 
        r--; 
    }
   }

}