#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> t;
int main(){
	for(ll i=1;i*(i+1)/2<=1e9;i++)
		t.insert(i*(i+1)/2);
	vector<int> x;
	for(ll i=1;i*i<=1e9;i++)
		if(t.find(i*i-1)!=t.end())
			x.push_back(i*i);
	int a,b;
	int tc=1;
	while(true){
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
			break;
		auto le=upper_bound(x.begin(),x.end(),a);
		auto ri=lower_bound(x.begin(),x.end(),b);
		printf("Case %d: %d\n",tc,ri-le);
		tc++;
	}
	return 0;
}