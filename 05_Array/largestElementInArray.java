public class largestElementInArray{
    public static void main(String[] args){
        double negInf = Double.NEGATIVE_INFINITY;
        int[] arr = {1,8,7,56,90};
        for(int i= 0; i < arr.length; i++){
            if(arr[i] > negInf) negInf = arr[i]; 
        }
        System.out.println((int) negInf); 
    }
}