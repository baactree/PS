#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int ans=0;
	if(a<0){
		ans=(-a)*c+d;
		a=0;
	}
	ans+=(b-a)*e;
	printf("%d\n",ans);
	return 0;
}