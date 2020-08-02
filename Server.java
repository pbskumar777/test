import java.net.*;
import java.io.*;
class Server{
    public static void main(String[] args){
        try{
            ServerSocket ss = new ServerSocket(1080);
            Socket s = ss.accept();
            InputStream is = s.getInputStream();
            DataInputStream dis = new DataInputStream(is);

            OutputStream os = s.getOutputStream();
            DataOutputStream dos = new DataOutputStream(os);
            int line = 0;
            BufferedReader br = new BufferedReader(new FileReader("/home/shiva/Downloads/messages.txt"));
            while(true){            
                String msg = dis.readUTF();
                if(msg.equals("break") || msg==null){
                    dos.writeUTF("Terminated by you :(");
                    break;
                }
                String l = "";
                int count = 0;
                while((l = br.readLine())!=null){
                    if(line == count){
                        dos.writeUTF(l);
                        System.out.println("Sent : " + l);
                        line++;
                        break;
                    } 
                    else{
                        count++;
                    }
                }
                if(l == null){
                    dos.writeUTF("Chat is over !! Bye bye");
                    break;
                }
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}