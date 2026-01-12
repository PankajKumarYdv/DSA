public class gcdOfTwoNumber{
    public static void main(String[] args){

        System.out.println("My Algo : " + gcd(20,15)); 
        System.out.println("Striver (BrutForce) : " + findGcd(20,15)); 
        System.out.println("Striver (Better) : " + betterFindGcd(20,15)); 
        System.out.println("Striver (Optimal) : " + optimalFindGcd(20,15)); 
        
    }


    // My Solution 
    public static int gcd(int a, int b){
        boolean flag = true; 
        int quad = 0; 
        int rem = 0; 
        while(flag){
            quad = a/b; 
            rem = a%b; 
            if (rem == 0){
                flag = false; 
                break; 
            }

            a = b;
            b = rem; 

        }

        return b; 
    }


    // Striver : Brute Force Approach 
    public static int findGcd(int n1, int n2) {
        // Initialize gcd to 1
        int gcd = 1;

        // Iterate from 1 up to
        // the minimum of n1 and n2
        for (int i = 1; i <= Math.min(n1, n2); i++) {
            // Check if i is a common
            // factor of both n1 and n2
            if (n1 % i == 0 && n2 % i == 0) {
                // Update gcd to the
                // current common factor i
                gcd = i;
            }
        }

        // Return the greatest
        // common divisor (gcd)
        return gcd;
    }


    // Better Approach 
    public static int betterFindGcd(int n1, int n2) {
        // Iterate from the minimum of
        // n1 and n2 down to 1
        // Start from the minimum of n1 and n2
        // because the GCD cannot
        // exceed the smaller number
        
        for (int i = Math.min(n1, n2); i > 0; i--) {
            // Check if i is a common
            // factor of both n1 and n2
            if (n1 % i == 0 && n2 % i == 0) {
                // If i is a common factor,
                // return it as the GCD
                return i;
            }
        }
        // If no common factors are found,
        // return 1 (as 1 is always a
        // divisor of any number)
        return 1;
    }

    // Optimal Approach 
    public static int optimalFindGcd(int a, int b) {
        while(a > 0 && b > 0) {
            // If a is greater than b,
            // subtract b from a and update a
            if(a > b) {
                // Update a to the remainder
                // of a divided by b
                a = a % b;
            }
            // If b is greater than or equal
            // to a, subtract a from b and update b
            else {
                // Update b to the remainder
                // of b divided by a
                b = b % a;
            }
        }
        // Check if a becomes 0,
        // if so, return b as the GCD
        if(a == 0) {
            return b;
        }
        // If a is not 0,
        // return a as the GCD
        return a;
    } 
}

