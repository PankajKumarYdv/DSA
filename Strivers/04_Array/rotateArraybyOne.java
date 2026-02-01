// Rotate array by one
public class rotateArraybyOne{
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5}; 
        for(int i = (arr.length-1); i > 0; i--){
            arr[i-1] = arr[i-1] ^ arr[i]; 
            arr[i] = arr[i-1] ^ arr[i]; 
            arr[i-1] = arr[i-1] ^ arr[i]; 
        }

        // all data 
        
        for(int element : arr ){
            System.out.print(element); 
        }
    }
}