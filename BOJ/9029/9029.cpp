#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[205][205][205];
inline int calc(int a,int b,int c){
	if(a>b)
		swap(a,b);
	if(b>c)
		swap(b,c);
	if(a>b)
		swap(a,b);
	return dp[a][b][c];
}
int main(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<205;i++)
		dp[i][i][i]=1;
	for(int w=1;w<=200;w++)
		for(int l=w;l<=200;l++)
			for(int h=l;h<=200;h++){
				for(int k=1;k*2<=w;k++)
					dp[w][l][h]=min(dp[w][l][h],calc(k,l,h)+calc(w-k,l,h));
				if(w!=l)
					for(int k=1;k*2<=l;k++)
						dp[w][l][h]=min(dp[w][l][h],calc(w,k,h)+calc(w,l-k,h));
				if(l!=h)
					for(int k=1;k*2<=h;k++)
						dp[w][l][h]=min(dp[w][l][h],calc(w,l,k)+calc(w,l,h-k));
			}
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int w,l,h;
		scanf("%d%d%d",&w,&l,&h);
		printf("%d\n",calc(w,l,h));
	}
	return 0;
}