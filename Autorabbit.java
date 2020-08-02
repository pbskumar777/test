import java.util.*;
import java.io.*;
import java.lang.*;
public class Autorabbit{

    public static HashMap<Integer, Integer> primefactorization(int n){
        HashMap<Integer, Integer> primefactors = new HashMap<>();
        if(n == 1){
            primefactors.put(1,0);
            return primefactors;
        }

        while (n % 2 == 0) { 
            if(primefactors.containsKey(2)){
                primefactors.replace(2, primefactors.get(2)+1);
            }
            else{
                primefactors.put(2,1);
            }
			n /= 2; 
		} 

		for (int i = 3; i <= Math.sqrt(n); i += 2) { 
			while (n % i == 0) { 
                if(primefactors.containsKey(i)){
                    primefactors.replace(i, primefactors.get(i)+1);
                }
                else{
                    primefactors.put(i,1);
                }
				n /= i; 
			} 
		} 

		if (n > 2){
            if(primefactors.containsKey(n)){
                primefactors.replace(n, primefactors.get(n)+1);
            }
            else{
                primefactors.put(n,1);
            }
        } 
        return primefactors;
    }

    public static int gcd(int a, int b){
        if (a == 0) 
          return b; 
        if (b == 0) 
          return a; 
       
        if (a == b) 
            return a; 
       
        if (a > b) 
            return gcd(a-b, b); 
        return gcd(a, b-a);
    }

    public static int calculateA(ArrayList<Integer> factors){
        int count = 0;
        for(int f = 0;f < factors.size(); f++){
            for(int i = 1; i<= factors.get(f);i++){
                if(gcd(factors.get(f), i) == 1){
                    count += 1;
                }
            }
        }
        return count;
    }

    public static int calculateB(int v){
        ArrayList<Integer> factors = new ArrayList<>();
        for (int p = 1;p <= v;p++) 
            if(v%p==0){
                factors.add(p);
            }
        int sumofA = calculateA(factors);
        return sumofA;
    }

    public static int calculateC(int v){
        int bOfx = calculateB(v);
        HashMap<Integer, Integer> primeFactors = primefactorization(bOfx);
        int finalVal = 0;
        for(Map.Entry<Integer, Integer> entry : primeFactors.entrySet()){
            finalVal += entry.getValue();
        }
        return finalVal;
    }

    public static void main(String[] args){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int test = Integer.parseInt(br.readLine());
            for(int i=0;i<test;i++){
                int value = Integer.parseInt(br.readLine());
                int result = 0;
                for(int j = 1;j<=value;j++){
                    result += calculateC(j);
                }
                System.out.println(result);
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}