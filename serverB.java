import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Date;

public class serverB
{
	public static void main(String[] args)
	{
		try
	{
	System.out.println("Listening...");
	ServerSocket ss = new ServerSocket(7778);
	Socket soc = ss.accept();
	System.out.println("Connection established");
	BufferedReader in = new BufferedReader(new
InputStreamReader(soc.getInputStream()));
	PrintWriter out = new PrintWriter(soc.getOutputStream(), true);
	int d = Integer.parseInt(in.readLine());
	//System.out.println(d);
	//char result = d.charAt(11);
	//char result2 = d.charAt(12);
	//System.out.println(result);
	//System.out.println(result2);

	if(d<=11)
	{
		out.println("Good Morning");
	}
	else if(d>=13&&d<=19)
	{
		out.println("Good Evening");
	}
	else if(d>=20)
	{
		out.println("GOOD NIGHT");
	}
	else
	{
		out.println("GOOD AFTERNOON");
	}
	soc.close();
}
	catch(Exception e)
	{
		e.printStackTrace();
	}
}
}
