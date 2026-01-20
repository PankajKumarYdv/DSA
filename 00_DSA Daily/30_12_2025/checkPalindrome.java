public class checkPalindrome{
    public static void main(String[] args){
        if(isPalindrome(1251)){
            System.out.println("Number is Palindrome"); 
        }else{
            System.out.println("Number is not Palindrome"); 
        }

    }

    // check palindrome number 
    public static boolean isPalindrome(int num){
        int reverseNumber = 0;
        int n = num; 
        int rem; 
        while(num > 0){
            rem = num%10; 
            reverseNumber = (reverseNumber * 10) + rem; 
            num = num / 10; 
        }
        
        return  reverseNumber == n; 
        

    }
}