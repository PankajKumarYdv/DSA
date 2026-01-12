import java.util.LinkedList; 

public class linkedlist{
    public static void main(String[] args){
        LinkedList <String> cars = new LinkedList <String> (); 
        cars.add("Volvo");
        cars.add("BMW");
        cars.add("Mazda");

        System.out.println(cars);
        System.out.println(cars.getFirst());
        System.out.println(cars.getLast());
        cars.addFirst("Dodge");
        cars.addLast("Audi");
        System.out.println(cars);

        // deletion
        cars.removeFirst();
        cars.removeLast();
        System.out.println(cars);
    }
}