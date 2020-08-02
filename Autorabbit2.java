import java.io.*;
import java.util.*;
import java.lang.Math;
public class Autorabbit2
{
    public static int sieveOfEratosthenes(int n) 
    { 
        boolean prime[] = new boolean[n+1]; 
        for(int i=0;i<=n;i++) 
            prime[i] = true; 
          
        for(int p = 2; p*p <=n; p++) 
        { 
            if(prime[p] == true) 
            { 

                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
        int c=0;
        for(int i = 2; i <= n; i++) 
        { 
            if(prime[i] == true){ 
                while(n%i==0){
                    c=c+1;
                    n=n/i;
                }}
        } 
        return c;
    }
    public static void main (String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            int fin=0;
            for(int i=1;i<=n;i++){
                fin=fin+sieveOfEratosthenes(i);
            }
            System.out.println(fin);
        }
    }
}