#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[8][8]={
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,0,1},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,1},
	{0,0,0,0,1,0,1,0}
};
ll ans[8][8]={
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,1}
};
int n;
const int mod=1e9+7;
void multi(ll (*a)[8],ll (*b)[8]){
	ll ret[8][8]={0,};
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			for(int k=0;k<8;k++){
				ret[i][j]+=(a[i][k]*b[k][j])%mod;
				ret[i][j]%=mod;
			}
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			a[i][j]=ret[i][j];
}
int main(){
	scanf("%d",&n);
	while(n){
		if(n&1)
			multi(ans,d);
		multi(d,d);
		n>>=1;
	}
	printf("%d\n",ans[0][0]);
	return 0;
}