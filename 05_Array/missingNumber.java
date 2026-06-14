public class missingNumber{
    public static void main(String[] args){
        int[] nums = { 9,6,4,2,3,5,7,0,1}; 
        int longest = (int) Double.NEGATIVE_INFINITY;  
        int smallest = (int) Double.POSITIVE_INFINITY; 
        int sumOfArray = 0; 
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > longest){
                longest = nums[i]; 
            }

            if(nums[i] < smallest){
                smallest = nums[i]; 
            }
            sumOfArray += nums[i]; 
        }

        int sumofNterm =(int) (nums.length+1)*(smallest + longest)/2; 
        int missingNumber =  sumofNterm - sumOfArray; 
        System.out.print(sumofNterm + " " + missingNumber);
    }
}