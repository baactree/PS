#include <bits/stdc++.h>
using namespace std;
int n;
int mat[20][20];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	vector<int> vec(n);
	for(int i=n/2;i<n;i++)
		vec[i]=1;
	int ans=1e9;
	do{
		int now[2]={0,};
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(i==j)
					continue;
				if(vec[i]==vec[j])
					now[vec[i]]+=mat[i][j];
			}
		ans=min(ans,abs(now[0]-now[1]));
	}while(next_permutation(vec.begin(),vec.end()));
	printf("%d\n",ans);
	return 0;
}