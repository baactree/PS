#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<pair<int,int>,int> > event;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		event.push_back({{a,0},i+1});
		event.push_back({{b,1},i+1});
	}
	sort(event.begin(),event.end());
	int ans=0;
	set<int> anss;
	int cnt=0;
	set<int> now;
	for(int i=0;i<event.size();i++){
		if(!event[i].first.second){
			cnt++;
			now.insert(event[i].second);
		}
		else{
			cnt--;
			now.erase(event[i].second);
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	for(int i=0;i<event.size();i++){
		if(!event[i].first.second){
			cnt++;
			now.insert(event[i].second);
		}
		else{
			cnt--;
			now.erase(event[i].second);
		}
		if(cnt==ans){
			for(auto x:now)
				printf("%d ",x);
			printf("\n");
			return 0;
		}
	}
	return 0;
}