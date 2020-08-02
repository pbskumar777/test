import java.util.*; 
import java.io.*;
public class Main {

  public static File getFileInfo(){
    System.out.println("Enter the name of quiz file (Eg: /home/user/Quizscores.txt): ");
    Scanner sc = new Scanner(System.in);
    String path = sc.next();
    File tempFile = new File(path);
    boolean exists = tempFile.exists();
    if(!exists){
        System.out.println("Error! File does not exist.");
        return getFileInfo();
    }
    return tempFile;
  }

  public static void readFile(Scanner sc, Map<String,String> students){
    while (sc.hasNextLine()){ 
      String s = sc.nextLine();
      String[] data = s.split(", ");
      students.put(data[0], data[1]);
    }
  }

  public static void createKey(String[] key,int questions){
    Scanner readkey = new Scanner(System.in);
    int v = questions;
    System.out.println("Please enter the answers for the following questions: ");
    System.out.println("Where 'T' = true, 'F' = false or A,B,C,D,E for multiple choice ");
    while(questions>0){
        System.out.print(Integer.toString(v-(questions-1))+") ");
        key[v-questions] = readkey.next().toUpperCase();
        questions--;
    }
  }

  public static void gradeQuiz(Map<String,String> students, int[] student_result,String[] key,int points,int[] correct){
    int count = 0;
    Map<String, Integer> guide = new HashMap<>();
    guide.put("T",1);
    guide.put("F",2);
    guide.put("A",1);
    guide.put("B",2);
    guide.put("C",3);
    guide.put("D",4);
    guide.put("E",5);
    for (Map.Entry<String,String> iter : students.entrySet()){
        int score = 0;
        int corr = 0;
        String val = iter.getValue();
        for(int i=0;i<val.length();i++){
            String atI = key[i];
            if(Integer.parseInt(String.valueOf(val.charAt(i)))==guide.get(atI)){
                corr+=1;
                score+=points;
            }
        }
        student_result[count] = score;
        correct[count] = corr;
        count++;
    }
  }

  public static float percentage(int i,int[] correct,int questions){
    float c = correct[i];
    float q = questions;
    return (c/q)*100;
  }

  public static String getLetterGrade(int i,int[] correct,int questions){
    float c = correct[i];
    float q = questions;
    float per = (c/q)*100;
    if(per >= 90.00 && per <= 100.00){
        return "A";
    }
    else if(per >= 80.00 && per <= 89.9999){
        return "B";
    }
    else if(per > 70.00 && per <= 79.9999){
        return "C";
    }
    else if(per >= 60.00 && per <= 70.00){
        return "D";
    }
    else{
        return "F";
    }
  }

  public static String getLetterGrade(float per){
    if(per >= 90.00 && per <= 100.00){
        return "A";
    }
    else if(per >= 80.00 && per <= 89.9999){
        return "B";
    }
    else if(per > 70.00 && per <= 79.9999){
        return "C";
    }
    else if(per >= 60.00 && per <= 70.00){
        return "D";
    }
    else{
        return "F";
    }
  }

  public static float getAverage(int[] correct, int questions){
    float q = questions;
    float avg = 0;
    for(int i=0;i<correct.length;i++){
        float av = correct[i];
        avg+= (av/q)*100;
    }
    return avg/correct.length;
  }

  public static void saveResults(Map<String,String> students,int[] correct,double[] percentages,int[] student_result,String[] grades){
    int i=0;
    System.out.println("Results.txt File created... ");
    try {
        FileWriter Writer = new FileWriter("Results.txt");
        for (Map.Entry<String,String> iter : students.entrySet()){
            Writer.write(iter.getKey()+","+Integer.toString(correct[i])+","+Double.toString(percentages[i])+","+Integer.toString(student_result[i])+","+grades[i]);
            i++;
            Writer.write("\n");
        }
        Writer.close();
        System.out.println("Successfully wrote to the file.");
      } catch (IOException e) {
        System.out.println("An error occurred.");
        e.printStackTrace();
      }
  }

  public static void display(Map<String,String> students,int[] correct,int[] student_result,int questions){
    int i=0;
    double[] percentages = new double[correct.length];
    String[] grades = new String[correct.length];
    System.out.println("Student ID\t# correct\t% Correct\tScore\t\tGrade");
    for (Map.Entry<String,String> iter : students.entrySet()){
        double percent = Double.parseDouble(String.format("%.2f",percentage(i,correct,questions)));
        percentages[i] = percent;
        grades[i] = getLetterGrade(i,correct,questions);
        System.out.println(iter.getKey()+"\t    "+Integer.toString(correct[i])+"\t\t  "+Double.toString(percent)+"\t\t "+Integer.toString(student_result[i])+"\t\t  "+getLetterGrade(i,correct,questions));
        i++;
    }
    float average = getAverage(correct,questions);
    System.out.println("Average: "+Float.toString(average)+"("+getLetterGrade(average)+")"); 
    System.out.println("Highest: " +Arrays.stream(student_result).max().getAsInt()); 
    System.out.println("Lowest: " +Arrays.stream(student_result).min().getAsInt()); 
    saveResults(students,correct,percentages,student_result,grades);
  }
  
  public static void main(String[] args) throws Exception {
    File file = getFileInfo();
    Map<String, String> students = new HashMap<>();
    Scanner sc = new Scanner(file);
    Scanner inp = new Scanner(System.in);
    readFile(sc,students);
    System.out.println("Please enter the number of questions on the exam: ");
    int questions = inp.nextInt();
    System.out.println("Please enter the number of points per question: ");
    int points = inp.nextInt();
    String[] key = new String[questions];
    createKey(key,questions);
    int[] student_result = new int[students.size()];
    int[] correct = new int[students.size()];
    gradeQuiz(students,student_result,key,points,correct);
    display(students, correct, student_result, questions);
  }
}