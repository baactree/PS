import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        
        BigInteger a;
        BigInteger b;
        
        BigInteger c;
			BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
		while (sc.hasNextInt()) {
			int N=sc.nextInt();
            a= BigInteger.ONE;
            b= BigInteger.ONE;
            
            c= BigInteger.ONE;
			for (int i = 2; i <= N; i++){
				c=b.add(a.multiply(two));
                a=b;
                b=c;
            }
			System.out.println(c);
		}
	}
}
