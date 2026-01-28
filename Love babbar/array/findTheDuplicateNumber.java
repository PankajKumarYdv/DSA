public class findTheDuplicateNumber{
    public static void main(String[] args){
        int[] arr = {23,342,43,43,56,34}; 
        int  multipleArray = multiple(arr); 
        System.out.println(multipleArray); 
    }


    public static int multiple(int[] num){
        int[] number = num.clone();
        int n = number.length;
        if(n==1) return 0;
        // bubble sort 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (n-i)-1; j++){
                if(number[j] > number[j+1]){
                    number[j] = number[j] ^ number[j+1]; 
                    number[j+1] = number[j] ^ number[j+1];
                    number[j] = number[j] ^ number[j+1]; 
                }else{
                    continue; 
                }
            }
        }

        // duplicate finder 
        for(int i = 0; i < n-1; i++){
            if(number[i] == number[i+1]){
                return number[i]; 
            }else{
                continue; 
            }
        }

        return 0; 
    }
}