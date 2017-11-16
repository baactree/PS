#include <bits/stdc++.h>
using namespace std;
vector<int> idx[26];
string str;
int main(){
	cin>>str;
	int ans=0;
	int now=-1;
	int st=0;
	for(int i=0;i<str.size();i++){
		int t=str[i]-'a';
		idx[t].push_back(i);
		auto it=upper_bound(idx[t].begin(),idx[t].end(),now);
		if(it==idx[t].end()||*it>=st){
			ans++;
			if(now!=-1)
				i--;
			st=i+1;
			now=-1;
		}
		else{
			now=*it;
		}
	}
	if(now!=-1)
		ans++;
	printf("%d\n",ans);
	return 0;
}