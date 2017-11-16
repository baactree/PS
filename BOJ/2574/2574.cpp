#include <bits/stdc++.h>
using namespace std;

int min_value=2e9,max_value=0;
void solve(int x1,int y1,int x2,int y2,vector<pair<int,int> > &vec,int mode){
	if(vec.empty()){
		int now=(x2-x1)*(y2-y1);
		max_value=max(max_value,now);
		min_value=min(min_value,now);
		return;
	}
	if(!mode){
		vector<pair<int,int> > le,ri;
		int k=vec[0].second;
		for(int i=1;i<vec.size();i++){
			if(vec[i].second<k)
				le.push_back(vec[i]);
			else
				ri.push_back(vec[i]);
		}
		vec.~vector();
		new (&vec) vector<int>();
		solve(x1,y1,x2,k,le,1-mode);
		solve(x1,k,x2,y2,ri,1-mode);
	}
	else{
		vector<pair<int,int> > hi,lo;
		int k=vec[0].first;
		for(int i=1;i<vec.size();i++){
			if(vec[i].first<k)
				lo.push_back(vec[i]);
			else
				hi.push_back(vec[i]);
		}
		vec.~vector();
		new (&vec) vector<int>();
		solve(x1,y1,k,y2,lo,1-mode);
		solve(k,y1,x2,y2,hi,1-mode);
	}
}
int main(){
	int n,m;
	int k;
	scanf("%d%d%d",&n,&m,&k);
	vector<pair<int,int> > vec(k);
	for(int i=0;i<k;i++)
		scanf("%d%d",&vec[i].first,&vec[i].second);
	solve(0,0,n,m,vec,0);
	printf("%d %d\n",max_value,min_value);
	return 0;
}