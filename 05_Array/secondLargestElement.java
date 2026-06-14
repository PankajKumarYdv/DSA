// Second Largest number without Sorting
public class secondLargestElement{
    public static void main(String[] args){
        double largestNumber = Double.NEGATIVE_INFINITY;    
        double secondLarNum = Double.NEGATIVE_INFINITY; 
        int[] arr = {10,10,10,10}; 
        for(int i = 0; i < arr.length; i++){
            if(arr[i] > secondLarNum && arr[i] > largestNumber){
                secondLarNum = largestNumber; 
                largestNumber = arr[i]; 
            }else if(arr[i] > secondLarNum && arr[i] < largestNumber){
                secondLarNum = arr[i]; 
            }else{
                continue; 
            }
        }
        if(secondLarNum < 0) System.out.println(-1); 
        else System.out.println((int) secondLarNum);
         
    }
}