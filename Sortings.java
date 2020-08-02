import java.util.*;
import java.lang.*;
import java.io.*;
public class Sortings{
    public static int[] bubblesort(int[] arr){
        for(int i = 0;i<arr.length-1;i++){
            for(int j = 0;j<arr.length-i-1;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }

    public static void recursivebubblesort(int[] arr, int size){
        if(size == 1){
            return;
        }
        for(int j=0;j<size-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        recursivebubblesort(arr, size-1);
    }

    public static int[] selectionsort(int[] arr){
        for(int i = 0;i<arr.length-1;i++){
            int min_ind = i, min_val = Integer.MAX_VALUE;
            for(int j = i;j < arr.length;j++){
                if(arr[j] < min_val){
                    min_val = arr[j];
                    min_ind = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
        return arr;
    }

    public static int[] insertionsort(int[] arr){
        for(int i =0;i<arr.length;i++){
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        return arr;
    }

    public static void recursiveinsertionsort(int[] arr, int i){
        if(i == arr.length){
            return;
        }
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        recursiveinsertionsort(arr, i+1);
    }

    public static int partition(int[] arr, int low, int high){
        int pivot = arr[high];
        int i = low-1;
        for(int j = low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        int temp = arr[high];
        arr[high] = arr[i+1];
        arr[i+1] = temp;
        return i+1;
    }

    public static void quicksort(int[] arr, int low, int high){
        if(low < high){
            int mid = partition(arr,low, high);
            quicksort(arr,low,mid-1);
            quicksort(arr,mid+1,high);
        }
    }

    public static void merge(int[] arr, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        int[] L = new int[n1];
        int[] R = new int[n2];
        for(int i = 0;i<n1;i++){
            L[i] = arr[l+i];
        }
        for(int j = 0;j<n2;j++){
            R[j] = arr[m+1+j];
        }
        int i=0;
        int j = 0;
        int k = l;
        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void sort(int[ ] arr, int l, int r){
        if(l<r){
            int m = (l+r)/2;
            sort(arr,l,m);
            sort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }

    public static void heapify(int[] arr, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && arr[largest]<arr[l]){
            largest = l;
        }

        if(r<n && arr[largest] < arr[r]){
            largest = r;
        }

        if(largest!=i){
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr,n,largest);
        }
    }

    public static void heapsort(int[] arr, int n){
        for(int i = n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }

        for(int i = n-1;i>0;i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr,i,0);
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        int[] arr = new int[size];
        for(int i=0;i<size;i++){
            arr[i] = Integer.parseInt(br.readLine());
        }
        heapsort(arr,size);
        for(int i = 0;i<arr.length;i++){
            System.out.println(arr[i] + " ");
        }
    }
}
