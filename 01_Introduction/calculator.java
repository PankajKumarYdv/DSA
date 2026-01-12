import java.lang.*;
import java.util.*;
public class calculator{
	public static void main(String arg[]){
		Scanner input = new Scanner(System.in);
		String menu = """
			+------------------Calculator------------------+
			1. Addition 			2. Subtraction
			3. Multiplication 		4. Division
			5. Modulus
			""";
		System.out.println(menu);
		System.out.println("Choose Option : (0 to exit )"); 
		int userInput = input.nextInt(); 
		if (userInput == 1){
			System.out.println("Addition"); 
			float firstNumber = input.nextFloat();
			float secondNumber = input.nextFloat(); 
			float result = add(firstNumber, secondNumber);
			System.out.println(result);
			
		}else if (userInput == 2){
			System.out.println("Subtraction"); 
			float firstNumber = input.nextFloat(); 
			float secondNumber = input.nextFloat();
			System.out.println(subtract(firstNumber, secondNumber));
			
		}else if (userInput == 3){
			System.out.println("Multiplication");
			float firstNumber = input.nextFloat();
			float secondNumber = input.nextFloat(); 
			System.out.println(multiply(firstNumber,secondNumber));
			
		}else if (userInput == 4){
			System.out.println("Division");
			float firstNumber = input.nextFloat();
			float secondNumber = input.nextFloat();
			System.out.println(divide(firstNumber, secondNumber));
			
		}else if (userInput == 5){
			System.out.println("Modulus");
			float firstNumber = input.nextFloat();
			float secondNumber = input.nextFloat();
			System.out.println(modulus(firstNumber, secondNumber));
		}else if (userInput == 0){
			System.exit(0); 
		}else {
			System.exit(0);
		}
		
	}
	
	public static float add(float x, float y){
		// float result = x + y;
		return  x + y;//result;  
	}
	
	public static float subtract(float x, float y){
		return x - y; 
	}
	
	public static float multiply(float x, float y){
		return x * y; 
	}
	
	public static float divide(float x, float y){
		return x / y; 
	}
	
	public static float modulus(float x, float y){
		return x % y;
	}
	
}