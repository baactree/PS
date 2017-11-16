#include <bits/stdc++.h>
using namespace std;
int n;
int x[22],y[22];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	sort(x,x+n);
	sort(y,y+n);
	int r=max(x[n-1]-x[0],y[n-1]-y[0]);
	printf("%d\n",r*r);

	return 0;
}