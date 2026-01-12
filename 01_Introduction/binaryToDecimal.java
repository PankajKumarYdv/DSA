import java.lang.*; 
import java.util.*;
public class binaryToDecimal{
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		sc.useRadix(8); 
		int binaryNumber = sc.nextInt(); 
		System.out.println(binaryNumber);
		sc.close(); 
	}
}