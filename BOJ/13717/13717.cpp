#include <bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,string> > > vec;
int n;
int calc(int a,int b){
	int ret=0;
	while(b>=a){
		int k=b/a;
		ret+=k;
		b=b%a+k*2;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		int a,b;
		scanf("%d%d",&a,&b);
		int temp=calc(a,b);
		ans+=temp;
		vec.push_back({temp,{-i,str}});
	}
	auto temp=*max_element(vec.begin(),vec.end());
	cout<<ans<<endl;
	cout<<temp.second.second<<endl;
	return 0;
}