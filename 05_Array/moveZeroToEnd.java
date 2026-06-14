public class moveZeroToEnd{
    public static void main(String[] args){
        int[] arr = {1,0,2,3,2,0,0,4,5}; 
        int r = 0, l = 1; 
        for(int i = 0; i < arr.length-1; i++){
            if(arr[r] != 0){
                r++; 
                l++; 
            }else if(arr[r] == 0 && arr[l] != 0){
                arr[r] = arr[r] ^ arr[l];
                arr[l] = arr[r] ^ arr[l];
                arr[r] = arr[r] ^ arr[l];
                r++; 
                l++; 
            }else if(arr[r] == 0 && arr[l] == 0){
                l++; 
            }else{
                continue; 
            }
        }

        // printing
        for(int ele : arr){
            System.out.print(ele + " "); 
        }
    }
}