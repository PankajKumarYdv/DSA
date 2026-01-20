public class reverseDigitofANumber{
    
    public static void main(String[] args){
        int reverseNumber = bruteForce(1234); 
        System.out.println(reverseNumber); 
    }

    public static int bruteForce(int num){
        int reverseNumber = 0;
        int rem; 
        while(num > 0){
            rem =  num % 10; 
            reverseNumber = (reverseNumber * 10) + rem;
            num = num/10;
        }
        return reverseNumber; 
    }
}