import java.util.List;
import java.util.ArrayList; 
import java.util.Collections; 


public class arrayList {
    public static void main(String[] args){
        ArrayList <String> cars = new ArrayList <String> (); 
        cars.add("Volvo");
        cars.add("BMW"); 
        cars.add("Ford");

        // Sort cars
        Collections.sort(cars);
        for(String car : cars){
            System.out.println(car);
        }

        // Integer ArrayList 
        List <Integer> nums = new ArrayList <> (); 
        nums.add(32);
        nums.add(23);
        nums.add(90);

        System.out.println(nums);
        for(int num : nums){
            System.out.println(num);
        }
        
    }
}