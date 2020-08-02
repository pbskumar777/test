import java.util.*;
import java.lang.*;
import java.io.*;
public class Problem {
    public static List<String> applyfilter(String[] arr){
        List<String> d = new ArrayList<>();
        for(int i=0;i<arr.length;i++){
            if(arr[i].length() != 0){
                if(!(arr[i].length() == 1 && arr[i].equals(" ")))
                    d.add(arr[i].trim());
            }
        }
        return d;
    }
    public static String StandardizeStatement(FileReader input, FileWriter output){
        try(BufferedReader ir = new BufferedReader(input); BufferedWriter or = new BufferedWriter(output);){
            or.write("Date,Transaction Description,Debit,Credit,Currency,CardName,Transaction,Location" + "\n");
            String line = "";
            String transaction = "";
            String user = "";
            HashMap<String, Integer> header= new HashMap<>();
            while((line = ir.readLine())!=null){
                if(line.replace(",","").length() != 0){
                    if(line.contains("Domestic Transactions")){
                        transaction = "Domestic";
                    }
                    else if(line.contains("International Transactions")){
                        transaction = "International";
                    }
                    else{
                        line = line.replace(",,",",0,");
                        String data[] = line.split(",");
                        List<String> arr = applyfilter(data);
                        if(arr.size() == 2 || arr.size() == 1){
                            if(arr.size() == 1)
                                user = arr.get(0);
                            else
                                user = arr.get(1);
                        }
                        else if(arr.contains("Date")){
                            int count = 0;
                            for(String k : arr){
                                header.put(k,count);
                                count++;
                            }
                        }
                        else{
                            String result = "";
                            String dateValue = arr.get(header.get("Date")).replace("-","/").replace(".","/");
                            result += (dateValue + ",");

                            String locArr[] = null;
                            List<String> locModified = null;

                            if(header.containsKey("Transaction Description")){
                                locArr = arr.get(header.get("Transaction Description")).split(" ");
                            }
                            else{
                                locArr = arr.get(header.get("Transaction Details")).split(" ");
                            }

                            locModified = applyfilter(locArr);

                            if(transaction.equals("International")){
                                for(int i = 0;i<locModified.size()-2;i++){
                                    result += locModified.get(i) + " ";
                                }
                            }
                            else{
                                for(int i = 0;i<locModified.size()-1;i++){
                                    result += locModified.get(i) + " ";
                                }
                            }

                            result += ",";

                            if(header.containsKey("Amount")){
                                result += arr.get(header.get("Amount")).split(" ")[0] + ",";
                                result += "0" + ",";
                            }
                            else{
                                result += arr.get(header.get("Debit")).split(" ")[0] + ",";
                                result += arr.get(header.get("Credit")).split(" ")[0] + ",";
                            }

                            if(transaction.equals("International")){
                                result += locArr[locArr.length - 1] + ",";
                                result += user + ",";
                                result += transaction + ",";
                                result += locModified.get(locModified.size()-2).toLowerCase();
                            }
                            else{
                                result += "INR" + ",";
                                result += user + ",";
                                result += transaction + ",";
                                result += locArr[locArr.length - 1].toLowerCase();
                            }
                            or.write(result + "\n");
                        }
                    }
                }
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        return "Standard Output Statement Generated Successfully !!";
    }
    public static void main(String[] args){
        BufferedReader br = null;
        try{
            br = new BufferedReader(new InputStreamReader(System.in));
            while(true){
                System.out.println("*****Menu*****");
                System.out.println("1. Enter File Location");
                System.out.println("2. Exit");
                System.out.println("Please choose an option from menu !!");
                int option = Integer.parseInt(br.readLine());
                if(option == 2){
                    System.out.println("System successfully exited !!");
                    break;
                }
                else{
                    System.out.println("Please enter file location - ");
                    String location = br.readLine();
                    FileReader input = null;
                    try{
                        input = new FileReader(location);
                    }
                    catch(FileNotFoundException e){
                        System.out.println(e.getMessage());
                        continue;
                    }
                    String filename = location.replace("Input","Output");
                    FileWriter output = new FileWriter(filename);
                    System.out.println(StandardizeStatement(input, output));
                }
            }
        }
        catch(IOException e){
            System.out.println(e.getMessage());
        }
        finally{
            try{
                br.close();
            }
            catch(IOException e){
                System.out.println(e.getMessage());
            }
        }
    }
    
}
