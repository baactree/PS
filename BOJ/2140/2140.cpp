#include <bits/stdc++.h>
using namespace std;
int n;
char mat[105][105];
char temp[105][105];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",mat[i]);
	if(n<=2)
		return !printf("0\n");
	for(int i=2;i<n-2;i++)
		for(int j=2;j<n-2;j++)
			mat[i][j]='*';
	for(int q=0;q<4;q++){
		for(int i=0;i<n;i++){
			if(mat[0][0]=='1')
				mat[1][1]='*';
			else
				mat[1][1]=' ';
			for(int j=1;j<n-3;j++){
				int cnt=0;
				for(int k=0;k<2;k++)
					if(mat[1][j-1+k]=='*')
						cnt++;
				if(cnt==mat[0][j]-'0')
					mat[1][j+1]=' ';
				else if(cnt+1==mat[0][j]-'0')
					mat[1][j+1]='*';
				else
					assert(false);
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				temp[n-1-j][i]=mat[i][j];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				mat[i][j]=temp[i][j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]=='*')
				ans++;
	printf("%d\n",ans);
	return 0;
}