import java.util.*;
import java.io.*;
import java.lang.*;

class Node{
    private int data;
    public Node left = null;
    public Node right = null;

    Node(int d){
        this.data = d;
    }

    public int getData(){
        return this.data;
    }

    public void setData(int d){
        this.data = d;
    }
}

public class BST{

    public static Node insertion(int val, Node root){
        if(root == null){
            return new Node(val);
        }
        
        if(val < root.getData()){
            root.left = insertion(val,root.left);
        }
        else{
            root.right = insertion(val,root.right);
        }
        return root;
    }

    public static Node delete(int val, Node root){
        if(root == null){
            return root;
        }

        if(root.getData() < val){
            root.right = delete(val,root.right);
        }
        else if(root.getData() > val){
            root.left = delete(val, root.left);
        }
        else{
            if(root.left == null){
                return root.right;
            }
            else if(root.right == null){
                return root.left;
            }
            int min = inorderSuccessor(root.right);
            root.setData(min);
            root.right = delete(min,root.right); 
            return root;
        }
        return root;
    }

    public static int inorderSuccessor(Node root){
        int v = root.getData();
        while(root.left!=null){
            root = root.left;
            v = root.getData();
        }
        return v;
    }

    public static void display(Node root){
        if(root == null){
            return;
        }
        else{
            display(root.left);
            System.out.print(root.getData() + " ");
            display(root.right);
        }

    }

    public static void main(String[] args){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter size:");
            int s = Integer.parseInt(br.readLine());
            Node root = null;
            for(int i=0;i<s;i++){
                int val = Integer.parseInt(br.readLine());
                root = insertion(val,root);
                display(root);
                System.out.println("---------------------------");
            }

            System.out.println("Enter no of items to delete:");
            int it = Integer.parseInt(br.readLine());
            for(int i=0;i < it;i++){
                int valtodelete = Integer.parseInt(br.readLine());
                root = delete(valtodelete, root);
                display(root);
                System.out.println("---------------------------");
            }

        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}