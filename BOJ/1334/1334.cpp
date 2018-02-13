#include <bits/stdc++.h>
using namespace std;
bool possi(const string &str){
	int le=0;
	int ri=str.size()-1;
	while(le<ri){
		if(str[le]!=str[ri])
			return false;
		le++;
		ri--;
	}
	return true;
}
void calc(string &str,int idx){
	bool flag=true;
	while(idx>=0&&flag){
		flag=false;
		if(str[idx]=='9'){
			flag=true;
			str[idx]='0';
		}
		else
			str[idx]++;
		idx--;
	}
	if(idx==-1&&flag)
		str="1"+str;
}
void solve(string &str){
	int le,ri;
	le=0;
	ri=str.size()-1;
	while(le<ri){
		if(str[le]<str[ri]){
			str[ri]='0';
			calc(str,ri-1);
		}
		int diff=str[le]-str[ri];
		str[ri]+=diff;
		le++;
		ri--;
	}
}
int main(){
	string str;
	cin>>str;
	if(possi(str))
		calc(str,str.size()-1);
	solve(str);
	cout<<str<<endl;
	return 0;
}