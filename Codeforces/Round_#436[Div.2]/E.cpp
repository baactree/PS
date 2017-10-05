#include <bits/stdc++.h>
using namespace std;
struct Item{
	int t,d,p,idx;
	bool operator <(const Item &rhs)const{
		return d<rhs.d;
	}
};
int n;
Item arr[105];
int cache[105][2005];
int solve(int idx,int ri){
	if(idx==n)
		return 0;
	int &ret=cache[idx][ri];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1,ri);
	if(ri+arr[idx].t<arr[idx].d)
		ret=max(ret,solve(idx+1,ri+arr[idx].t)+arr[idx].p);
	return ret;
}
vector<int> ans;
void get_ans(int idx,int ri){
	if(idx==n)
		return;
	int ret=solve(idx+1,ri);
	if(ri+arr[idx].t<arr[idx].d){
		if(ret<solve(idx+1,ri+arr[idx].t)+arr[idx].p){
			ans.push_back(idx);
			get_ans(idx+1,ri+arr[idx].t);
			return;
		}
	}
	get_ans(idx+1,ri);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&arr[i].t,&arr[i].d,&arr[i].p);
		arr[i].idx=i+1;
	}
	sort(arr,arr+n);
	memset(cache,-1,sizeof(cache));
	printf("%d\n",solve(0,0));
	get_ans(0,0);
	printf("%d\n",ans.size());
	for(auto x:ans)
		printf("%d ",arr[x].idx);
	printf("\n");
	return 0;
}