import java.util.*;
import java.net.*;
import java.io.*;

public class Client{
	public static void main(String []args){
		try{
			Scanner sc = new Scanner(System.in);
			Socket s = new Socket("localhost", 6969);

			DataOutputStream dout = new DataOutputStream(s.getOutputStream());
			DataInputStream din = new DataInputStream(s.getInputStream());

			String str = sc.nextLine();
			char c = sc.next().charAt(0);

			dout.writeUTF(str);
			dout.writeChar(c);

			System.out.println(din.readInt());

			sc.close();
			s.close();			
		} catch(Exception e){
			System.out.println(e);
		}
	}
}