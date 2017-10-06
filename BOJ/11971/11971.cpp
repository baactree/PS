#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[100];
int main(){
	int pre=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=pre;j<pre+a;j++)
			s[j]=b;
		pre+=a;
	}
	int ans=0;
	pre=0;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=pre;j<pre+a;j++)
			ans=max(ans,max(0,b-s[j]));
		pre+=a;
	}
	printf("%d\n",ans);
	return 0;
}