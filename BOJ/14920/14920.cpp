#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans=1;
	while(n!=1){
		ans++;
		if(n&1)
			n=n*3+1;
		else
			n/=2;
	}
	printf("%d\n",ans);
	return 0;
}