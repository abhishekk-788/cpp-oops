import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream("input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			System.err.println("Error");
		}
		Scanner sc = new Scanner(System.in);
		int t = 1;
		// t = sc.nextInt();
		
		while(t != 0)
		{
		    int n = sc.nextInt();
    		String x = sc.next();
    		
    		/* For String */
    		StringBuilder str = new StringBuilder(x);
    		StringBuilder s = new StringBuilder(x);
    	}
	}
}