#include <bits/stdc++.h>
using namespace std;
int n,m;
map<int,int> mp;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		mp[a]=b;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		vector<int> ans;
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			if(mp.count(x)!=0){
				ans.push_back(mp[x]);
			}
		}
		if(ans.size()!=k)
			printf("YOU DIED\n");
		else{
			for(int j=0;j<k;j++)
				printf("%d%c",ans[j]," \n"[j==k-1]);
		}
	}
}