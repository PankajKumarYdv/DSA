public class missingInArray{
    public static void main(String[] args){
        // user input 
        int[] arr = {1,2,3,5}; 
        int arrSum = 0; 
        for(int ele : arr){
            arrSum = arrSum + ele; 
        }
        // logic 
        int n = arr.length+1; 
        // Math.pow(N, P);
        int sumOfN =(int) (Math.pow(n,2) + n)/2; 

        // Missing number 
        System.out.println(sumOfN - arrSum); 
    }
}