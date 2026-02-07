import java.util.HashMap; 
/*
HashMap<KeyDataType, ValueDataType> HashMapName = new HashMap<>(); 
Wrapper classes	Primitive data types
Integer	    -->   int
Character	-->   char
Float	    -->   float
Byte	    -->   byte
Short	    -->   short
Long	    -->   long
Double	    -->   double
Boolean	    -->   boolean
*/
public class hashmap{
    public static void main(String[] args){
        // Declaration 
        HashMap <String, Integer> productQuantity = new HashMap<>(); 

        // Putting data in the hashmap 
        productQuantity.put("Apple", 30); 
        productQuantity.put("Banana", 40); 
        productQuantity.put("Watermelon", 32); 
        productQuantity.put("Cherry", 54); 

        // printing hashmap values 
        System.out.println(productQuantity);  // {Apple=30, Cherry=54, Watermelon=32, Banana=40} 

        // Getting data by key; 
        System.out.println(productQuantity.get("Cherry")); 

        // Change the value of Items 
        productQuantity.replace("Banana", 20); 
        System.out.println(productQuantity); 


        // increasing value 
        int value = productQuantity.get("Banana"); 
        productQuantity.replace("Banana",value+120); 
        System.out.println(productQuantity);
        
        // delete
        productQuantity.remove("Apple");

        // clear 
        // productQuantity.clear(); 

        // HashMap Size 
        System.out.println(productQuantity.size()); 

        // printing keys 
        for(String keys : productQuantity.keySet()){
            System.out.println(keys); 
        }

        // printing values 
        for(int values : productQuantity.values()){
            System.out.println(values); 
        }
    }
}

// Add items to a HashMap 
