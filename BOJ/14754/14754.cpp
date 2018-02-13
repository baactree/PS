#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int mat[1005][1005];
bool check[1005][1005];
int main(){
	scanf("%d%d",&n,&m);
	ll sum=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&mat[i][j]);
			sum+=mat[i][j];
		}
	for(int i=0;i<n;i++){
		int v=-1;
		int idx=-1;
		for(int j=0;j<m;j++){
			if(mat[i][j]>v){
				v=mat[i][j];
				idx=j;
			}
		}
		check[i][idx]=true;
	}
	for(int i=0;i<m;i++){
		int v=-1;
		int idx=-1;
		for(int j=0;j<n;j++){
			if(mat[j][i]>v){
				v=mat[j][i];
				idx=j;
			}
		}
		check[idx][i]=true;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(check[i][j])
				sum-=mat[i][j];
	printf("%lld\n",sum);
	return 0;
}