
import java.util.*;
import java.math.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int N=sc.nextInt();
		if(N<=1)
			System.out.println(N);
		else{
			BigInteger[] fibo=new BigInteger[N+1];
			fibo[0]=BigInteger.ZERO;
			fibo[1]=BigInteger.ONE;
			for(int i=2;i<=N;i++)
				fibo[i]=fibo[i-1].add(fibo[i-2]);
			System.out.println(fibo[N]);
		}
	}

}