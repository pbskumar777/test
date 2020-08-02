
import java.net.*;
import java.io.*;
class Client{
    public static void main(String[] args){
        try{
            Socket sc = new Socket("localhost",1080);
            InputStream is = sc.getInputStream();
            DataInputStream dis = new DataInputStream(is);

            OutputStream os = sc.getOutputStream();
            DataOutputStream dos = new DataOutputStream(os);
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            while(true){
                System.out.println("Enter your message");
                String ms = br.readLine();
                dos.writeUTF(ms);
                String smessage = dis.readUTF();
                System.out.println(smessage);
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}