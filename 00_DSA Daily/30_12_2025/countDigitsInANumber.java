public class countDigitsInANumber{
    public static void main(String[] args){
        System.out.println("Count digits in a number"); 
        int cnt = bruteForce(348923); 
        System.out.println("Brute Force function :  " + cnt); 

        int result = optimalSolution(423423); 
        System.out.println("Optimal Solution Result :  " + result); 
    }

    public static int bruteForce(int num){
        int count = 0; 
        while(num>0){
            num = num/10; 
            count++; 
        }
        return count; 
    }

    // Optimal Solution
    public static int optimalSolution(int num){
        int cnt = (int) (Math.log10(num) + 1); 
        return cnt; 
    }
}