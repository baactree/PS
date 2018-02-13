#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	bool flag=false;
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if((a&1)&&(b&1))
			flag=true;
	}
	if((n&1)&&(m&1))
		printf("%d\n",n/2+m/2+flag);
	else
		printf("%d\n",n/2+m/2);
	return 0;
}