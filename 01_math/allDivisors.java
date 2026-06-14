import java.util.*; 
public class allDivisors{
    public static void main(String args[]){
        int number = 36; 
        double sqr = Math.sqrt(number); 
        // System.out.println(sqr); 
        for(int i = 1; i < sqr; i++){
            if(number%i == 0) {
                System.out.println(i);
                System.out.println(number/i);
            }else{
                continue; 
            }
        }
        System.out.println((int) sqr);
    }
}