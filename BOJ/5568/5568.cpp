#include <bits/stdc++.h>
using namespace std;
int n,k;
string arr[10];
set<int> s;
bool chk[10];
void solve(int cnt,string str){
	if(cnt==k){
		s.insert(stoi(str));
		return;
	}
	for(int i=0;i<n;i++){
		if(!chk[i]){
			chk[i]=true;
			solve(cnt+1,str+arr[i]);
			chk[i]=false;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	solve(0,"");
	printf("%d\n",s.size());
	return 0;
}