import java.util.*;
public class removeDuplicatesSortedArray{
    // remove duplicate 
    public static List<Integer> removeDuplicate(int[] arr){
        ArrayList<Integer> tempArray = new ArrayList<Integer>();
        for(int i = 1; i < arr.length; i++){
            if(arr[i-1] == arr[i]){
                continue; 
            }else{
                tempArray.add(arr[i-1]);
            }
        }
        tempArray.add(arr[arr.length-1]);

        return tempArray; 
    }

    public static void main(){
        int[] arr={9,9,4,7,18,18,22,22}; 
        List<Integer> result = removeDuplicate(arr);
        for(int element : result){
            System.out.println(element); 
        }
        
    }
}