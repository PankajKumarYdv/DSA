import java.lang.*;
import java.util.*;

public class sum{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); 
		System.out.print("Enter first number : "); 
		int firstNumber = sc.nextInt();

		System.out.print("Enter Second number : "); 
		int secondNumber = sc.nextInt(); 

		System.out.println(firstNumber + "+" + secondNumber + "=" + (firstNumber + secondNumber));
	    sc.close(); 	
	}
}
