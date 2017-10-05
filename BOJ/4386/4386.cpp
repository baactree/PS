#include <bits/stdc++.h>
using namespace std;
int n;
pair<double,double> arr[105];
vector<pair<double,pair<int,int> > > edge;
int par[105];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&arr[i].first,&arr[i].second);
		par[i]=i;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			edge.push_back({hypot(arr[i].first-arr[j].first,arr[i].second-arr[j].second),{i,j}});
		}
	sort(edge.begin(),edge.end());
	double ans=0;
	for(int i=0;i<edge.size();i++){
		double weight=edge[i].first;
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		if(find(u)==find(v))
			continue;
		ans+=weight;
		merge(u,v);
	}
	printf("%.2f\n",ans);
	return 0;
}