import java.net.*;
import java.io.*;

public class Server{
	public static void main(String []args){
		try{
			ServerSocket ss = new ServerSocket(6969);
			Socket s = ss.accept();

			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			DataInputStream din = new DataInputStream(s.getInputStream());

			String str = (String)din.readUTF();
			char c = din.readChar();

			int ans = -1;
			for(int i = 0; i < str.length(); i++){
				if(str.charAt(i) == c){
					ans = i;
					break;
				}
			}

			dout.writeInt(ans);

			ss.close();
		} catch(Exception e){
			System.out.println(e);
		}
	}
}