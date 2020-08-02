public class Arrayreverse {
    public static int reverse(int[] arr,int i){
        if(i==-1){
            return 0;
        }
        else{
            System.out.println(arr[i]);
            reverse(arr,i-1);
        }
        return 0;
    }
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5,6,7};
        reverse(arr,6);
    }
}