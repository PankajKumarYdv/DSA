import java.util.HashMap;
public class majorityElements{
    public static void main(String[] args){
        int[] arr = {3,2,3}; 


        // Logic 


        // Result 
        myApproach(arr); 
    }


    // My Approach 
    public static void myApproach(int[] arr){
        HashMap<Integer,Integer> numberMap = new HashMap <Integer, Integer>(); 
        int nby2 = arr.length/2;
        for(int i = 0; i < arr.length; i++){
            numberMap.putIfAbsent(arr[i], 0);
            int value = numberMap.get(arr[i]);
            numberMap.put(arr[i], value + 1);
        }

        // hashMap
        System.out.println(numberMap);
        // printing 
        for (int i : numberMap.keySet()) {
            if(numberMap.get(i) > nby2){
                System.out.println(i); 
                break; 
            }
        }

    }
}