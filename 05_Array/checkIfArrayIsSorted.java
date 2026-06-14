public class checkIfArrayIsSorted{
    public static void main(String[] args){
        int[] arr = {90, 80, 100, 70, 40, 30};
        for(int i = 1; i < arr.length; i++){
            if (arr[i-1] < arr[i]) continue ; 
            else System.out.println("Not sorted"); 
        }
        System.out.println("SOrted"); 
    }
}