import java.net.*;
import java.io.*;
import java.util.*;

public class server
{
  public static void main(String[]args) throws IOException
  {
   String message, temp;
   String a ="Assalamualaikum";
   System.out.println("Connection successful");
   ServerSocket s1= new ServerSocket(52851);
   Socket s = s1.accept();
   Scanner sc = new Scanner(s.getInputStream());
   message = sc.next();

   if(message.equalsIgnoreCase(a))
     temp = "Waalaikumsalam";
   else
     temp = "Are you a muslim?";

   PrintStream p = new PrintStream(s.getOutputStream());
   p.println(temp);
   }
}
# netsprog
