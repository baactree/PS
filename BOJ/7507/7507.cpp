#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<pair<int,int> > > arr;
vector<int> cache;
int solve(int idx){
	if(idx==m)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1);
	int nidx=lower_bound(arr[k].begin(),arr[k].end(),
		make_pair(arr[k][idx].second,0))-arr[k].begin();
	ret=max(ret,solve(nidx)+1);
	return ret;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		arr.clear();
		scanf("%d",&n);
		map<int,int> mp;
		int idx=0;
		for(int i=0;i<n;i++){
			int d,s,e;
			scanf("%d%d%d",&d,&s,&e);
			if(mp.count(d)==0)
				mp[d]=idx++;
			d=mp[d];
			if(arr.size()==d)
				arr.push_back(vector<pair<int,int> >());
			arr[d].push_back({s,e});
		}
		int ans=0;
		for(int i=0;i<idx;i++){
			sort(arr[i].begin(),arr[i].end());
			cache=vector<int>(arr[i].size(),-1);
			m=arr[i].size();
			k=i;
			ans+=solve(0);
		}
		printf("Scenario #%d:\n%d\n",tc,ans);
		if(tc<testcase)
			printf("\n");
	}
	return 0;
}