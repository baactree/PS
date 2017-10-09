#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int order[255];
int rorder[26];
int main(){
	int tc=1;
	while(true){
		scanf("%d",&n);
		if(n==0)
			break;
		cin>>str;
		for(int i=0;i<str.size();i++){
			order[str[i]]=i;
			rorder[i]=str[i];
		}
		vector<string> vec(n);
		for(int i=0;i<n;i++){
			cin>>vec[i];
			for(int j=0;j<vec[i].size();j++)
				vec[i][j]=order[vec[i][j]];
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<n;i++)
			for(int j=0;j<vec[i].size();j++)
				vec[i][j]=rorder[vec[i][j]];
		printf("year %d\n",tc++);
		for(auto x:vec)
			cout<<x<<'\n';
	}
	return 0;
}