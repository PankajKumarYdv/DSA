import java.util.*; 
public class sort012{
    // main function 
    public static void main(String[] args){
        int[] arr = {2}; 

        for (int ele : arr){
            System.out.print("Entered array : " + ele + " "); 
        }
        System.out.print("\n"); 

        // Logic 
        // sort012MyApproach(arr);
        sort012Optimal(arr); 


        // Result 
        for(int ele : arr){
            System.out.print("Sorted Array : " + ele + " "); 
        }
    }

    // My approach
    public static void sort012MyApproach(int[] arr){
        int zeroCount = 0; 
        int oneCount = 0; 
        int twoCount = 0; 
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == 0) zeroCount++; 
            else if (arr[i] == 1) oneCount++; 
            else twoCount++; 
        }

        for(int i = 0;  i < arr.length; i++){
            if(zeroCount != 0){
                arr[i] = 0; 
                zeroCount--; 
            }else if (oneCount != 0){
                arr[i] = 1; 
                oneCount--; 
            }else{
                arr[i] = 2; 
            }
        }
    }


   // sort 0,1,2 -> Optimal (Dutch National Flag Algorithm)
   public static void sort012Optimal(int[] arr){
    int low = 0, mid = 0;
        int high = arr.length - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                mid++;
            } 
            else { 
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
   }
}