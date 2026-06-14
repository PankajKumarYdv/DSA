// Brute force method 
/* 1. Method 
public class gcd{
    public static void main(String[] args){
        int n1 = 24; 
        int n2 = 36; 
        int gcd = 1; 
        double sqr = Math.sqrt(Math.min(n1,n2)); 
        for(int i=1; i <= sqr; i++){
            if(n1%i == 0 && n2 % i == 0){
                gcd = i; 
            }
        }

        // gcd 
        System.out.println(gcd); 
    }
}
*/

// 2. Method 
public class gcd{
    public static void main(String[] args){
        int n1 = 24; 
        int n2 = 36; 

        int gcd = 1; 
        double sqr = Math.sqrt(Math.min(n1, n2));
        for(int i = (int) sqr; i > 0; i--){
            if(n1%i==0 && n2%i==0){
                gcd = i; 
                break; 
            }
        }
        System.out.println(gcd);
    }
}