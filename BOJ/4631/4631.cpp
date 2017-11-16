#include <bits/stdc++.h>
using namespace std;
bool cmp(string &a,string &b){
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}
int main(){
	int n;
	int tc=1;
	while(true){
		scanf("%d",&n);
		if(n==0)
			break;
		vector<string> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		printf("SET %d\n",tc);
		for(int i=0;i<n;i+=2)
			cout<<vec[i]<<'\n';
		for(int i=(n&1)?n-2:n-1;i>=0;i-=2)
			cout<<vec[i]<<'\n';
		tc++;
	}
	return 0;
}