#include <bits/stdc++.h>
using namespace std;
int n,m;
int dpl[10005],dpr[10005];
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d",&n,&m);
	vector<int> le,ri;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x<0)
			le.push_back(-x);
		else
			ri.push_back(x);
	}
	sort(le.begin(),le.end());
	sort(ri.begin(),ri.end());
	for(int i=1;i<=le.size();i++){
		dpl[i]=inf;
		int pre=max(i-m,0);
		dpl[i]=dpl[pre]+le[i-1]*2;
	}
	for(int i=1;i<=ri.size();i++){
		dpr[i]=inf;
		int pre=max(i-m,0);
		dpr[i]=dpr[pre]+ri[i-1]*2;
	}
	int now=dpl[le.size()]+dpr[ri.size()];
	int ans=inf;
	if(!le.empty())
		ans=min(ans,now-le.back());
	if(!ri.empty())
		ans=min(ans,now-ri.back());
	printf("%d\n",ans);
	return 0;
}