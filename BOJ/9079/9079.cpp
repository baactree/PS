#include <bits/stdc++.h>
using namespace std;
int mat[3][3];
const int inf=0x3f3f3f3f;
int calc(int x){
	int ret=0;
	while(x){
		if(x&1)
			ret++;
		x/=2;
	}
	return ret;
}
void flip(int idx){
	if(idx==0)
		for(int i=0;i<3;i++)
			mat[0][i]^=1;
	if(idx==1)
		for(int i=0;i<3;i++)
			mat[1][i]^=1;
	if(idx==2)
		for(int i=0;i<3;i++)
			mat[2][i]^=1;
	if(idx==3)
		for(int i=0;i<3;i++)
			mat[i][0]^=1;
	if(idx==4)
		for(int i=0;i<3;i++)
			mat[i][1]^=1;
	if(idx==5)
		for(int i=0;i<3;i++)
			mat[i][2]^=1;
	if(idx==6)
		for(int i=0;i<3;i++)
			mat[i][i]^=1;
	if(idx==7)
		for(int i=0;i<3;i++)
			mat[i][2-i]^=1;
}
bool possi(int state){
	for(int i=0;i<8;i++){
		if(state&(1<<i))
			flip(i);
	}
	int cnt=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cnt+=mat[i][j];
	for(int i=0;i<8;i++){
		if(state&(1<<i))
			flip(i);
	}
	return (cnt==0||cnt==9);
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				char in[2];
				scanf("%s",in);
				mat[i][j]=in[0]=='T';
			}
		int ans=inf;
		for(int i=0;i<(1<<8);i++){
			if(possi(i))
				ans=min(ans,calc(i));
		}
		printf("%d\n",ans==inf?-1:ans);
	}
	return 0;
}