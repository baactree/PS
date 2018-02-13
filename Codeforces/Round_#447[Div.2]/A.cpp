#include <bits/stdc++.h>
using namespace std;
string str;
int cache[100][3];
char p[3]={'Q','A','Q'};
int solve(int idx,int cnt){
	if(cnt==3)
		return 1;
	if(idx==str.size())
		return 0;
	int &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=0;
	if(str[idx]==p[cnt])
		ret+=solve(idx+1,cnt+1);
	ret+=solve(idx+1,cnt);
	return ret;
}
int main(){
	cin>>str;
	memset(cache,-1,sizeof(cache));
	printf("%d\n",solve(0,0));
	return 0;
}