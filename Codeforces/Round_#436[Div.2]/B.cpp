#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int calc(string s){
	set<char> t;
	for(int i=0;i<s.size();i++){
		t.insert(s[i]);
	}
	return t.size();
}
int main(){
	cin>>n>>str;
	int ans=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='A'&&str[i]<='Z')
			continue;
		int st=i;
		int ed=i;
		while(ed<str.size()&&str[ed]>='a'&&str[ed]<='z')
			ed++;
		ans=max(ans,calc(string(str.begin()+st,str.begin()+ed)));
		i=ed-1;
	}
	printf("%d\n",ans);
	return 0;
}