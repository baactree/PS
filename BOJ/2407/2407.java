

import java.math.BigInteger;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		BigInteger dp[][] = new BigInteger[101][101];
		int n,m;
		n=sc.nextInt();
		m=sc.nextInt();
		for(int i=0;i<=n;i++)
			for(int j=0;j<=i;j++){
				if(j==0||j==i)
					dp[i][j]=BigInteger.ONE;
				else
					dp[i][j]=dp[i-1][j-1].add(dp[i-1][j]);
			}
		System.out.println(dp[n][m]);
	}

}
